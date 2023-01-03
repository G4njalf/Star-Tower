////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "/mnt/c/Users/Lenovo/Desktop/UNIVERSITA/PROGRAMMAZIONE/Progetto/player/playerNEW.hpp"
#include "enemyDef.hpp"
using namespace std;



void entity (int argc, char ** argv,WINDOW *playwin, coordinates pl, coordinates en, int layout)
{
//initscr();
//noecho();
//cbreak();
//curs_set(0);
int yMax, xMax;
getmaxyx(stdscr, yMax, xMax);

//WINDOW * playwin = newwin(25, 80, (yMax/2)-10, 10);
//box(playwin, 0, 0);
refresh();
wrefresh(playwin);
Player * p = new Player(playwin,pl.rows,pl.columns,'&',1);
shootingenemy * e= new shootingenemy(playwin,en.rows,en.columns,'$',0,18,0,3,7);



nodelay(playwin, TRUE);
wtimeout(playwin, 1);
int Life =3;
int life2 =2; 
int x, y;

	do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}
    if(mvwinch(playwin,e->getenemy(), e->getenemx() )=='.'){life2--;}
    if (e->getenemx()==p->getplx() && e->getenemy()==p->getply()){Life--;} 
    if(life2>0){
	 e->leftenemsh();}
    else if(life2==0){
        e->undisplaybullets(); 
        delete e; 
        e=NULL; 
        life2--; 
    }
	
    
    napms(100);

	}while(p->getmv()!='x' && Life>0 && life2>0);

	/*e->undisplay();
    
	delete e;
	e=NULL;*/

	do{
	mvwprintw(playwin, 10 , 20 , "GAME OVER");

	}while(p->getmv()!='x');


//endwin();

}















