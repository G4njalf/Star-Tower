#include<ncurses.h>
#include<cstdlib>
#include<ctime>
using namespace std;

struct coordinates
{
    int x;
    int y;
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

class Map
{
private:
    terminal sizet;
    Pwindow map;
public:
    Map(Pwindow map, terminal sizet)
    {
        this->map = map;
        this->sizet = sizet;
        this->map = newwin(this->sizet.rows,this->sizet.columns,0,0);
        nodelay(this->map,true);
        refresh();
        box(this->map,0,0);
        wrefresh(this->map);
        refresh();
    }
    void borders()
    {
        coordinates cord;
        cord.x = 40;
        cord.y = 15;    
        mvwvline(map,cord.y,cord.x,0,200);
        refresh();
        //mvprintw(cord.y,cord.x,"q");
        wrefresh(map);
    }

};

class Room : public Map
{
private:
    
public:
    Room(Pwindow map, terminal sizet) : Map(map,sizet)
    {
        
    }
};
