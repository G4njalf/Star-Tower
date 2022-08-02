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

        void update_enemy(entity &E){
            srand(time(0));
            int a=rand();

            if(a%10<3) E.x--;
            else if (a%10>2 && a%10<6) E.x++;
            else if (a%10>5 && a%10<8) E.y--;
            else if (a%10>7 && a%10<10) E.y++;
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