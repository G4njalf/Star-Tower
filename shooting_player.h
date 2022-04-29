#ifndef _SHOOTING_PLAYER_H_
#define _SHOOTING_PLAYER_H_



class shooting_player{
    protected:
        WINDOW* win;
        int pos_y;
        int pos_x;
        char c;
        int yMax;
        int xMax;

    public:
        shooting_player(WINDOW* win, int pos_y, int pos_x){
            this->pos_y=pos_y;
            this->pos_x=pos_x;
            this->win=win; 
        };

        void init(){
            initscr();
            noecho();
            curs_set(0);  
        };

        void end(){
            getch();
            endwin();
        };

        void create_win_box(){
            win=newwin (10, 17, 7, 10 );
            refresh();
            box(win, 0, 0);
            wrefresh(win);
            keypad(win, true);
            getmaxyx(win, yMax, xMax);
        };

        void player(){
            pos_y=yMax/2;
            pos_x=xMax/2;

            //stampo P al centro dello schermo
            mvwprintw(win, pos_y, pos_x, "P");
            wrefresh(win);
        }

        void moveup(){
            mvwprintw(win, pos_y, pos_x, " ");
            wrefresh(win);
            pos_y--;
            if (pos_y==0) pos_y=1;
            mvwprintw(win, pos_y, pos_x, "P");
            wrefresh(win);
        }

        void movedown(){
            mvwprintw(win, pos_y, pos_x, " ");
            wrefresh(win);
            pos_y++;
            if (pos_y==yMax-1) pos_y=yMax-2;
            mvwprintw(win, pos_y, pos_x, "P");
            wrefresh(win);
        }

        void moveright(){
            mvwprintw(win, pos_y, pos_x, " ");
            wrefresh(win);
            pos_x++;
            if (pos_x==xMax-1) pos_x=xMax-2;
            mvwprintw(win, pos_y, pos_x, "P");
            wrefresh(win);
        }

        void moveleft(){
            mvwprintw(win, pos_y, pos_x, " ");
            wrefresh(win);
            pos_x--;
            if(pos_x==0) pos_x=1;
            mvwprintw(win, pos_y, pos_x, "P");
            wrefresh(win);
        }

        void shotup(){
            for(int i=1; i<5;i++){
                if (pos_y-i!=0){
                mvwprintw(win, pos_y-i, pos_x, "+");
                wrefresh(win);
                napms(100);
                mvwprintw(win, pos_y-i, pos_x, " ");
                wrefresh(win);
                }
            }
        }

        void shotdown(){
            for(int i=1; i<5;i++){
                if (pos_y+i!=yMax-1){
                mvwprintw(win, pos_y+i, pos_x, "+");
                wrefresh(win);
                napms(100);
                mvwprintw(win, pos_y+i, pos_x, " ");
                wrefresh(win);
                }
            }
        }

        void shotleft(){
            for(int i=1; i<5;i++){
                if (pos_x-i!=0){
                mvwprintw(win, pos_y, pos_x-i, "+");
                wrefresh(win);
                napms(100);
                mvwprintw(win, pos_y, pos_x-i, " ");
                wrefresh(win);
                }
            }
        }

        void shotright(){
            for(int i=1; i<5;i++){
                if (pos_x+i!=xMax){
                mvwprintw(win, pos_y, pos_x+i, "+");
                wrefresh(win);
                napms(100);
                mvwprintw(win, pos_y, pos_x+i, " ");
                wrefresh(win);
                }
            }
        }



        int getmove(){
            int choice;
            while (choice!='x'){
                choice=wgetch(win);
                switch(choice)
                    {
                    case KEY_UP:
                        moveup();
                        break;
                    case KEY_DOWN:
                        movedown();
                        break;
                    case KEY_LEFT:
                        moveleft();
                        break;
                    case KEY_RIGHT:
                        moveright();
                        break;
                    case 'w':
                        shotup();
                        break;
                    case 's':
                        shotdown();
                        break;
                    case 'a':
                        shotleft();
                        break;
                    case 'd':
                        shotright();
                        break;
                    default:
                        break;
                }
            }
            return choice;

        }
};

#endif
