#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.hpp"
#include "enemy.hpp"
using namespace std;


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

bool nemici_vivi[2]; 


int main (int argc, char ** argv)
{
initscr();
noecho();
cbreak();
curs_set(0);
int yMax, xMax;
int enemycounter = 1;
getmaxyx(stdscr, yMax, xMax);

WINDOW * playwin = newwin(25, 80, (yMax/2)-10, 10);
box(playwin, 0, 0);
refresh();
wrefresh(playwin);
Player * p = new Player(playwin, 1, 4, '$', 1, 1000, 50);
shootingenemy * e= new shootingenemy(playwin, 18 , 68 , 'X',100, 0, 18 , 0 , 3, 7);
shootingenemy * e2= new shootingenemy(playwin, 15 , 60 , 'X',100, 0, 18 , 0 , 3, 7);
artifact * h = new artifact(16, 15, '.');
key *chiave=new key(13,40,'K');             ///////



nodelay(playwin, TRUE);
wtimeout(playwin, 1);




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

    for (int i=0; i<2; i++){
    nemici_vivi[i]=true;
    };

    bool stop=false;
    
    

	do {
        wtimeout(playwin, 50);
        mvwprintw(playwin, 23, 7, "    ");
        mvwprintw(playwin, 23, 12, "    ");
        mvwprintw(playwin, 23, 7, "%d", p->currentlife());
        mvwprintw(playwin, 23, 12, "%d", e->currentlife());
        if (mvwinch(playwin, e->currentY(), e->currentX())=='.'||mvwinch(playwin, e->currentY()+1, e->currentX())=='.'){     //non legge il proiettile
        e->damage(p->currdamage());
    }
        if (mvwinch(playwin, e2->currentY(), e2->currentX())=='.'||mvwinch(playwin, e2->currentY()+1, e2->currentX())=='.'){     
        e2->damage(p->currdamage());
    }
	    p->display();
	    if(wgetch(playwin) == ERR){}
        else{
            p->getmv();
        }
        if(!e->return_kill()){
	        e->leftenemsh();
        }
        else{
            e->undisplay();
            nemici_vivi[0]=false;      /////
        }
        if(!e2->return_kill()){
	        e2->leftenemsh();
        }
        else{
            e2->undisplay();
            nemici_vivi[1]=false;      /////
        }
        //controllo dell'array che mi dice che i nemici sono vivi o morti. Se sono tutti morti, stmapa la chiave
        if (nemici_vivi[0]==false && nemici_vivi[1]==false && (stop==false)){          //////
            chiave->show(playwin);         ///////
            stop=true;
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
	if (e2->currentX()==p->currentX() && e2->currentY()==p->currentY()){
        p->damage(50);
    }
     
    wrefresh(playwin);
	}while(p->getmv()!='x' && p->currentlife());

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