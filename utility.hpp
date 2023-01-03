#include<ncurses.h>
#include<cstdlib>
#include <cstring>

void init()
{
    initscr();
    noecho();
    raw();
    cbreak();
    curs_set(0);
}

void reset()
{
    endwin();
}

void colori(){
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
}

void gameover(){
    WINDOW * win = newwin (30, 80, 0, 0);
    refresh();
    box (win, 0, 0);
    wrefresh(win);

    int length = 70;
    int posY=6, posX=1, prevposX = posX;
    char string1[length], string2[length], string3[length], string4[length], string5[length], string6[length], string7[length];
    wattron (win, A_BOLD);
    strncpy(string1, "  -------               ------         ------    -----   ---------\0", length);
    strncpy(string2, " ---------            ---------        ---------------   ---------\0", length);
    strncpy(string3, "----                 ---     ---       --- ------- ---   ---\0", length);
    strncpy(string4, "---                 -------------      ---   ---   ---   ------\0", length);
    strncpy(string5, "----    ----       ---------------     ---         ---   ---\0", length);
    strncpy(string6, " ---------        ----         ----    ---         ---   ---------\0", length);
    strncpy(string7, "  ------         -----         -----   ---         ---   ---------\0", length);

    for (int j=0; j<2; j++){        //ripeto l'operazione due volte per scrivere con lo stesso codice sai "game"
        if(j==1){                   // sia "over"
            strncpy(string1, "  ------     ---            ---  ---------   ---------\0", length);
            strncpy(string2, " ---  ---     ---          ---   ---------   ----------\0", length);  //ogni stringa è una parte
            strncpy(string3, "--      --     ---        ---    ---         ---    ---\0", length);  //di scritta
            strncpy(string4, "-        -      ---      ---     ------      --- ----\0", length);
            strncpy(string5, "--      --       ---    ---      ---         ---   ---\0", length);
            strncpy(string6, " ---  ---         ---  ---       ---------   ---    ---\0", length);
            strncpy(string7, "  ------           ------        ---------   ---     ---\0", length);
            posY=17;
            posX=6;
            prevposX = posX;
        }
        for (int i=1; i<7; i++){
            mvwaddstr(win, posY, posX, string1);            //scrivo la scritta corrente partendo da ogni singola riga
            wrefresh(win);                                  //e avanzando verso sinistra fino alla posizione finale
            napms(40);
            mvwaddstr(win, posY, posX, " ");
            wrefresh(win);
            posX++;
        }
        posX=prevposX;              //aggiorno gli assi per passare alla riga seguente
        posY++;
        for (int i=1; i<7; i++){
            mvwaddstr(win, posY, posX, string2);
            wrefresh(win);
            napms(40);
            mvwaddstr(win, posY, posX, " ");
            wrefresh(win);
            posX++;
        }
        posX=prevposX;
        posY++;
        for (int i=1; i<7; i++){
            mvwaddstr(win, posY, posX, string3);
            wrefresh(win);
            napms(40);
            if(i!=6){
                mvwaddstr(win, posY, posX, " ");
                wrefresh(win);
            }
            posX++;
        }
        posX=prevposX;
        posY++;
        for (int i=1; i<7; i++){
            mvwaddstr(win, posY, posX, string4);
            wrefresh(win);
            napms(40);
            if(i!=6){
                mvwaddstr(win, posY, posX, " ");
                wrefresh(win);
            }
            posX++;
        }
        posX=prevposX;
        posY++;
        for (int i=1; i<7; i++){
            mvwaddstr(win, posY, posX, string5);
            wrefresh(win);
            napms(40);
            if(i!=6){
                mvwaddstr(win, posY, posX, " ");
                wrefresh(win);
            }
            posX++;
        }
        posX=prevposX;
        posY++;
        for (int i=1; i<7; i++){
            mvwaddstr(win, posY, posX, string6);
            wrefresh(win);
            napms(40);
            mvwaddstr(win, posY, posX, " ");
            wrefresh(win);
            posX++;
        }
        posX=prevposX;
        posY++;
        for (int i=1; i<7; i++){
            mvwaddstr(win, posY, posX, string7);
            wrefresh(win);
            napms(40);
            mvwaddstr(win, posY, posX, " ");
            wrefresh(win);
            posX++;
        }
    }
    wattroff(win, A_BOLD);
    getch();
    endwin();
}