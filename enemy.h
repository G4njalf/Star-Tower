#ifndef _ENEMY_H_
#define _ENEMY_H_
class enemy
{
	public :
		enemy(WINDOW *win, int y, int x , int firerate ,  char c );

		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
		void move();
		void display();
		int fyloc();
		int getenemx();
		int getenemy();
		void undisplay();
		void shoot();

	private :
		int xloc, yloc, xMax, yMax;
		char character;
		WINDOW *curwin;
		//int contatore  ;
		//int contatore_2 ; 
		int yloc_bullet [50];
		int xloc_bullet [50];
		bool maxbullets ; 
		//int j ; 
		int k;
		int kk;
		int timer; 
		int firerate;
		
};

enemy::enemy(WINDOW *win, int y, int x , int firerate, char c)
{
	curwin = win;
	yloc = y;
	xloc = x;
	getmaxyx(curwin, yMax, xMax);
	contatore=0;
	contatore_2 = 0 ;
	maxbullets= false;
	character = c;
	xloc_bullet[0]= xloc+1;
	yloc_bullet[0]= yloc;
	j = 0; 
	k=1;
	kk=0;
	this->firerate= firerate;
	timer=0;
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
	void enemy::display(){mvwaddch(curwin, yloc, xloc, character);  }
	int enemy::fyloc(){int loc=yloc ; return(loc);}
	



void enemy::move(){ 
		
		if(fyloc()==1){j=0;}
		if(fyloc()==yMax-2){j=1;}
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








int enemy::getenemx(){return (xloc);}
int enemy::getenemy(){return (yloc);}

void enemy::undisplay(){mvwaddch(curwin, yloc, xloc , ' ' );}



















#endif


