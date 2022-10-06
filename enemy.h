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
		//void declife();

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
	//vita = life;

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




//void enemy::declife(int& dannoricevuto){vita=vita-dannoricevuto;}
//bool enemy::checklife(){if(vita>0){return(true);} else{return(false);} }




int enemy::getenemx(){return (xloc);}
int enemy::getenemy(){return (yloc);}

void enemy::undisplay(){mvwaddch(curwin, yloc, xloc , ' ' );}





class shootingenemy : public enemy {
	protected :
		int xmax, ymax, xmin , ymin ;
		int yloc_bullet [50];
		int xloc_bullet [50];
		bool maxbullets ; 
		int k;
		int kk;
		int timer; 
		int firerate;
	public:
		shootingenemy(WINDOW *win, int y, int x, char c, int xmax, int ymax, int xmin , int ymin, int firerate ) : enemy(win,y,x,c){
				this->xmax= xmax;
			this->ymax=ymax;
			this->xmin= xmin;
			this->ymin=ymin;
			maxbullets= false;
			xloc_bullet[0]= xloc+1;
			yloc_bullet[0]= yloc; 
			k=1;
			kk=0;
			this->firerate= firerate;
			timer=0;
		}
		void rightenemsh();
	//	void leftenemsh(int ymin, int ymax);
	//	void upenemsh(int xmin, int xmax);
	//	void downenemsh(int xmin, int xmax);


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
		if (timer==firerate){
			if(maxbullets==false){
				xloc_bullet[kk]= xloc+1;
				yloc_bullet[kk]= yloc;}}
		if(maxbullets==false){k++;}
		kk++;
		timer++;
		for(int i = 0 ; i<k ; i++){
			if(yloc_bullet[i]!=0){
				if(mvwinch(curwin, yloc_bullet[i], xloc_bullet[i])!=124){
					mvwaddch(curwin , yloc_bullet[i], xloc_bullet[i], ' ' );}
				xloc_bullet[i]++;
				if(mvwinch(curwin, yloc_bullet[i], xloc_bullet[i])!=124){
					mvwaddch(curwin , yloc_bullet[i], xloc_bullet[i], '*' );}}
			if(mvwinch(curwin, yloc_bullet[i], xloc_bullet[i])==124)
				{maxbullets=true; 
				yloc_bullet[i]=yloc; 
				xloc_bullet[i]=xloc+1; }
			if(maxbullets==true && kk==k-1){kk=0;}
		
			if(timer==firerate+1){timer=0;}
		}
}










#endif












