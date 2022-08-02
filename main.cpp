#include <ncurses.h>
#include "player.h"
#include "enemy.h"



int main(){
    
    initscr();
    noecho();
    curs_set(0);

    WINDOW *field=newwin(15, 40, 10, 10);
    refresh();
    box(field, 0, 0);
    wrefresh(field);
    keypad(field, TRUE);
    nodelay(field, true);
    int yMax;
    int xMax;
    getmaxyx(field, yMax, xMax);

    //creo struct player
    entity P;
    P.x=20;
    P.y=10;
    P.symbol='P';
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
        napms(150);
        int input=wgetch(field);

        //update stuff and erase player and enemy
        giocatore.erase_entity(P, field);
        nemico.erase_entity(E, field);
        giocatore.update_player(P, input);
        nemico.update_enemy(E);
        if(E.y>=yMax-1) E.y=yMax-2;
        else if (E.y<=0) E.y=1;
        if (E.x>=xMax-1) E.x= xMax-2;
        else if (E.x<=0) E.y=1;


        //print stuff
        giocatore.draw_entity(P, field);
        nemico.draw_entity(E, field);
    };












    getch();
    endwin();
}
