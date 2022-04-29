#include <ncurses.h>
using namespace std;
#include "shooting_player.h"

int main(){

    int y, x;
    getmaxyx(stdscr, y, x);
    WINDOW* win;
    refresh();
    
    shooting_player object=shooting_player(win,y/3, x/3);

    object.init();

    object.create_win_box();
    object.player();
    object.getmove();
    


    object.end();
    
}