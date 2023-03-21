#include <ncurses.h>

struct artifact_list{
    int ax;
    int ay;
    artifact_list *next;
};

typedef artifact_list* lartifact;

class artifact {
public:
    artifact(WINDOW* win, int y, int x, char c);

    int cy();
    int cx();
    void draw();
    void drawhpup();
    void clear();
    bool collected (int y, int x);
    bool return_remove();
    void canttake();
    void its_removed();

protected:
    int posX, posY;
    char character;
    bool remove;
    WINDOW * window;
};


class key : public artifact{
public:
    key(WINDOW* win, int y, int x, char c);
    bool return_used_right();
    bool return_used_left();
    void print_key_if_necessary(int layout,int vita_e1, int vit_e2, int vita_e3);
    bool return_taken();
    void taken_true();
    void open_door_if_necessary(int layout, int Py, int Px);
    void used_right_true();
    void used_left_true();

protected:
    bool used_right=false;
    bool used_left=false;
    bool taken=false;
};


class coins : public artifact{
public:
    coins(WINDOW* win, int y, int x, char c, int y2, int x2, int id, lartifact co);
    void all_coins();
    void add_coinsquare(int i);
    void add_coinvert();
    void add_coinhoriz();
    void print_coins();
    void delete_coins(int y, int x);
    int return_counter();
    bool return_delone();
    lartifact return_currlist();
    void change_list(lartifact nc);
protected:
    lartifact coin;
    bool second, last_one, delone;
    int posX2, posY2, tmpY, tmpX, id_room, tmpY2, tmpX2, counter;
};

