#ifndef _ENEMY_H_
#define _ENEMY_H_

class enemy2{
    protected:
        WINDOW*win;
        entity E;
    public:
        enemy2(WINDOW*win, entity E){
            this->win=win;
            this->E=E;
        };
        void update_enemy(WINDOW*win, entity &E, int index){
            if(index%10<5) E.y--;
            else E.y++;
        };
        void draw_entity(entity p, WINDOW*win){
            mvwaddch(win, p.y, p.x, p.symbol);
            wrefresh(win);
        };
        void erase_entity(entity p, WINDOW*win){
            mvwaddch(win, p.y, p.x, ' ');
            wrefresh(win);
        };
        void update_bullet(WINDOW*win, entity &E, int index){

            if (index%10==3){
                E.y_bullet=E.y;
                E.x_bullet=E.x-1;
            }
            //else if(index%10==3) E.x_bullet=E.x_bullet-2;
            else if(index%10==4) E.x_bullet=E.x_bullet-2;
            else if(index%10==5) E.x_bullet=E.x_bullet-2;
            else if(index%10==6) E.x_bullet=E.x_bullet-2;
            else if(index%10==7) E.x_bullet=E.x_bullet-2;
            else if(index%10==8) {
                E.y_bullet=E.y;
                E.x_bullet=E.x-1;
            }
            else if(index%10==9) E.x_bullet=E.x_bullet-2;
            else if(index%10==0) E.x_bullet=E.x_bullet-2;
            else if(index%10==1) E.x_bullet=E.x_bullet-2;
            else if(index%10==2) E.x_bullet=E.x_bullet-2;
            


};

        void draw_bullet(WINDOW*win, entity E){
            mvwaddch(win, E.y_bullet, E.x_bullet, '-');
            wrefresh(win);
        }

        void erase_bullet(WINDOW*win, entity p){
            mvwaddch(win, p.y_bullet, p.x_bullet, ' ');
            wrefresh(win);
        };
};






#endif