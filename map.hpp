#include<ncurses.h>
#include<cstdlib>
#include<ctime>
using namespace std;

struct coordinates
{
    int columns;
    int rows;
};

struct terminal
{
    int columns;
    int rows;
};

struct door
{
    //cord location; //locazione della porta
    bool isOpen; // true = si    
};

typedef WINDOW *Pwindow;

class Room
{
private:
    terminal sizet;
    Pwindow room;
    int layout; 
    door doorx;
public:
    Room(Pwindow room, terminal sizet, int layout, door doorx)
    {
        this->doorx.isOpen = doorx.isOpen;
        this->room = room;
        this->sizet = sizet;
        this->room = newwin(this->sizet.rows,this->sizet.columns,0,0);
        this->layout = layout;
        nodelay(this->room,true);
        refresh();
        box(this->room,0,0);
        wrefresh(this->room);
        refresh();

        borders(layout);
    }
    // a seconda del numero(layout) crei un layout di stanza diverso
    void borders(int layout)
    {
        if (layout == 0)
        {
            //muri
            coordinates cord;
            cord.columns = 26;
            cord.rows = 1;    
            mvwvline(room,cord.rows,cord.columns,0,8); //muovi poi disegni riga verticale nella finestra (fuori non si vede)
            mvwvline(room,cord.rows+3,cord.columns+26,0,8);
            cord.columns = 39;
            cord.rows = 12;
            mvwvline(room,cord.rows,cord.columns,0,11);
            cord.columns = 27;
            cord.rows = 12;
            mvwhline(room,cord.rows,cord.columns,0,25);
            //porta da uscire
            if (!doorx.isOpen)
            {
                cord.columns = 42;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,88,5);
            }
            else
            {
                cord.columns = 42;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,' ',5);
            }
            //porta da cui è entrato
            cord.columns = 10;
            cord.rows = 23;
            mvwhline(room,cord.rows,cord.columns,' ',5);
            wrefresh(room);
        }
    }
};



/*class Map : public Room // lista di room?
{
private:
    
public:
    Map(Pwindow room, terminal sizet, int layout, door doorx) : Room(room,sizet,layout,doorx)
    {
        
    }
};*/
