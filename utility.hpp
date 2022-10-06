#include<ncurses.h>
#include<cstdlib>

void init()
{
    initscr();
    noecho();
    raw();
    cbreak();
}

void reset()
{
    endwin();
}

void colori(){
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
}