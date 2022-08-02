#ifndef _PLAYER_H_
#define _player_H_

struct entity{
    int y;
    int x;
    char symbol;
    int hearts;
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
                // case 'w':
                //     shot_up(p);
                //    break;
                default:         //questo comando viene eseguito se schiaccio un tasto diverso da quelli inseriti nello switch
                    break;
            }
        }

        // void shot_up(entity p){
        //     for(int i=1; i<5;i++){
        //         if (P.y-i!=0){
        //         mvwprintw(win, P.y-i, P.x, "+");
        //         wrefresh(win);
        //         napms(100);
        //         mvwprintw(win, P.y-i,P.x, " ");
        //         wrefresh(win);
        //         }
        //     }
            
        
        

        void draw_entity(entity p, WINDOW*win){
            mvwaddch(win, p.y, p.x, p.symbol);
            wrefresh(win);
        };

        void erase_entity(entity p, WINDOW*win){
            mvwaddch(win, p.y, p.x, ' ');
            wrefresh(win);
        };

        void collision(entity p, entity e, int &hearts){
            if(p.x==e.x&&p.y==e.y) hearts--;
        };

        void print_hearts(WINDOW*win, entity p){
            mvwprintw(win,1,1, "Vite: %d", p.hearts );
            wrefresh(win);
        };



        


};








#endif

