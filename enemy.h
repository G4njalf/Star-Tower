#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <ctime>
#include <stdlib.h>

class enemy{
    protected:
        WINDOW*win;
        entity E;
    public:
        enemy(WINDOW*win, entity E){
            this->win=win;
            this->E=E;
        };

        void update_enemy(WINDOW* field, entity &E){
            srand(time(0));
            int a=rand();

            //aggiornamento coordinate enemy
            if(a%10<3) E.x--;
            else if (a%10>2 && a%10<6) E.x++;
            else if (a%10>5 && a%10<8) E.y--;
            else if (a%10>7 && a%10<10) E.y++;


            //imposto margini mappa
            int yMax;
            int xMax;
            getmaxyx(field, yMax, xMax);
            if(E.y>=yMax-1) E.y=yMax-2;
            else if (E.y<=0) E.y=1;
            if (E.x>=xMax-1) E.x= xMax-2;                                 
            else if (E.x<=0) E.y=1;

        };
        void draw_entity(entity p, WINDOW*win){
            mvwaddch(win, p.y, p.x, p.symbol);
            wrefresh(win);
        };
        void erase_entity(entity p, WINDOW*win){
            mvwaddch(win, p.y, p.x, ' ');
            wrefresh(win);
        };
};

#endif