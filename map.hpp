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
    coordinates entranceDlocation; //locazione della porta di ingresso
    coordinates exitDlocation; //locazione della porta di uscita
    bool exitDisOpen; // true = si    
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
        this->doorx.exitDisOpen = doorx.exitDisOpen;
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
    // a seconda del numero(layout) crei un layout di stanza diverso
    void draw()
    {
        refresh();
        wrefresh(room);
        werase(room);
        box(this->room,0,0);
        
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
            if (!doorx.exitDisOpen)
            {
                cord.columns = 42;
                doorx.exitDlocation.columns = cord.columns;
                cord.rows = 23;
                doorx.exitDlocation.rows = cord.rows;
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
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 23;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',5);
            wrefresh(room);
        } 
        if (layout == 1)
        {
            //muri
            coordinates cord;
            cord.columns = 1;
            cord.rows = 12;    
            mvwhline(room,cord.rows,cord.columns,0,78-5);
            cord.columns = 40;
            cord.rows = 1+3;    
            mvwvline(room,cord.rows,cord.columns,0,23-6);

            //porta da uscire (5 spazi se hor , 3 spazi se ver)
            if (!doorx.exitDisOpen)
            {
                cord.columns = 10;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,88,5);
            }
            else
            {
                cord.columns = 10;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,' ',5);
            }
            doorx.exitDlocation.columns = cord.columns;
            doorx.exitDlocation.rows = cord.rows;
            //porta da cui è entrato
            cord.columns = 10;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',5);
            wrefresh(room);    
        }
        if (layout == 2)
        {
            //muri
            coordinates cord;
            cord.columns = 27;
            cord.rows = 1;    
            mvwvline(room,cord.rows,cord.columns,0,12);
            cord.columns = 53;
            cord.rows = 12;    
            mvwvline(room,cord.rows,cord.columns,0,11);

            //porta da uscire (5 spazi se oriz , 3 spazi se verti)
            if (!doorx.exitDisOpen)
            {
                cord.columns = 79;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 79;
                cord.rows = 10;
                mvwhline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.exitDlocation.columns = cord.columns;
            doorx.exitDlocation.rows = cord.rows;
            //porta da cui è entrato
            cord.columns = 0;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 10;
            doorx.entranceDlocation.rows = cord.rows;
            mvwvline(room,cord.rows,cord.columns,' ',3);
            wrefresh(room);
        }
        if (layout == 3)
        {
            //muri
            coordinates cord;
            cord.columns = 1;
            cord.rows = 3;
            mvwhline(room,cord.rows,cord.columns,0,69);
            cord.columns = 70;
            cord.rows = 4;
            mvwvline(room,cord.rows,cord.columns,0,4);
            cord.columns = 11;
            cord.rows = 8;
            mvwhline(room,cord.rows,cord.columns,0,59);
            cord.columns = 11;
            cord.rows = 8+4;
            mvwhline(room,cord.rows,cord.columns,0,69);
            cord.columns = 11;
            cord.rows = 8+4+4;
            mvwhline(room,cord.rows,cord.columns,0,59);
            cord.columns = 10;
            cord.rows = 17;
            mvwvline(room,cord.rows,cord.columns,0,6);

            //porta da uscire (5 spazi se oriz , 3 spazi se verti)
            if (!doorx.exitDisOpen)
            {
                cord.columns = 79;
                cord.rows = 18;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 79;
                cord.rows = 18;
                mvwhline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.exitDlocation.columns = cord.columns;
            doorx.exitDlocation.rows = cord.rows;
            //porta da cui è entrato
            cord.columns = 0;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwvline(room,cord.rows,cord.columns,' ',3);
            wrefresh(room);
        }
        
    }
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
    porta.exitDisOpen = false;
    srand((unsigned)time(0));
    layout = rand() % 4;
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
