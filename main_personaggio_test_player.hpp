#include <iostream>
#include "personaggio_T.hpp"


bool gameover = false;
bool chmap = false; // 1 se devi cambiare mappa
bool bf = true;

int changemap(int layout, int rows, int columns) // 0 == vai indietro // 1 == vai avanti a SX // 2 == vai avanti a DX
{
    //layout 0
    if (layout == 0 && rows >= 20)
    {
        return 1; 
    }
    else if (layout == 0 && columns >= 77)
    {
        return 2;
    }
    else if (layout == 0 && rows <= 1)
    {
        return 0;
    }
    //layout 1
    else if (layout == 1 && rows <= 1)
    {
        return 0;
    }
    else if (layout == 1 && columns<= 2)
    {
        return 1;
    }
    else if (layout == 1 && rows >= 21)
    {
        return 2;
    }
    //layout 2
    else if (layout == 2 && rows <= 1)
    {
        return 0;
    }
    else if (layout == 2 && columns <= 2)
    {
        return 1;
    }
    else if (layout == 2 && columns >= 77)
    {
        return 2;
    }
    //layout 3
    else if (layout == 3 && columns >= 77)
    {
        return 0;
    }
    else if (layout == 3 && columns <= 2)
    {
        return 1;
    }
    else if (layout == 3 && rows >= 21)
    {
        return 2;
    }
    
    return 100;
    chmap = false;
    
}

void player (WINDOW* win, coordinates p, int layout){
    chmap = false;
    refresh();
    keypad(win, TRUE);
    personaggio prot(p.rows, p.columns, '&', win);

    while (!gameover && !chmap){    //finchè non c'è un gameover o cambiomappa posso usare il personaggio
            wtimeout(win, 80);
            int movimento = wgetch(win);
            //sparare(prot, win, movimento);
            /*if(movimento==KEY_UP){
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
            else {*/
                prot.cancella();
                prot.muovi(movimento);

                prot.disegna();
            //}
        
            if (changemap(layout,getcury(win),getcurx(win)) != 100)
            {
                chmap = true;
                prot.cancella();
                //mvaddch(10,10,'s');
                //refresh();
            }
            else
            {
                chmap = false;
                //mvaddch(10,10,'n');
                //refresh();
            }
        }
}

