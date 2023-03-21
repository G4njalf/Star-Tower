
#include "enemyDef.hpp"




enemy::enemy(WINDOW *win, int y, int x , char c , int h)
{
	curwin = win;
	yloc = y;
	xloc = x;
	getmaxyx(curwin, yMax, xMax);
	j=0;
	character = c;
    healt = h;
}
	void enemy::mvup()
	{ mvwaddch(curwin, yloc, xloc, ' ');
	yloc--;

	}
	void enemy::mvdown()
	{ mvwaddch(curwin, yloc, xloc, ' ');
	yloc++;
	}



void enemy::mvright()
	{ mvwaddch(curwin, yloc, xloc, ' ');
	xloc++;

	}
void enemy::mvleft()
	{ mvwaddch(curwin, yloc, xloc, ' ');
	xloc--;

	}




	void enemy::display(){mvwaddch(curwin, yloc, xloc, character);  }
	int enemy::fyloc(){int loc=yloc ; return(loc);}
	int enemy::fxloc(){int loc= xloc; return(loc);}

    void enemy :: damage (int d){
        healt = healt - d;
    if (healt<=0){
        killed = true;
            undisplay();
        }
    }

    int enemy :: currentlife(){
        return healt;
    }

    bool enemy :: return_kill(){
        return killed;
    }

	void enemy:: set_killed_status(){
		if (healt<=0) {
			killed=true;
			undisplay();
		}	
		else killed=false;
	}



	void enemy::verticalmove(){ 
	

		if(mvwinch(curwin, yloc+1, xloc)=='_'||mvwinch(curwin, yloc+1, xloc)=='|'){j=1;}
		if(mvwinch(curwin, yloc-1, xloc)=='_'||mvwinch(curwin, yloc-1, xloc)=='|'){j=0;}
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

		if(mvwinch(curwin, yloc, xloc+1)=='_'||mvwinch(curwin, yloc, xloc+1)=='|'){j=1;}
		if(mvwinch(curwin, yloc, xloc-1)=='_'||mvwinch(curwin, yloc, xloc-1)=='|'){j=0;}
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











int shootingenemy ::bulletdamage(){
    return bulldamage;
}

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
         	xb = xloc+1;
         	yb = yloc;
         	identity =  4 ;
         	if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95 && mvwinch(curwin, yb , xb)!='X'){
         		 addbullet();
          		addblank();
				}
        flag=true;
        }
		stampa_bullets();
    	if(counter!=firerate){counter++;}
    	if(counter==firerate && flag){
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
         	if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95 && mvwinch(curwin, yb , xb)!='X'){
         		 addbullet();
         		 addblank();
				 }
        flag=true;
        }
		stampa_bullets();
    	if(counter!=firerate){counter++;}
    	if(counter==firerate && flag){
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
         	if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95 && mvwinch(curwin, yb , xb)!='X'){
         		 addbullet();
          		addblank();
				}
        	flag=true;
        }
		stampa_bullets();
    	if(counter!=firerate){counter++;}
    	if(counter==firerate && flag){
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
         	if(mvwinch(curwin, yb , xb)!=124 && mvwinch(curwin, yb , xb)!=95 && mvwinch(curwin, yb , xb)!='X'){
          		addbullet();
          		addblank();
				}
       		 flag=true;
        }
		stampa_bullets();
    	if(counter!=firerate){counter++;}
    	if(counter==firerate && flag){
         	counter=0; 
    	}
    	flag=false;

}





void shootingenemy:: addbullet(){
	lnemico tmp = p;
	if(p==NULL){
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95 || mvwinch(curwin, yb , xb)!='X'){
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
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95 || mvwinch(curwin, yb , xb)!='X'){
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
		if(mvwinch(curwin, bby , bbx)==124 ||mvwinch(curwin, bby , bbx)==95 || mvwinch(curwin, bby , bbx)=='X'){
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
		if(mvwinch(curwin, bby , bbx)==124 ||mvwinch(curwin, bby , bbx)==95 || mvwinch(curwin, bby , bbx)=='X'){
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
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95 || mvwinch(curwin, yb , xb)!='X' ||mvwinch(curwin, yb , xb)!='$'){
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
    if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95 || mvwinch(curwin, yb , xb)!='X'||mvwinch(curwin, yb , xb)!='$'){
		tmp->next = new nemico;
		tmp = tmp->next;
		tmp->bx=xloc;
		tmp->by=yloc;
		tmp->id = identity;
		tmp->next = NULL;
    }
	}
	
}



void shootingenemy:: undisplaybullets(){
lnemico tmp = p ; 
while(tmp != NULL){
 	   if(tmp->id == 1 ){
                mvwaddch(curwin, tmp->by+1, tmp->bx, ' ');
            }
       else if(tmp->id == 2 ){
                mvwaddch(curwin, tmp->by, tmp->bx+1, ' ');
            }
       else if(tmp->id == 3 ){
                mvwaddch(curwin, tmp->by-1, tmp->bx, ' ');
            }
       else if(tmp->id == 4 ){
                mvwaddch(curwin, tmp->by, tmp->bx-1, ' ');
            }    
       tmp = tmp->next ;
        }

mvwaddch(curwin, yloc, xloc,' ' ); 

}














