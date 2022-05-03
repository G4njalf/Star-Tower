#include<ncurses.h>
#include<cstdlib>

void init()
{
    initscr();
    noecho();
    cbreak();
}

void reset()
{
    endwin();
}

