///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <ncurses.h>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "enemy.h"
using namespace std;



int main (int argc, char ** argv)
{
initscr();
noecho();
cbreak();
curs_set(0);
int yMax, xMax;
getmaxyx(stdscr, yMax, xMax);

WINDOW * playwin = newwin(25, 80, (yMax/2)-10, 10);
box(playwin, 0, 0);
refresh();
wrefresh(playwin);
Player * p = new Player(playwin, 1, 4, '$', 10);
shootingenemy * e= new shootingenemy(playwin, 18 , 69 , 'X',0, 18 , 0 , 3, 6);
//enemy *e= new enemy(playwin, 1, 48 , 'X');	


nodelay(playwin, TRUE);
wtimeout(playwin, 1);
int Life =3;

 /*mvwprintw(playwin, 19 ,0, "__________________________________________________");
 mvwprintw(playwin, 0 ,0, "__________________________________________________");
 mvwprintw(playwin, 1 ,0,"|");
 mvwprintw(playwin, 2 ,0,"|");
 mvwprintw(playwin, 3 ,,"|");
 mvwprintw(playwin, 4 ,25,"|");
 mvwprintw(playwin, 5 ,25,"|");
 mvwprintw(playwin, 6 ,25,"|");
 mvwprintw(playwin, 7 ,25,"|");
 mvwprintw(playwin, 8 ,25,"|");
 mvwprintw(playwin, 9 ,25,"|");
 mvwprintw(playwin, 10 ,25,"|");
 mvwprintw(playwin, 11 ,25,"|");
 mvwprintw(playwin, 12 ,25,"|");
 mvwprintw(playwin, 13 ,25,"|");
 mvwprintw(playwin, 14 ,25,"|");
 mvwprintw(playwin, 15 ,25,"|");
 mvwprintw(playwin, 16 ,25,"|");
 mvwprintw(playwin, 17 ,25,"|");
 mvwprintw(playwin, 18 ,25,"|");
 mvwprintw(playwin, 19 ,25,"|");
 //mvwprintw(playwin, 20 ,25,"|")*/



            mvwprintw(playwin,1 ,1,"__|    |______________________________________________________________________");
            mvwprintw(playwin,2 ,1,"__|    |______________________________________________________________________");
            mvwprintw(playwin,3 ,1,"__|    |______|                                                     |_________");
            mvwprintw(playwin,4 ,1,"__|    |______|                                                     |_________");
            mvwprintw(playwin,5 ,1,"__|    |______|     _________________                               |_________");
            mvwprintw(playwin,6 ,1,"__|    |______|    |_________________|                              |_________");
            mvwprintw(playwin,7 ,1,"__|                |_________________|                              |_________");
            mvwprintw(playwin,8 ,1,"__|                |_________________|                              |_________");
            mvwprintw(playwin,9 ,1,"__|________________|_________________|                              |_________");
            mvwprintw(playwin,10,1,"_____________________________________|                                        ");
            mvwprintw(playwin,11,1,"_____________________________________|                                        ");
            mvwprintw(playwin,12,1,"_____________________________________|                                ________");
            mvwprintw(playwin,13,1,"____|                                                                |________");
            mvwprintw(playwin,14,1,"____|                                                                |________");
            mvwprintw(playwin,15,1,"____|                                                                |________");
            mvwprintw(playwin,16,1,"____|                                                                |________");
            mvwprintw(playwin,17,1,"____|                                                                |________");
            mvwprintw(playwin,18,1,"____|                                                                |________");
            mvwprintw(playwin,19,1,"____________________      ___________________________________________|________");
            mvwprintw(playwin,20,1,"____________________|    |____________________________________________________");
            mvwprintw(playwin,21,1,"____________________|    |____________________________________________________");
            mvwprintw(playwin,22,1,"____________________|    |____________________________________________________");



	do {
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}
	e->leftenemsh();
	wrefresh(playwin);
	if (e->getenemx()==p->getplx() && e->getenemy()==p->getply()){Life--;}   
 	//napms(1);
	}while(p->getmv()!='x' && Life>0);

	e->undisplay();
	delete e;
	e=NULL;

	do{
	mvwprintw(playwin, 10 , 20 , "GAME OVER");

	}while(p->getmv()!='x');


endwin();
return 0;}















