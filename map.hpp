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
    Pwindow room;
    terminal sizet;
    //int layout;
    door doorx;
    int id; // numero identificativo stanza
public:
    int layout;
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
        //wavefunctioncollapse();
        layouts(layout,room,cord,doorx);  
    };

    coordinates getcoordinates() // coordinate dove spawna il player
    {
        coordinates p;
        if (layout == 0)
        {
            p.rows = 4;
            p.columns = 5;
        }
        else if (layout == 1)
        {
            p.rows = 4;
            p.columns = 5;
        }
        else if (layout == 2)
        {
            p.rows = 4;
            p.columns = 64;
        }
        else if (layout == 3)
        {
            p.rows = 5;
            p.columns = 70;
        }
        return p;
    };
};

Room StanzaRandom(bool leftDoor, bool rightDoor, Pwindow room)
{
    //Pwindow room = newwin(sizet.rows,sizet.columns,0,0);  // stanza
    terminal sizet; // grandezza della stanza
    door porta;
    int layout; //tipo di layout
    int identificativo;
    sizet.columns = 80;
    sizet.rows = 24;
    porta.LeftExitOpen = leftDoor;
    porta.RightExitOpen = rightDoor;
    srand((unsigned)time(0));
    layout = rand() % 4;
    //Pwindow room = newwin(sizet.rows,sizet.columns,0,0);
    Room SRandom = Room(room,sizet,layout,porta,identificativo);
    return SRandom;
}

Room Stanzatest(bool leftDoor, bool rightDoor, Pwindow room, int layout)
{
    //Pwindow room = newwin(sizet.rows,sizet.columns,0,0);  // stanza
    terminal sizet; // grandezza della stanza
    door porta;
    //int layout; //tipo di layout
    int identificativo;
    sizet.columns = 80;
    sizet.rows = 24;
    porta.LeftExitOpen = leftDoor;
    porta.RightExitOpen = rightDoor;
    srand((unsigned)time(0));
    //layout = rand() % 4;
    //Pwindow room = newwin(sizet.rows,sizet.columns,0,0);
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
