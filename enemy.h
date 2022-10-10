#ifndef _ENEMY_H_
#define _ENEMY_H_
class enemy
{
	public :
		enemy(WINDOW *win, int y, int x, char c );

		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
		void move(int& j);
		void display();
		int fyloc();
		int getenemx();
		int getenemy();
		void undisplay();

	private :
		int xloc, yloc, xMax, yMax;
		char character;
		WINDOW *curwin;
};

enemy::enemy(WINDOW *win, int y, int x , char c)
{
	curwin = win;
	yloc = y;
	xloc = x;
	getmaxyx(curwin, yMax, xMax);

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
	void enemy::display(){mvwaddch(curwin, yloc, xloc, character);  }
	int enemy::fyloc(){int loc=yloc ; return(loc);}
	void enemy::move(int& j){ 

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

		}


int enemy::getenemx(){return (xloc);}
int enemy::getenemy(){return (yloc);}

void enemy::undisplay(){mvwaddch(curwin, yloc, xloc , ' ' );}

#endif












