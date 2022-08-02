#ifndef _PLAYER_H_
#define _player_H_

struct entity{
    int y;
    int x;
    char symbol;
};


class player{
    protected:
        WINDOW*win;
        entity P;
    public: 
        player(WINDOW*win, entity P){
            this->win=win;
            this->P=P;
        }
        void update_player(entity &p, int input){
            switch (input) {
                case KEY_LEFT:
                    p.x--;
                    break;
                case KEY_RIGHT:
                    p.x++;
                    break;
                case KEY_UP:
                    p.y--;
                    break;
                case KEY_DOWN:
                    p.y++;
                    break;
                default:         //questo comando viene eseguito se schiaccio un tasto diverso da quelli inseriti nello switch
                    break;
            }
        }

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

