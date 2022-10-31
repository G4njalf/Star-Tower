#ifndef _PLAYER_H_
#define _PLAYER_H_


struct personaggio{
    int bx;
    int by;
    int id;
    personaggio *next;
};

typedef personaggio *lpersonaggio;








class Player
{
  public :
     Player(WINDOW *win, int y, int x, char c, int firerate);

      void mvup();
      void mvdown();
      void mvleft();
      void mvright();
      int  getmv();
      void addbullet();
      void remove_bullet();
      void addblank();
      void remove_blank();
      void stampa_bullets();
      int getplx();
      int getply();
      void display();

      protected:
         int xLoc, yLoc, xMax, yMax, xb, yb, identity, counter, firerate;
         bool flag;
         char character;
         WINDOW * curwin;
         lpersonaggio  p ;
         lpersonaggio  b ; 

};

Player::Player(WINDOW * win, int y, int x, char c, int firerate)
{
   curwin = win;
   yLoc = y;
   xLoc = x;
   getmaxyx(curwin, yMax, xMax);
   keypad(curwin, true);
   character = c;
   p = NULL;
   this->firerate = firerate;
   counter= firerate;
   flag = true;  

}








void Player::mvup()
{
   mvwaddch(curwin, yLoc, xLoc, ' ');
   yLoc--;
   if(yLoc<1)
   yLoc = 1;
	mvwaddch(curwin, yLoc, xLoc, character);

}
void Player::mvdown()
{
   mvwaddch(curwin, yLoc, xLoc, ' ');
   yLoc++;
   if(yLoc > yMax-2)
   yLoc = yMax-2;
	mvwaddch(curwin, yLoc, xLoc, character);

}
void Player::mvleft()
{
   mvwaddch(curwin, yLoc, xLoc, ' ');
   xLoc--;
   if(xLoc < 1 )
    xLoc = 1;
	mvwaddch(curwin, yLoc, xLoc, character);
}
void Player::mvright()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
    xLoc = xMax-2;
	mvwaddch(curwin, yLoc, xLoc, character);
}


int Player::getmv()
	{
  int choice= wgetch(curwin);
  switch(choice)
    {
      case KEY_UP:
     if(mvwinch(curwin, yLoc-1 , xLoc)!=124 && mvwinch(curwin, yLoc-1 , xLoc)!=95){
        mvup();}
	wrefresh(curwin);
         break;
      case KEY_DOWN:
      if(mvwinch(curwin, yLoc+1 , xLoc)!=124 && mvwinch(curwin, yLoc+1 , xLoc)!=95){
        mvdown();}
	wrefresh(curwin);
         break;
      case KEY_LEFT:
      if(mvwinch(curwin, yLoc , xLoc-1)!=124 && mvwinch(curwin, yLoc , xLoc-1)!=95){
        mvleft();}
	wrefresh(curwin);
         break;
      case KEY_RIGHT:
      if(mvwinch(curwin, yLoc , xLoc+1)!=124 && mvwinch(curwin, yLoc , xLoc+1)!=95){
        mvright();}
	wrefresh(curwin);
         break;
      case 119:
        mvwaddch(curwin, yLoc, xLoc, character);
        if(counter==firerate){
         xb = xLoc;
         yb = yLoc-1;
         identity =  1 ;
         if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95){
          addbullet();
          addblank();}
        flag=true;
        }
        break;
      case 97:
        mvwaddch(curwin, yLoc, xLoc, character);
        if(counter==firerate){
         xb = xLoc-1;
         yb = yLoc;
         identity =  2 ;
         if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95){
          addbullet();
          addblank();}
        flag=true;
        }
        break;
      case 115:
        mvwaddch(curwin, yLoc, xLoc, character);
        if(counter==firerate){
         xb = xLoc;
         yb = yLoc+1;
         identity =  3 ;
         if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95){
          addbullet();
          addblank();}
        flag=true;
        }
        break;
      case 100:
        mvwaddch(curwin, yLoc, xLoc, character);
        if(counter==firerate){
         xb = xLoc+1;
         yb = yLoc;
         identity =  4 ;
         if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95){
          addbullet();
          addblank();}
        flag=true;
        }
        break;
      default:
      break;
 }
    stampa_bullets();
    if(counter!=firerate){counter++;}
    if(counter==firerate && flag==true){
      counter=0; 
    }
    flag=false;

     
    return choice;


}




void Player::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);
	wrefresh(curwin);
}
int  Player::getplx(){return (xLoc);}
int  Player::getply(){return (yLoc);}


void Player:: addbullet(){
	lpersonaggio tmp = p;
	if(p==NULL){
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
		p = new personaggio;
		p->bx=xb;
		p->by=yb;
		p->id = identity;
		p->next = NULL;
    }
	}
	else{
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
		tmp->next = new personaggio;
		tmp = tmp->next;
		tmp->bx=xb;
		tmp->by=yb;
		tmp->id = identity;
		tmp->next = NULL;
    }
	}
	
}

void Player:: remove_bullet(){
	lpersonaggio aux = p;
	lpersonaggio prec = NULL;
	lpersonaggio tmp;
  int bbx, bby;
	while(aux!=NULL){
    bby = aux->by;
    bbx = aux->bx;
		if(mvwinch(curwin, bby , bbx)==124 ||mvwinch(curwin, bby , bbx)==95){
			tmp = aux;
			if(prec == NULL){
				p = p->next ;
			}else {
				prec->next = aux->next ;
			}
			aux = aux->next;
			delete (tmp);
		}
		else{
			prec = aux ;
			aux = aux->next ;
		}
	}
	
}






void Player:: stampa_bullets(){
    lpersonaggio tmp = p;
	while (tmp!=NULL){    
        if(tmp->id == 1 ){
                mvwaddch(curwin, tmp->by, tmp->bx, '.');
                tmp->by--;
            }
       else if(tmp->id == 2 ){
                mvwaddch(curwin, tmp->by, tmp->bx, '.');
                tmp->bx--;
            }
       else if(tmp->id == 3 ){
                mvwaddch(curwin, tmp->by, tmp->bx, '.');
                tmp->by++;
            }
       else if(tmp->id == 4 ){
                mvwaddch(curwin, tmp->by, tmp->bx, '.');
                tmp->bx++;
            }    
       tmp = tmp->next ;
        }
  remove_bullet();
  tmp = b;
while (tmp!=NULL){    
        if(tmp->id == 1 ){
          if(tmp->by!=yLoc || tmp->bx!=xLoc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
          }
                tmp->by--;
            }
       else if(tmp->id == 2 ){
        if(tmp->by!=yLoc || tmp->bx!=xLoc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
        }
                tmp->bx--;
            }
       else if(tmp->id == 3 ){
        if(tmp->by!=yLoc || tmp->bx!=xLoc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
        }
                tmp->by++;
            }
       else if(tmp->id == 4 ){
        if(tmp->by!=yLoc || tmp->bx!=xLoc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
        }
                tmp->bx++;
            }    
       tmp = tmp->next ;
        }
		remove_blank();
	}



void Player:: remove_blank(){
	lpersonaggio aux = b;
	lpersonaggio prec = NULL;
	lpersonaggio tmp;
  int bbx, bby;
	while(aux!=NULL){
    bby = aux->by;
    bbx = aux->bx;
		if(mvwinch(curwin, bby , bbx)==124 ||mvwinch(curwin, bby , bbx)==95){
			tmp = aux;
			if(prec == NULL){
				b = b->next ;
			}else {
				prec->next = aux->next ;
			}
			aux = aux->next;
			delete (tmp);
		}
		else{
			prec = aux ;
			aux = aux->next ;
		}
	}
	
}

void Player:: addblank(){
	lpersonaggio tmp = b;
	if(b==NULL){
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
		b = new personaggio;
		b->bx=xLoc;
		b->by=yLoc;
		b->id = identity;
		b->next = NULL;
    }
	}
	else{
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
		tmp->next = new personaggio;
		tmp = tmp->next;
		tmp->bx=xLoc;
		tmp->by=yLoc;
		tmp->id = identity;
		tmp->next = NULL;
    }
	}
	
}


#endif
