#include"map.hpp"
#include<thread>

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

Pwindow map;
terminal cordi;

int main()
{
    init();
    cordi.columns = 80;
    cordi.rows = 24;
    Map mappa = Map(map,cordi);
    mappa.borders();
    int ch = getch();
    while (ch == 'v')
    {
        reset();
        break;
    }
    
    reset();
    
}