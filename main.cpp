#include <ncurses.h>
#include "player.h"
#include "enemy.h"



int main(){
    
    initscr();
    noecho();
    curs_set(0);

    //finestra dove si muove il giocatore
    WINDOW *field=newwin(15, 40, 10, 10); 
    refresh();
    box(field, 0, 0);
    wrefresh(field);
    //finestra delle vite
    WINDOW*hpw=newwin(3, 10, 3, 10);
    refresh();
    box(hpw, 0, 0);
    wrefresh(hpw);
    keypad(field, TRUE);
   

    //creo struct player
    entity P;
    P.x=20;
    P.y=10;
    P.symbol='P';
    P.hearts=3;
    //creo oggetto player
    player giocatore=player(field, P);

    //creo struct enemy
    entity E;
    E.x=30;
    E.y=10;
    E.symbol='@';
    //creo oggetto enemy
    enemy nemico=enemy(field, E);


    while(1){
        //handle input
        wtimeout(field, 250);
        int input=wgetch(field);

        //update stuff and erase player and enemy
        giocatore.erase_entity(P, field);
        nemico.erase_entity(E, field);
        giocatore.update_player(P, input);
        nemico.update_enemy(field, E);
        

        //print stuff
        giocatore.draw_entity(P, field);
        nemico.draw_entity(E, field);
        giocatore.collision(P, E, P.hearts);
        giocatore.print_hearts(hpw, P);
    };












    getch();
    endwin();
}
