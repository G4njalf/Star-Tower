#include <iostream>
#include "Personaggio.hpp"
#include "Artefatti.hpp"
#include "Nemici.hpp"

bool gameover = false;
bool bf = true;

//int notimeout(WINDOW * window, bool bf);

/*void funzpers(personaggio p, hpup h, nemico n){
    p.colpito(n.cy(), n.cx(), n.dannobomba(), n);
    h.raccolto(p);
}*/

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

void scrittagameover(personaggio prot, WINDOW * win){
    wattron (win, COLOR_PAIR(3));
    char A[8] = {'G','A', 'M','E','O','V','E','R'};
    int x = 20;
    for (int i=0; i<8; i++){
        mvwaddch(win, 9, x, A[i]);
        wrefresh(win);
        napms(200);
        x++;
    }
    wattroff (win, COLOR_PAIR(3));
    wrefresh(win);
}

int main (){
    inizio();
    colori();

    WINDOW * win = newwin (20, 50, 0, 0);
    refresh();
    box (win, 0, 0);
    wrefresh(win);
    keypad(win, TRUE);

    personaggio prot(10, 25, '&', 100, win);
    int prevl = prot.cl();
    mina * bomba = new mina('*', 100, 16, 40);
    hpup * vita = new hpup(10, 11, 50);
    lanciabomba * nemico2 = new lanciabomba(ACS_BLOCK, 50, 2, 8);
    bomba->disegna(win);
    vita->disegna(win);
    mvwprintw(win, 18, 40, "VITA: ");
    mvwprintw(win, 18, 46, "%d", prevl);
    wrefresh(win);
    int i=0;
    nodelay(win, TRUE);
    do {
        while (!gameover){              //finchè non c'è un gameover posso usare il personaggio
      //      funzpers(prot, vita, bomba);
            prot.disegna();
           // notimeout(win, bf);
           // prot.colpito(bomba.cy(), bomba.cx(), bomba.dannobomba(), bomba);
            bomba->colpito(prot, prot.cy(), prot.cx(), win);
            if (vita->raccolto(prot)==1){
                delete vita;
            }
            if (bomba->colpito(prot, cy(), cx(), win)){
                delete bomba;
            }
          //  nemico2.disegna(win);
            if (prot.cl()!=prevl){
                mvwprintw(win, 18, 46, "   ");
                mvwprintw(win, 18, 46, "%d", prevl);
                wrefresh(win);
                prevl = prot.cl();
            }
            if (prot.muovi()=='x' || prot.cl() <= 0) {       //per uscire "forzatamente" premere x,
                wclear(win);                        // altrimenti esce in automatico se muori
                flash();
                scrittagameover(prot, win);
                gameover = true;
            }
          //  nemico2.muovi(win);
            /*if (i==0){
                prot.incrementavita(9);
            }*/
        }
    }
    while (prot.muovi()!='x');      //esco dal progetto

    endwin();
    cout << prot.cl() << endl;
    //cout << prot.cy() << " " << prot.cx() << endl;
    cout << prot.cy() << " " << prot.cx() << endl;
   return 0;
}