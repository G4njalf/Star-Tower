#include<ncurses.h>
#include<cstdlib>
#include<ctime>
#include"draw.hpp"
using namespace std;

struct terminal
{
    int columns;
    int rows;
};

typedef WINDOW *Pwindow;

class Room
{
private:
    terminal sizet;
    Pwindow room;
    int layout; 
    door doorx;
    int id; // numero identificativo stanza
public:
    Room(Pwindow room, terminal sizet, int layout, door doorx, int id)
    {
        this->id = id;
        this->doorx = doorx;
        this->room = room;
        this->sizet = sizet;
        //this->room = newwin(this->sizet.rows,this->sizet.columns,0,0);
        this->layout = layout;
        nodelay(this->room,true);
        refresh();
        //box(this->room,0,0);
        wrefresh(this->room);
        refresh();

        //draw(layout);
    }

    void draw()
    {
        refresh();
        wrefresh(room);
        werase(room);
        box(this->room,0,0);
        coordinates cord;
        wavefunctioncollapse();
        layouts(layout,room,cord,doorx);    
    };
};

Room StanzaRandom()
{
    //Pwindow room = newwin(sizet.rows,sizet.columns,0,0);  // stanza
    terminal sizet; // grandezza della stanza
    door porta;
    int layout; //tipo di layout
    int identificativo;
    sizet.columns = 80;
    sizet.rows = 24;
    porta.LeftExitOpen = false;
    porta.RightExitOpen = true;
    srand((unsigned)time(0));
    layout = rand() % 2;
    Pwindow room = newwin(sizet.rows,sizet.columns,0,0);
    Room SRandom = Room(room,sizet,layout,porta,identificativo);
    return SRandom;
}


/*class Map : public Room // lista di room?
{
private:
    
public:
    Map(Pwindow room, terminal sizet, int layout, door doorx) : Room(room,sizet,layout,doorx)
    {
        
    }
};*/
