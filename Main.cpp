#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.hpp"
#include "enemy.hpp"

void displaygameover(WINDOW * win){       //scrive la scritta gameover una lettera alla volta
//    wattron (win, COLOR_PAIR(3));
    char A[8] = {'G','A', 'M','E','O','V','E','R'};
    int x = 20;
    for (int i=0; i<8; i++){
        mvwaddch(win, 8, x, A[i]);                          //scrive ogni lettera dell'array, viene incrementata la x
        wrefresh(win);                                      // così vengono scritte di fianco
        napms(100);
        x++;
    }
 //   wattroff (win, COLOR_PAIR(3));
    wrefresh(win);
}

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
Player * p = new Player(playwin, 1, 4, '$', 1, 1000, 25);
shootingenemy * e = new shootingenemy(playwin, 18 , 68 , 'X',100, 0, 18 , 0 , 3, 7);
artifact * h = new artifact(16, 15, '.');

nodelay(playwin, TRUE);


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

    h->drawhpup(playwin);
    mvwprintw(playwin, 23, 1, "VITA: ");

	while (p->currentlife()){
        mvwprintw(playwin, 23, 7, "    ");
        mvwprintw(playwin, 23, 12, "    ");
        mvwprintw(playwin, 23, 7, "%d", p->currentlife());
        mvwprintw(playwin, 23, 12, "%d", e->currentlife());
        wtimeout(playwin, 100);
        p->display();
        p->getmv();
        if (mvwinch(playwin, e->currentY(), e->currentX())=='.'||mvwinch(playwin, e->currentY()+1, e->currentX())=='.'){     //controlla la posizione del nemico anche
            e->damage(p->currdamage());
        }
        if(!e->return_kill()) {
            e->leftenemsh();
        }
    if(!h->return_remove()){
        p->healtup(h);
    }
    if (mvwinch(playwin, p->currentY(), p->currentX())=='*'){
        p->damage(e->bulletdamage());
    }
	if (e->currentX()==p->currentX() && e->currentY()==p->currentY()){
        p->damage(50);
    }

    wrefresh(playwin);
	}

	e->undisplay();
	delete e;
    delete h;
    delete p;
	e=NULL;

    werase(playwin);
    displaygameover(playwin);

    mvprintw(20, 1, "Premere un tasto casuale per uscire");
    getch();


endwin();
return 0;
}
