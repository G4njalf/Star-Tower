#include <iostream>
#include "Personaggio.hpp"

bool gameover = false;
bool bf = true;

void inizio(){
    initscr();
    noecho();
    raw();
    cbreak();
}
void colori(){
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
}

/*void scrittagameover(personaggio prot, WINDOW * win){       //scrive la scritta gameover una lettera alla volta
    wattron (win, COLOR_PAIR(3));
    char A[8] = {'G','A', 'M','E','O','V','E','R'};
    int x = 20;
    for (int i=0; i<8; i++){
        mvwaddch(win, 9, x, A[i]);                          //scrive ogni lettera dell'array, viene incrementata la x
        wrefresh(win);                                      // così vengono scritte di fianco
        napms(100);
        x++;
    }
    wattroff (win, COLOR_PAIR(3));
    wrefresh(win);
}

void sparare(personaggio prot, WINDOW* win, int movimento){             //questa funzione aggiunge un bug, dopo che si spara
    if(movimento==KEY_UP){                                              //la posizione del personaggio torna dov'era prima della funzione
        sparo *proiettile = new sparo(prot.cy(), prot.cx(), '.', win);
        while(!proiettile->return_ostacolo()) {
            int movimento2 = wgetch(win);
            wtimeout(win, 50);

            prot.cancella();
            proiettile->cancella();
            prot.muovi(movimento2);
            proiettile->sparosu();

            proiettile->disegna();
            prot.disegna();
        }
        prot.cancella();
        proiettile->cancella2();
        delete proiettile;
    }
    else if(movimento==KEY_DOWN){
        sparo *proiettile = new sparo(prot.cy(), prot.cx(), '.', win);
        while(!proiettile->return_ostacolo()) {
            int movimento2 = wgetch(win);
            wtimeout(win, 50);

            prot.cancella();
            proiettile->cancella();
            prot.muovi(movimento2);
            proiettile->sparogiu();

            proiettile->disegna();
            prot.disegna();
        }
        prot.cancella();
        proiettile->cancella2();
        delete proiettile;
    }
    else if(movimento==KEY_RIGHT){
        sparo *proiettile = new sparo(prot.cy(), prot.cx(), '.', win);
        while(!proiettile->return_ostacolo()) {
            int movimento2 = wgetch(win);
            wtimeout(win, 30);

            prot.cancella();
            proiettile->cancella();
            prot.muovi(movimento2);
            proiettile->sparodx();

            prot.disegna();
            proiettile->disegna();
        }
        proiettile->cancella2();
        delete proiettile;
        prot.cancella();
    }
    else if(movimento==KEY_LEFT){
        sparo *proiettile = new sparo(prot.cy(), prot.cx(), '.', win);
        while(!proiettile->return_ostacolo()) {
            int movimento2 = wgetch(win);
            wtimeout(win, 30);

            prot.cancella();
            proiettile->cancella();
            prot.muovi(movimento2);
            proiettile->sparosx();

            proiettile->disegna();
            prot.disegna();
        }
        prot.cancella();
        proiettile->cancella2();
        delete proiettile;
    }
}*/

int main (){
    inizio();
    colori();

    WINDOW * win = newwin (24, 80, 0, 0);
    refresh(); 
    box (win, 0, 0);
    wrefresh(win);
    keypad(win, TRUE);

    personaggio prot(22, 24, '&', win);

    mvwprintw(win, 1 ,1,"__|     |_____________________________________________________________________");
    mvwprintw(win, 2 ,1,"__|     |_____________________________________________________________________");
    mvwprintw(win, 3 ,1,"__|     |_____|                                           |___________________");
    mvwprintw(win, 4 ,1,"__|     |_____|                                           |___________________");
    mvwprintw(win, 5 ,1,"__|     |_____|     _________________________________     |___________________");
    mvwprintw(win, 6 ,1,"__|     |_____|    |_________________________________|    |___________________");
    mvwprintw(win, 7 ,1,"__|                |_________________________________|    |___________________");
    mvwprintw(win, 8 ,1,"__|                |_________________________________|    |___________________");
    mvwprintw(win, 9 ,1,"__|________________|_________________________________|    |___________________");
    mvwprintw(win, 10,1,"_____________________________________________________|                        ");
    mvwprintw(win, 11,1,"_____________________________________________________|                        ");
    mvwprintw(win, 12,1,"_____________________________________________________|     ___________________");
    mvwprintw(win, 13,1,"_____________________________________________________|    |___________________");
    mvwprintw(win, 14,1,"_____________________________________________________|    |___________________");
    mvwprintw(win, 15,1,"_____________________________________________________|    |___________________");
    mvwprintw(win, 16,1,"_____________________________________________________|    |___________________");
    mvwprintw(win, 17,1,"____________________|                                     |___________________");
    mvwprintw(win, 18,1,"____________________|                                     |___________________");
    mvwprintw(win, 19,1,"____________________|     ________________________________|___________________");
    mvwprintw(win, 20,1,"____________________|    |____________________________________________________");
    mvwprintw(win, 21,1,"____________________|    |____________________________________________________");
    mvwprintw(win, 22,1,"____________________|    |____________________________________________________");

    wrefresh(win);

        while (!gameover){              //finchè non c'è un gameover posso usare il personaggio
            wtimeout(win, 80);
            int movimento = wgetch(win);
            //sparare(prot, win, movimento);
            if(movimento==KEY_UP){
                sparo *proiettile = new sparo(prot.cy(), prot.cx(), '.', win);
                while(!proiettile->return_ostacolo()) {
                    int movimento2 = wgetch(win);
                    wtimeout(win, 50);

                    prot.cancella();
                    proiettile->cancella();
                    prot.muovi(movimento2);
                    proiettile->sparosu();

                    proiettile->disegna();
                    prot.disegna();
                }
                proiettile->cancella2();
                delete proiettile;
            }
            else if(movimento==KEY_DOWN){
                sparo *proiettile = new sparo(prot.cy(), prot.cx(), '.', win);
                while(!proiettile->return_ostacolo()) {
                    int movimento2 = wgetch(win);
                    wtimeout(win, 50);

                    prot.cancella();
                    proiettile->cancella();
                    prot.muovi(movimento2);
                    proiettile->sparogiu();

                    proiettile->disegna();
                    prot.disegna();
                }
                proiettile->cancella2();
                delete proiettile;
            }
            else if(movimento==KEY_RIGHT){
                sparo *proiettile = new sparo(prot.cy(), prot.cx(), '.', win);
                while(!proiettile->return_ostacolo()) {
                    int movimento2 = wgetch(win);
                    wtimeout(win, 30);

                    prot.cancella();
                    proiettile->cancella();
                    prot.muovi(movimento2);
                    proiettile->sparodx();

                    prot.disegna();
                    proiettile->disegna();
                }
                proiettile->cancella2();
                delete proiettile;
            }
            else if(movimento==KEY_LEFT){
                sparo *proiettile = new sparo(prot.cy(), prot.cx(), '.', win);
                while(!proiettile->return_ostacolo()) {
                    int movimento2 = wgetch(win);
                    wtimeout(win, 30);

                    prot.cancella();
                    proiettile->cancella();
                    prot.muovi(movimento2);
                    proiettile->sparosx();

                    proiettile->disegna();
                    prot.disegna();
                }
                proiettile->cancella2();
                delete proiettile;
            }
            else {
                prot.cancella();
                prot.muovi(movimento);

                prot.disegna();
            }
        }

    endwin();
   return 0;
}
