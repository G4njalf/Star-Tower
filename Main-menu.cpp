#include "Menu.hpp"

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
int main (){
    inizio();
    colori();

    WINDOW* win = newwin (20, 50, 0, 0);
    WINDOW* window = newwin (25, 60, 0, 0);
    refresh(); 
    box (win, 0, 0);
    wrefresh(win);
    keypad(win, TRUE);

    menu1 *home=new menu1(1, win);          //creo le finestre come puntatori per poterle eliminare a piacimento
    menu2 *opzioni=new menu2(1, win);
    while(!home->return_exit() && !home->return_newgame()){         //finche' non creo la partita o non esco posso accedere ai due menu'
        home->titolo();
        home->disegna1();
        home->muovi1(win);
        if(home->return_opzioni()){             //se si attiva il booleano menu allora si pulisce lo schermo e si crea la seconda finestra, cio' avviene finche' 
            werase(win);                        //il booleano e' vero
            wrefresh(win);
            box (win, 0, 0);
            opzioni->disegna2();
            opzioni->muovi2();
        }
        if(!opzioni->return_opzioni()){         //se diventa falso faccio lo stesso
            werase(win);
            wrefresh(win);
            box (win, 0, 0);
            home->disegna1();
            home->muovi1(win);
        }
    }
    if(home->return_newgame()){         //se ho avviato una nuova partita si eliminano i menu' e si crea la finestra di gioco (da collegare tutto con la mappa poi)
        delete opzioni;
        delete home;
        clear();
        refresh();
        flash();
        box (window, 0, 0);
        wrefresh(window);
    }
    if(home->return_exit()){            //se esco dal gioco chiudo tutto e faccio l'endwin
        delete opzioni;
        delete home;
        clear();
        refresh();
        endwin();
    }

    getch();
    endwin();
    return(0);
}
