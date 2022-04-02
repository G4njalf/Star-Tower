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

Pwindow room;
terminal cordi;
door porta;
int main()
{
    init();
    cordi.columns = 80;
    cordi.rows = 24;
    porta.isOpen = false;
    Room Roompa = Room(room,cordi,0,porta);
    //Roompa.borders();
    int ch = getch();
    while (ch == 'v')
    {
        reset();
        break;
    }
    
    reset();
    
}