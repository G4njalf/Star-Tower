#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <ncurses.h>
#include "artifacts.hpp"

bool chmap = false; // 1 se devi cambiare mappa

struct personaggio{
    int bx;
    int by;
    int id;
    personaggio *next;
};

typedef personaggio *lpersonaggio;

int changemap(int layout, int rows, int columns) // 0 == vai indietro // 1 == vai avanti a SX // 2 == vai avanti a DX
{
    //layout 0
    if (layout == 0 && rows >= 20)
    {
        return 1; 
    }
    else if (layout == 0 && columns >= 77)
    {
        return 2;
    }
    else if (layout == 0 && rows <= 1)
    {
        return 0;
    }
    //layout 1
    else if (layout == 1 && rows <= 1)
    {
        return 0;
    }
    else if (layout == 1 && columns<= 2)
    {
        return 1;
    }
    else if (layout == 1 && rows >= 21)
    {
        return 2;
    }
    //layout 2
    else if (layout == 2 && rows <= 1)
    {
        return 0;
    }
    else if (layout == 2 && columns <= 2)
    {
        return 1;
    }
    else if (layout == 2 && columns >= 77)
    {
        return 2;
    }
    //layout 3
    else if (layout == 3 && columns >= 77)
    {
        return 0;
    }
    else if (layout == 3 && columns <= 2)
    {
        return 1;
    }
    else if (layout == 3 && rows >= 21)
    {
        return 2;
    }
    
    return 100;
    chmap = false;
    
}


class Player
{
  public :
     Player(WINDOW *win, int y, int x, char c, int firerate, int h, int bd);

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
      void mvup2();
      void mvdown2();
      void mvleft2();
      void mvright2();
      void healtup(artifact * h, int score);
      void damage(int dm);
      int currentlife();
      int currentY();
      int currentX();
      int currdamage();
      void print_jump();

      protected:
      int xLoc, yLoc, xMax, yMax, xb, yb, identity, identity2, counter, counter2, firerate, mvdelay;
      bool flag, flag2;
      int healt, bulldamage;
      char character;
      WINDOW * curwin;
      lpersonaggio  p ;
      lpersonaggio  b ;
};

Player::Player(WINDOW * win, int y, int x, char c, int firerate, int h, int bd)
{
   curwin = win;
   yLoc = y;
   xLoc = x;
   getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
    p = NULL;
    mvdelay = 8;
    this->firerate = firerate;
    counter= firerate;
    counter2 = mvdelay;
    flag = true;
    healt = h;
    bulldamage = bd;

}

void Player :: healtup (artifact * h, int score){            //funzioni usate per l'interazione col personaggio
    if (h->collected(yLoc, xLoc)){
        if (score>=100){
            healt = healt + 50;
        }
        else{
            h->canttake();
        }
    }
}
void Player :: damage (int d){
    healt = healt - d;
}

int Player :: currentlife() {
    return healt;
}

int Player :: currentY(){
    return yLoc;
}

int Player ::currentX() {
    return xLoc;
}

int Player ::currdamage() {
    return bulldamage;
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

void Player :: mvup2() {        //salto con lo shift
    if (!flag2) {
        if (mvwinch(curwin, yLoc-2, xLoc) == 32 && mvwinch(curwin, yLoc-1, xLoc) !='X') {
            mvwaddch(curwin, yLoc, xLoc, ' ');
            yLoc = yLoc-2;
            mvwaddch(curwin, yLoc, xLoc, character);
            wrefresh(curwin);
        }
    }
}

void Player:: mvdown2() {
    if (!flag2) {
        if (mvwinch(curwin, yLoc+2, xLoc) == 32 && mvwinch(curwin, yLoc+1, xLoc) !='X') {
            mvwaddch(curwin, yLoc, xLoc, ' ');
            yLoc = yLoc+2;
            mvwaddch(curwin, yLoc, xLoc, character);
            wrefresh(curwin);
        }
    }
}

void Player:: mvright2() {
    if(!flag2){
        if (mvwinch(curwin, yLoc, xLoc+2) == 32 && mvwinch(curwin, yLoc, xLoc+1) !='X') {
            mvwaddch(curwin, yLoc, xLoc, ' ');
            xLoc=xLoc+2;
            mvwaddch(curwin, yLoc, xLoc, character);
            wrefresh(curwin);
        }
    }
}

void Player:: mvleft2() {
    if (!flag2) {
        if (mvwinch(curwin, yLoc, xLoc) == 32 && mvwinch(curwin, yLoc, xLoc-1) !='X') {
            mvwaddch(curwin, yLoc, xLoc, ' ');
            xLoc=xLoc-2;
            mvwaddch(curwin, yLoc, xLoc, character);
            wrefresh(curwin);
        }
    }
}



int Player::getmv()
	{
  int choice= wgetch(curwin);
  switch(choice)
    {
      case 'w':
     if(mvwinch(curwin, yLoc-1 , xLoc)!=124 && mvwinch(curwin, yLoc-1 , xLoc)!=95 && mvwinch(curwin, yLoc-1, xLoc)!='X'){
        mvup();}
	wrefresh(curwin);
         break;
      case 's':
      if(mvwinch(curwin, yLoc+1 , xLoc)!=124 && mvwinch(curwin, yLoc+1 , xLoc)!=95 && mvwinch(curwin, yLoc+1, xLoc)!='X'){
        mvdown();}
	wrefresh(curwin);
         break;
      case 'a':
      if(mvwinch(curwin, yLoc , xLoc-1)!=124 && mvwinch(curwin, yLoc , xLoc-1)!=95 && mvwinch(curwin, yLoc, xLoc-1)!='X'){
        mvleft();}
	wrefresh(curwin);
         break;
      case 'd':
      if(mvwinch(curwin, yLoc , xLoc+1)!=124 && mvwinch(curwin, yLoc , xLoc+1)!=95 && mvwinch(curwin, yLoc, xLoc+1)!='X'){
        mvright();}
	wrefresh(curwin);
         break;
      case KEY_UP:
        mvwaddch(curwin, yLoc, xLoc, character);
        if(counter==firerate){
         xb = xLoc;
         yb = yLoc-1;
         identity =  1 ;
         if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95 && mvwinch(curwin, yb, xb)!='X'){
          addbullet();
          addblank();}
        flag=true;
        }
        break;
      case KEY_LEFT:
        mvwaddch(curwin, yLoc, xLoc, character);
        if(counter==firerate){
         xb = xLoc-1;
         yb = yLoc;
         identity =  2 ;
         if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95 && mvwinch(curwin, yb, xb)!='X'){
          addbullet();
          addblank();}
        flag=true;
        }
        break;
      case KEY_DOWN:
        mvwaddch(curwin, yLoc, xLoc, character);
        if(counter==firerate){
         xb = xLoc;
         yb = yLoc+1;
         identity =  3 ;
         if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95 && mvwinch(curwin, yb, xb)!='X'){
          addbullet();
          addblank();}
        flag=true;
        }
        break;
      case KEY_RIGHT:
        mvwaddch(curwin, yLoc, xLoc, character);
        if(counter==firerate){
         xb = xLoc+1;
         yb = yLoc;
         identity =  4 ;
         if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95 && mvwinch(curwin, yb, xb)!='X'){
          addbullet();
          addblank();}
        flag=true;
        }
        break;
        case 'W':
            for (int j=3; j>0; j--){
                if(yLoc==j){
                    flag2=true;
                }
            }
            if(counter2==mvdelay){
                identity2 = 1;
                print_jump();
                flag2=true;
            }
            break;
        case 'S':
            for (int j=20; j<24; j++){
                if(yLoc==j){
                    flag2=true;
                }
            }
            if(counter2==mvdelay){
                identity2 = 2;
                print_jump();
                flag2=true;
            }
            break;
        case 'D':
            for (int j=76; j<80; j++){
                if(xLoc==j){
                    flag2=true;
                }
            }
            if(counter2==mvdelay){
                identity2 = 3;
                print_jump();
                flag2=true;
            }
            break;
        case 'A':
            for (int j=3 ; j>0; j--){
                if(xLoc==j){
                    flag2=true;
                }
            }
            if(counter2==mvdelay){
                identity2 = 4;
                print_jump();
                flag2=true;
            }
            break;
      default:
      break;
 }
    stampa_bullets();
    if(counter!=firerate){counter++;}
    if(counter==firerate && flag){
      counter=0; 
    }
    flag=false;
    if(counter2 != mvdelay) {       //contatori per l'attesa per il prossimo scatto
        counter2++;
    }
    if (counter2==mvdelay && flag2){
        counter2=0;
    }
        flag2=false;


        return choice;
}

void Player ::print_jump() {
    if(identity2==1){
        mvup2();
    }
    if(identity2==2){
        mvdown2();
    }
    if(identity2==3){
        mvright2();
    }
    if(identity2==4){
        mvleft2();
    }
    flag2=true;
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
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95||mvwinch(curwin, yb, xb)!='X'){
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
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95||mvwinch(curwin, yb, xb)!='X'){
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
		if(mvwinch(curwin, bby , bbx)==124 ||mvwinch(curwin, bby , bbx)==95|| mvwinch (curwin, bby, bbx)=='X'){
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
		if(mvwinch(curwin, bby , bbx)==124 ||mvwinch(curwin, bby , bbx)==95||mvwinch(curwin, bby, bbx)=='X'){
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
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95||mvwinch(curwin, yb, xb)!='X'){
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
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95||mvwinch(curwin, yb, xb)!='X'){
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