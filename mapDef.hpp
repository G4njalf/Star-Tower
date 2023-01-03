#include<ncurses.h>
#include<cstdlib>
#include<ctime>
#include"draw.hpp"
using namespace std;

struct coordEnemy
{
    int col1;
    int row1;
    int col2;
    int row2;
    int col3;
    int row3;
};

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
public:
    int layout;
    int id; //numero identificativo stanza
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

    void draw(WINDOW * stats)
    {
        refresh();
        wrefresh(room);
        werase(room);
        box(this->room,0,0);
        coordinates cord;
        layouts(layout,room,cord,doorx);
        statistiche(stats);
    };

    void open_right_exit(){
        doorx.RightExitOpen=true;
    }

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

//le coordinate sono randomiche tra 3 combinazioni possibili
    coordEnemy getcoordinatesE1() // coordinate dove spawna il nemico 1 // 3 possibili spawn
    {
        coordEnemy e1;
        if (layout == 0)
        {
            e1.row1 = 6;
            e1.col1 = 48;
            e1.row2 = 6;
            e1.col2 = 48;
            e1.row3 = 3;
            e1.col3 = 30;
        }
        else if (layout == 1) 
        {
            e1.row1 = 3;
            e1.col1 = 29;
            e1.row2 = 3;
            e1.col2 = 29;
            e1.row3 = 3;    
            e1.col3 = 60;
        }
        else if (layout == 2) 
        {
            e1.row1 = 7;
            e1.col1 = 15;
            e1.row2 = 7;
            e1.col2 = 15;
            e1.row3 = 7;
            e1.col3 = 15;
        }
        else if (layout == 3) 
        {
            e1.row1 = 7;
            e1.col1 = 24;
            e1.row2 = 19;
            e1.col2 = 10;
            e1.row3 = 7;
            e1.col3 = 24;
        }
        return e1;
    };
   
   coordEnemy getcoordinatesE2() // coordinate dove spawna il nemico 2 // 3 possibili spawn
    {
        coordEnemy e2;
        if (layout == 0) // 15,20
        {
            e2.row1 = 15;
            e2.col1 = 20;
            e2.row2 = 15;
            e2.col2 = 20;
            e2.row3 = 17;
            e2.col3 = 45;
        }
        else if (layout == 1) //11,66
        {
            e2.row1 = 11;
            e2.col1 = 66;
            e2.row2 = 11;
            e2.col2 = 66;
            e2.row3 = 11;
            e2.col3 = 66;
        }
        else if (layout == 2) //9,46
        {
            e2.row1 = 9;
            e2.col1 = 46;
            e2.row2 = 20;
            e2.col2 = 55;
            e2.row3 = 9;
            e2.col3 = 65;
        }
        else if (layout == 3) //9,65
        {
            e2.row1 = 9;
            e2.col1 = 65;
            e2.row2 = 10;
            e2.col2 = 65;
            e2.row3 = 9;
            e2.col3 = 65;
        }
        return e2;
    };

    coordEnemy getcoordinatesE3() // coordinate dove spawna il nemico 3 //3 possibili spawn
    {
        coordEnemy e3;
        if (layout == 0) //17,60
        {
            e3.row1 = 17;
            e3.col1 = 60;
            e3.row2 = 17;
            e3.col2 = 60;
            e3.row3 = 17;
            e3.col3 = 60;   
        }
        else if (layout == 1) //18,34
        {
            e3.row1 = 18;
            e3.col1 = 34;
            e3.row2 = 18;
            e3.col2 = 34;
            e3.row3 = 18;
            e3.col3 = 15;
        }
        else if (layout == 2) //19,40
        {
            e3.row1 = 19;
            e3.col1 = 40;
            e3.row2 = 16;
            e3.col2 = 20;
            e3.row3 = 19;
            e3.col3 = 40;
        }
        else if (layout == 3) //16,42
        {
            e3.row1 = 16;
            e3.col1 = 10;
            e3.row2 = 18;
            e3.col2 = 42;
            e3.row3 = 16;
            e3.col3 = 42;
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
    srand(time(NULL));
    layout = rand() % 4;
    identificativo= rand()%3;
    Room SRandom = Room(room,sizet,layout,porta,identificativo);
    return SRandom;
}

Room Stanza(bool leftDoor, bool rightDoor, Pwindow room, int layout, int id)
{
    terminal sizet; // grandezza della stanza
    door porta;
    sizet.columns = 80;
    sizet.rows = 24;
    porta.LeftExitOpen = leftDoor;
    porta.RightExitOpen = rightDoor;
    Room SRandom = Room(room,sizet,layout,porta,id);
    return SRandom;
}
