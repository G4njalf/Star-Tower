
#ifndef _PLAYER_H_
#define _PLAYER_H_


struct personaggio{
    int bx;
    int by;
    int id;
    personaggio *next;
};

typedef personaggio *lpersonaggio;

void PLayer:: addbullet(lpersonaggio& p, int& xb, int& yb, int& id){
	lista tmp = p;
	if(p==NULL){
		p = new personaggio;
		p->bx=xb;
		p->by=yb;
		p->id = id;
		p->next = NULL;
	}
	else{
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		tmp->next = new personaggio;
		tmp = tmp->next;
		p->bx=x;
		p->by=y;
		p->id = id;
		tmp->next = NULL;
	}
	
}

void Player:: remove_bullet(lpesonaggio& p){
	plist aux = p;
	plist prec = NULL;
	plist tmp;
	while(aux!=NULL){
		if(strcmp(aux->name,n)==0){
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






void Player:: stampa_bullets(lpersonaggio& head){
    lpersonaggio tmp = head;
	while (tmp!=NULL){
        if(/*collisione*/){
		            lpersonaggio remove_bullet();}
        else if(tmp->id == 1 ){
                /*delete vecchio proiettile*/
                /*stampa nuovo prioettile con posizione aggiornata*/
            }
       else if(tmp->id == 2 ){
                /*delete vecchio proiettile*/
                /*stampa nuovo prioettile con posizione aggiornata*/
            }
       else if(tmp->id == 3 ){
                /*delete vecchio proiettile*/
                /*stampa nuovo prioettile con posizione aggiornata*/
            }
       else if(tmp->id == 4 ){
                /*delete vecchio proiettile*/
                /*stampa nuovo prioettile con posizione aggiornata*/
            }    
        }
		tmp = tmp->next ;
	}





class Player
{
  public :
     Player(WINDOW *win, int y, int x, char c);

      void mvup();
      void mvdown();
      void mvleft();
      void mvright();
      int  getmv();
      void addbullet(lpersonaggio& p, int& xb, int& yb, int& id);
      void remove_bullet(lpersonaggio& p);
      void stampa_bullets(lpersonaggio& head);
      int getplx();
      int getply();
      void display();

      private:
         int xLoc, yLoc, xMax, yMax;
         char character;
         WINDOW * curwin;
         lpersonaggio p ;
};

Player::Player(WINDOW * win, int y, int x, char c)
{
   curwin = win;
   yLoc = y;
   xLoc = x;
   getmaxyx(curwin, yMax, xMax);
   keypad(curwin, true);
   character = c;
   p = NULL;
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
        mvup();
	wrefresh(curwin);
         break;
      case KEY_DOWN:
        mvdown();
	wrefresh(curwin);
         break;
      case KEY_LEFT:
        mvleft();
	wrefresh(curwin);
         break;
      case KEY_RIGHT:
        mvright();
	wrefresh(curwin);
         break;
      case W_MAJUSC:
        mvwaddch(curwin, yLoc, xLoc, character);
        int xb = xloc;
        int yb = yloc-1;
        int id =  1 ;
        addbullet( p,  xb,  yb,  id);
        break;
      case A_MAJUSC:
        mvwaddch(curwin, yLoc, xLoc, character);
        int xb = xloc-1;
        int yb = yloc;
        int id =  2 ;
        addbullet( p,  xb,  yb,  id);
        break;
      case S_MAJUSC:
        mvwaddch(curwin, yLoc, xLoc, character);
        int xb = xloc;
        int yb = yloc+1;
        int id =  3 ;
        addbullet( p,  xb,  yb,  id);
        break;
      case D_MAJUSC:
        mvwaddch(curwin, yLoc, xLoc, character);
        int xb = xloc+1;
        int yb = yloc;
        int id =  4 ;
        addbullet( p,  xb,  yb,  id);
        break;
      default:
      break;
 }
  return choice;

    stampa_bullets(p); 


}




void Player::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);
	wrefresh(curwin);
}
int  Player::getplx(){return (xLoc);}
int  Player::getply(){return (yLoc);}







#endif
