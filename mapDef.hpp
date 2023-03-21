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
    door doorx;
public:
    int layout;
    int id; //numero identificativo stanza
    Room(Pwindow room, terminal sizet, int layout, door doorx, int id);
    void draw(WINDOW * stats);
    void open_right_exit();
    coordinates getcoordinatesP(); // coordinate dove spawna il player
    coordEnemy getcoordinatesE1(); // coordinate dove spawna il nemico 1 // 3 possibili spawn
    coordEnemy getcoordinatesE2(); // coordinate dove spawna il nemico 2 // 3 possibili spawn
    coordEnemy getcoordinatesE3(); // coordinate dove spawna il nemico 3 //3 possibili spawn
};

Room StanzaRandom(bool leftDoor, bool rightDoor, Pwindow room);


Room Stanza(bool leftDoor, bool rightDoor, Pwindow room, int layout, int id);

