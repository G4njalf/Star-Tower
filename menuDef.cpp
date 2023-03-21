#include "menuDef.hpp"
menu1 :: menu1(int c, WINDOW* w){
    current=c;
    win = w;
    strncpy(stringm1, "NEW GAME", 10);
    strncpy(stringm2, "INFO", 10);
    strncpy(stringm3, "EXIT", 10);
    strncpy(stringm4, "~STAR TOWER~", 15);
}

void menu1 :: position() {
    if (current == 1) {
        mvwaddstr(win, 7, 21, stringm2);             //pulisco le scritte se sono state evidenziate
        mvwaddstr(win, 9, 21, stringm3);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 5, 21, stringm1);             //evidenzio la scritta in cui c'e' il cursore
        wrefresh(win);
    } else if (current == 2) {
        mvwaddstr(win, 5, 21, stringm1);
        mvwaddstr(win, 9, 21, stringm3);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 7, 21, stringm2);
        wrefresh(win);
    } else {
        mvwaddstr(win, 5, 21, stringm1);
        mvwaddstr(win, 7, 21, stringm2);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 9, 21, stringm3);
        wrefresh(win);
    }
    wattroff(win, A_REVERSE);
}

void menu1 :: titolo(){
    int j=48;
    for(int i=1; i<16; i++) {
        mvwprintw(win, 1, i, "_");          //fa l'effetto iniziale scrivendo e poi cancellando i trattini
        mvwprintw(win, 1, j, "_");
        j--;
        wrefresh(win);
        napms(70);
    }
       // if (i == 16) {
            wattron(win, A_UNDERLINE);
            mvwaddstr(win, 1, 18, stringm4);         //sottolineo il titolo
            wattroff(win, A_UNDERLINE);
            j=30;
            for (int i=16; i!=0; i--) {
                mvwprintw(win, 1, i, " ");
                mvwprintw(win, 1, j, " ");
                napms(70);
                wrefresh(win);
                j++;
            }
      //  }

}
void menu1 :: disegna1(){
    options = false;
    wattron(win, A_UNDERLINE);
    mvwaddstr(win, 1, 18, stringm4);
    wattroff(win, A_UNDERLINE);
    mvwaddstr(win, 7, 21, stringm2);
    mvwaddstr(win, 9, 21, stringm3);
    mvwaddstr(win, 5, 21, stringm1);
    wrefresh(win);
}

void menu1 :: muovi1(WINDOW* window){
    while((push = wgetch(win))!='x' && !options){
        switch(push){                       //verifico la posizione del cursore
            case KEY_UP:
                current--;
                if(current==0){             //varia il current se muovi la freccia su o giu'
                    current=1;
                }
                break;
            case KEY_DOWN:
                current++;
                if(current==4){
                    current=3;
                }
                break;
            case 10:
                if(current==1){
                    newgame=true;
                }
                else if(current==2){
                    options=true;
                }
                else{
                    exit=true;
                }
                break;
            default:
                break;
        }
        if(push==10){       //se viene premuto enter si chiude la schermata
            break;
        }
        position();
    }
}

bool menu1 :: return_opzioni() {
    return options;
}
bool menu1 :: return_newgame() {
    return newgame;
}
bool menu1 :: return_exit() {
    return exit;
}
void menu1 :: cancella(){
    werase(win);
    wrefresh(win);
    clear();
    refresh();
}

menu2 :: menu2(int curr, WINDOW* window) : menu1 (curr, window){
    strncpy(string1, "ARTEFATTI:", 11);
    strncpy(string2, "HPUP", 5);
    strncpy(string3, "COINS", 6);
    strncpy(string4, "CHIAVE", 7);
    strncpy(string5, "NEMICI:", 8);
    strncpy(string6, "DISPLAY", 8);
    strncpy(string7, "TIPI", 5);
    strncpy(string8, "<= BACK", 8);
}

void menu2 :: position2(){
    if(current==1){
        mvwaddstr(win, 5, 21, string3);
        mvwaddstr(win, 7, 21, string4);
        mvwaddstr(win, 11, 21, string6);
        mvwaddstr(win, 13, 21, string7);
        mvwaddstr(win, 17, 2, string8);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 3, 21, string2);
        wrefresh(win);
    }
    else if(current==2){
        mvwaddstr(win, 3, 21, string2);
        mvwaddstr(win, 7, 21, string4);
        mvwaddstr(win, 11, 21, string6);
        mvwaddstr(win, 13, 21, string7);
        mvwaddstr(win, 17, 2, string8);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 5, 21, string3);
        wrefresh(win);
    }
    else if(current==3){
        mvwaddstr(win, 3, 21, string2);
        mvwaddstr(win, 5, 21, string3);
        mvwaddstr(win, 11, 21, string6);
        mvwaddstr(win, 13, 21, string7);
        mvwaddstr(win, 17, 2, string8);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 7, 21, string4);
        wrefresh(win);
    }
    else if(current==4){
        mvwaddstr(win, 3, 21, string2);
        mvwaddstr(win, 5, 21, string3);
        mvwaddstr(win, 7, 21, string4);
        mvwaddstr(win, 13, 21, string7);
        mvwaddstr(win, 17, 2, string8);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 11, 21, string6);
        wrefresh(win);
    }
    else if(current==5){
        mvwaddstr(win, 3, 21, string2);
        mvwaddstr(win, 5, 21, string3);
        mvwaddstr(win, 7, 21, string4);
        mvwaddstr(win, 11, 21, string6);
        mvwaddstr(win, 17, 2, string8);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 13, 21, string7);
        wrefresh(win);
    }
    else if(current==6){
        mvwaddstr(win, 3, 21, string2);
        mvwaddstr(win, 5, 21, string3);
        mvwaddstr(win, 7, 21, string4);
        mvwaddstr(win, 11, 21, string6);
        mvwaddstr(win, 13, 21, string7);
        wattron(win, A_REVERSE);
        mvwaddstr(win, 17, 2, string8);
        wrefresh(win);
    }
    wattroff(win, A_REVERSE);
}

void menu2 :: disegna2(){
    options = true;
    wattron(win, A_UNDERLINE);
    mvwaddstr(win, 5, 2, string1);
    mvwaddstr(win, 12, 2, string5);
    wattroff(win, A_UNDERLINE);

    mvwaddstr(win, 17, 2, string8);
    mvwaddstr(win, 5, 21, string3);
    mvwaddstr(win, 7, 21, string4);
    mvwaddstr(win, 11, 21, string6);
    mvwaddstr(win, 13, 21, string7);
    mvwaddstr(win, 3, 21, string2);
    wrefresh(win);
}

void menu2 :: muovi2(){
    current = 1;
    wclear(win);
    wrefresh(win);
    box(win, 0, 0);
    wrefresh(win);
    keypad(win, TRUE);

    wattron(win, A_UNDERLINE);
    mvwaddstr(win, 5, 2, string1);
    mvwaddstr(win, 12, 2, string5);
    wattroff(win, A_UNDERLINE);

    mvwaddstr(win, 17, 2, string8);
    mvwaddstr(win, 5, 21, string3);
    mvwaddstr(win, 7, 21, string4);
    mvwaddstr(win, 11, 21, string6);
    mvwaddstr(win, 13, 21, string7);
    mvwaddstr(win, 3, 21, string2);
    wrefresh(win);

    while ((push = wgetch(win)) != 'x' && options) {
        switch (push) {
            case KEY_UP:
                current--;
                if (current == 0) {
                    current = 1;
                }
                break;
            case KEY_DOWN:
                current++;
                if (current == 7) {
                    current = 6;
                }
                break;
            case 10:
                if (current == 1) {
                    move(21, 2);
                    clrtoeol();             //cancello la riga corrispondente
                    difficile = true;
                    mvprintw(21, 2, "si puo' raccogliere al prezzo di 200 score, aggiunge 50 hp");
                    move(3, 21);
                    refresh();
                }
                else if (current == 2) {
                    move(21, 2);
                    clrtoeol();
                    normale = true;
                    mvprintw(21, 2, "spawnano a gruppi, se raccolte aggiungono 10 punti score");
                    move(5, 21);
                    refresh();
                }
                else if (current == 3) {
                    move(21, 2);
                    clrtoeol();
                    facile = true;
                    mvprintw(21, 2, "la chiave 'K' spawna una volta uccisi tutti i nemici e si puo' usare solo nella stanza corrente");
                    move(7, 21);
                    refresh();
                }
                if (current == 4) {
                    move(21, 2);
                    clrtoeol();
                    effettion = true;
                    mvprintw(21, 2, "'V' e' il carattere che rappresenta i nemici");
                    move(11, 21);
                    refresh();
                }
                if (current == 5) {
                    move(21, 2);
                    clrtoeol();
                    effettioff = true;
                    mvprintw(21, 2, "sono sempre in movimento, spawnano con o senza arma");
                    move(13, 21);
                    refresh();
                }
                else if (current == 6) {
                    move(21, 2);
                    clrtoeol();
                    move(17, 2);
                    refresh();
                    options=false;
                }
                break;
            default:
                break;
        }
        position2();
        if(current==6 && push==10){
            break;
        }
    }
}
bool menu2 :: return_effetti(){
    return effettion;
}
bool menu2 :: return_difficile(){
    return difficile;
}
bool menu2 :: return_facile(){
    return facile;
}
bool menu2 :: return_normale(){
    return normale;
}


void inizioo(){
    initscr();
    noecho();
    raw();
    cbreak();
}
void colorii(){
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
}

bool menu () {
    bool exitgame = false;
    inizioo();
    colorii();

    WINDOW *win = newwin(20, 50, 0, 0);
    WINDOW *window = newwin(25, 60, 0, 0);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    keypad(win, TRUE);

    menu1 *home = new menu1(1, win);
    menu2 * opzioni = new menu2(1, win);
    home->titolo();
    while (!home->return_exit() && !home->return_newgame()) {
        if (!opzioni->return_opzioni()) {
            werase(win);
            wrefresh(win);
            box(win, 0, 0);
            home->disegna1();
            home->muovi1(win);
        }
        if (home->return_opzioni()) {
            werase(win);
            wrefresh(win);
            box(win, 0, 0);
            opzioni->disegna2();
            opzioni->muovi2();
        }
    }
    if (home->return_newgame()) {
        delete opzioni;
        delete home;
        clear();
        refresh();
        flash();
        //box (window, 0, 0);
        wrefresh(window);
    }
    if (home->return_exit()) {
        exitgame = true;
        delete opzioni;
        delete home;
        clear();
        refresh();
        endwin();
    }
    //getch();
    //endwin();
    return (exitgame);
}