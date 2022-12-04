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
        layouts(layout,room,cord,doorx);  
    };

    coordinates getcoordinatesP() // coordinate dove spawna il player
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

//fare che le coordinate siano randomiche tra 3 combinazioni possibili
    coordinates getcoordinatesE1() // coordinate dove spawna il nemico 1
    {
        coordinates e1;
        if (layout == 0)
        {
            e1.rows = 6;
            e1.columns = 48;
        }
        else if (layout == 1)
        {
            e1.rows = 5;
            e1.columns = 29;
        }
        else if (layout == 2)
        {
            e1.rows = 7;
            e1.columns = 15;
        }
        else if (layout == 3)
        {
            e1.rows = 7;
            e1.columns = 24;
        }
        return e1;
    };
   
   coordinates getcoordinatesE2() // coordinate dove spawna il nemico 2
    {
        coordinates e2;
        if (layout == 0)
        {
            e2.rows = 15;
            e2.columns = 20;
        }
        else if (layout == 1)
        {
            e2.rows = 11;
            e2.columns = 66;
        }
        else if (layout == 2)
        {
            e2.rows = 9;
            e2.columns = 46;
        }
        else if (layout == 3)
        {
            e2.rows = 9;
            e2.columns = 65;
        }
        return e2;
    };

    coordinates getcoordinatesE3() // coordinate dove spawna il nemico 3
    {
        coordinates e3;
        if (layout == 0)
        {
            e3.rows = 17;
            e3.columns = 58;
        }
        else if (layout == 1)
        {
            e3.rows = 18;
            e3.columns = 34;
        }
        else if (layout == 2)
        {
            e3.rows = 21;
            e3.columns = 44;
        }
        else if (layout == 3)
        {
            e3.rows = 16;
            e3.columns = 42;
        }
        return e3;
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

Room Stanza(bool leftDoor, bool rightDoor, Pwindow room, int layout)
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
