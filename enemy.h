#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <ncurses.h>




class enemy
{
	public :
		enemy(WINDOW *win, int y, int x, char c );

		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
		
		void display();
		int fyloc();
		int fxloc();
		int getenemx();
		int getenemy();
		void undisplay();
		void verticalmove();
		void horizontalmove();
		void diagonal1move();
		void diagonal2move();
	

	protected :
		int xloc, yloc, xMax, yMax, j ;
		char character;
		WINDOW *curwin;
};

enemy::enemy(WINDOW *win, int y, int x , char c )
{
	curwin = win;
	yloc = y;
	xloc = x;
	getmaxyx(curwin, yMax, xMax);
	j=0;
	character = c;

}
	void enemy::mvup()
	{ mvwaddch(curwin, yloc, xloc, ' ');
	napms(100);
	yloc--;

	}
	void enemy::mvdown()
	{ mvwaddch(curwin, yloc, xloc, ' ');
	napms(100);
	yloc++;
	}



void enemy::mvright()
	{ mvwaddch(curwin, yloc, xloc, ' ');
	napms(100);
	xloc++;

	}
void enemy::mvleft()
	{ mvwaddch(curwin, yloc, xloc, ' ');
	napms(100);
	xloc--;

	}




	void enemy::display(){mvwaddch(curwin, yloc, xloc, character);  }
	int enemy::fyloc(){int loc=yloc ; return(loc);}
	int enemy::fxloc(){int loc= xloc; return(loc);}




	void enemy::verticalmove(){ 

		if(mvwinch(curwin, yloc+1, xloc)!=32){j=1;}
		if(mvwinch(curwin, yloc-1, xloc)!=32){j=0;}
		if(j==0){
		mvdown();
		display();
		}
		if(j==1){
		mvup();
		display();

		}

		}

	void enemy::horizontalmove(){ 

		if(mvwinch(curwin, yloc, xloc+1)!=32){j=1;}
		if(mvwinch(curwin, yloc, xloc-1)!=32){j=0;}
		if(j==0){
		mvright();
		display();
		}
		if(j==1){
		mvleft();
		display();

		}

		}




void enemy::diagonal1move(){ 

		if(mvwinch(curwin, yloc, xloc-1)!=32 || mvwinch(curwin, yloc-1, xloc)!=32){j=0;}
		if(mvwinch(curwin, yloc, xloc+1)!=32 || mvwinch(curwin, yloc+1, xloc)!=32){j=1;}
		mvwaddch(curwin, yloc, xloc, ' ');
		if(j==0){
		xloc++;
		napms(50);
		yloc++;
		napms(50);
		display();
		}
		if(j==1){
		xloc--;
		napms(50);
		yloc--;
		napms(50);
		display();

		}

}



void enemy::diagonal2move(){

		
		if(mvwinch(curwin, yloc, xloc+1)!=32 || mvwinch(curwin, yloc-1, xloc)!=32){j=0;}
		if(mvwinch(curwin, yloc, xloc-1)!=32 || mvwinch(curwin, yloc+1, xloc)!=32){j=1;}
		mvwaddch(curwin, yloc , xloc, ' ');
		if(j==0){
		xloc--;
		napms(50);
		yloc++;
		napms(50);
		display();
		}
		if(j==1){
		xloc++;
		napms(50);
		yloc--;
		napms(50);
		display();

		}

}






int enemy::getenemx(){return (xloc);}
int enemy::getenemy(){return (yloc);}

void enemy::undisplay(){mvwaddch(curwin, yloc, xloc , ' ' );}



struct nemico{
    int bx;
    int by;
    int id;
    nemico *next;
};

typedef nemico *lnemico;





class shootingenemy : public enemy {
	protected :
		int xmax, ymax, xmin , ymin , counter, xb, yb, identity, firerate; 
		bool flag;
		lnemico p ;
		lnemico b ; 
	public:
		shootingenemy(WINDOW *win, int y, int x, char c, int xmax, int ymax, int xmin , int ymin, int firerate ) : enemy(win,y,x,c){
			this->xmax= xmax;
			this->ymax=ymax;
			this->xmin= xmin;
			this->ymin=ymin;
			this->firerate= firerate;
			counter = firerate;
			flag = true; 
			p = NULL ;
			b = NULL ; 
		}
		void rightenemsh();
		void leftenemsh();
		void upenemsh();
		void downenemsh();
		void addbullet();
		void remove_bullet();
		void addblank();
		void remove_blank();
		void stampa_bullets();

};




void shootingenemy::rightenemsh(){

			
		if(yloc==ymin){j=0;}
		if(yloc==ymax){j=1;}
		if(j==0){
		mvdown();
		display();
		}
		if(j==1){
		mvup();
		display();
		}
		if(counter==firerate){
         	xb = xloc+11;
         	yb = yloc;
         	identity =  4 ;
         	if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95){
         		 addbullet();
          		addblank();
				}
        flag=true;
        }
		stampa_bullets();
    	if(counter!=firerate){counter++;}
    	if(counter==firerate && flag==true){
        	counter=0; 
    	}
    	flag=false;

}



void shootingenemy::upenemsh(){

			
		if(xloc==xmin){j=0;}
		if(xloc==xmax){j=1;}
		if(j==0){
		mvright();
		display();
		}
		if(j==1){
		mvleft();
		display();
		}
		if(counter==firerate){
         	xb = xloc;
         	yb = yloc-1;
         	identity =  1 ;
         	if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95){
         		 addbullet();
         		 addblank();
				 }
        flag=true;
        }
		stampa_bullets();
    	if(counter!=firerate){counter++;}
    	if(counter==firerate && flag==true){
         	counter=0; 
    	}
    	flag=false;

}



void shootingenemy::leftenemsh(){

			
		if(yloc==ymin){j=0;}
		if(yloc==ymax){j=1;}
		if(j==0){
		mvdown();
		display();
		}
		if(j==1){
		mvup();
		display();
		}
		if(counter==firerate){
         	xb = xloc-1;
         	yb = yloc;
         	identity =  2 ;
         	if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95){
         		 addbullet();
          		addblank();
				}
        	flag=true;
        }
		stampa_bullets();
    	if(counter!=firerate){counter++;}
    	if(counter==firerate && flag==true){
        	counter=0; 
    	}
    	flag=false;

}


void shootingenemy::downenemsh(){

			
		if(xloc==xmin){j=0;}
		if(xloc==xmax){j=1;}
		if(j==0){
		mvright();
		display();
		}
		if(j==1){
		mvleft();
		display();
		}
		if(counter==firerate){
         	xb = xloc;
         	yb = yloc+1;
         	identity =  3 ;
         	if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95){
          		addbullet();
          		addblank();
				}
       		 flag=true;
        }
		stampa_bullets();
    	if(counter!=firerate){counter++;}
    	if(counter==firerate && flag==true){
         	counter=0; 
    	}
    	flag=false;

}





void shootingenemy:: addbullet(){
	lnemico tmp = p;
	if(p==NULL){
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
		p = new nemico;
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
		tmp->next = new nemico;
		tmp = tmp->next;
		tmp->bx=xb;
		tmp->by=yb;
		tmp->id = identity;
		tmp->next = NULL;
    }
	}
	
}

void shootingenemy:: remove_bullet(){
	lnemico aux = p;
	lnemico prec = NULL;
	lnemico tmp;
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






void shootingenemy:: stampa_bullets(){
    lnemico tmp = p;
	while (tmp!=NULL){    
        if(tmp->id == 1 ){
                mvwaddch(curwin, tmp->by, tmp->bx, '*');
                tmp->by--;
            }
       else if(tmp->id == 2 ){
                mvwaddch(curwin, tmp->by, tmp->bx, '*');
                tmp->bx--;
            }
       else if(tmp->id == 3 ){
                mvwaddch(curwin, tmp->by, tmp->bx, '*');
                tmp->by++;
            }
       else if(tmp->id == 4 ){
                mvwaddch(curwin, tmp->by, tmp->bx, '*');
                tmp->bx++;
            }    
       tmp = tmp->next ;
        }
  remove_bullet();
  tmp = b;
while (tmp!=NULL){    
        if(tmp->id == 1 ){
          if(tmp->by!=yloc || tmp->bx!=xloc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
          }
                tmp->by--;
            }
       else if(tmp->id == 2 ){
        if(tmp->by!=yloc || tmp->bx!=xloc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
        }
                tmp->bx--;
            }
       else if(tmp->id == 3 ){
        if(tmp->by!=yloc || tmp->bx!=xloc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
        }
                tmp->by++;
            }
       else if(tmp->id == 4 ){
        if(tmp->by!=yloc || tmp->bx!=xloc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
        }
                tmp->bx++;
            }    
       tmp = tmp->next ;
        }
		remove_blank();
	}



void shootingenemy:: remove_blank(){
	lnemico aux = b;
	lnemico prec = NULL;
	lnemico tmp;
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

void shootingenemy:: addblank(){
	lnemico tmp = b;
	if(b==NULL){
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
		b = new nemico;
		b->bx=xloc;
		b->by=yloc;
		b->id = identity;
		b->next = NULL;
    }
	}
	else{
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
		tmp->next = new nemico;
		tmp = tmp->next;
		tmp->bx=xloc;
		tmp->by=yloc;
		tmp->id = identity;
		tmp->next = NULL;
    }
	}
	
}

#endif












