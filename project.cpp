///////////////////////////////////////////////////////
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

WINDOW * playwin = newwin(20, 50, (yMax/2)-10, 10);
box(playwin, 0, 0);
refresh();
wrefresh(playwin);
Player * p = new Player(playwin, 1, 1, '$');
enemy * e= new enemy(playwin, 1 , 1 , 7 , 'X');



//int j= 0;
nodelay(playwin, TRUE);
wtimeout(playwin, 1);
int Life =3;


// mvwprintw(playwin, 0 ,25, "|");
 mvwprintw(playwin, 1 ,25,"|");
 mvwprintw(playwin, 2 ,25,"|");
 mvwprintw(playwin, 3 ,25,"|");
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
mvwprintw(playwin, 20 ,25,"|");







	do {
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}
	e->move();
	wrefresh(playwin);
	if (e->getenemx()==p->getplx() && e->getenemy()==p->getplx()){Life--;}   //per il momento il player uccide il nemico
 	napms(1);
	}while(p->getmv()!='x' && Life>0);

	e->undisplay();
	delete e;
	e=NULL;

	do{
	mvwprintw(playwin, 10 , 20 , "GAME OVER");

	}while(p->getmv()!='x');


endwin();
return 0;}















