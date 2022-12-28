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

protected:
    int posX, posY;
    char character;
    bool remove;
    WINDOW * window;
};
artifact :: artifact(WINDOW * win, int y, int x, char c){
        posY = y;
        posX = x;
        character = c;
        window = win;
    }
    int artifact :: cy(){
        return posY;
    }
    int artifact :: cx(){
        return posX;
    }
    bool artifact :: collected (int y, int x){                   //controlla se e' sopra all'artefatto, se si dice al player
        bool check=false;                                    //di aggiungere il bonus e cancella l'artefatto
        if (posY==y && posX==x){
            remove = true;
            check=true;
            mvwaddch(window, posY, posX, ' ');
        }
        return check;
    }
    void artifact ::canttake() {
        remove = false;
    }
    void artifact :: clear() {
        mvwaddch(window, posY, posX, ' ');
    }
    bool artifact :: return_remove(){
        return remove;
    }
    void artifact :: draw (){
        mvwaddch(window, posY, posX, character);
    }
    void artifact :: drawhpup (){
        mvwaddch(window, posY, posX, ACS_DIAMOND);
    }


class key : public artifact{
public:
    key(WINDOW* win, int y, int x, char c);
    void near_door();
    bool return_used();
protected:
    bool used=false;
};
key :: key(WINDOW* win, int y, int x, char c):artifact(win, y, x, c){}
bool key ::return_used() {
    return used;
}
void key :: near_door(){
    //se la porta e' in prossimita', la porta si apre e la chiave si cancella
}

class coins : public artifact{
public:
    coins(WINDOW* win, int y, int x, char c, int y2, int x2, int id);
    void all_coins();
    void add_coinsquare(int i);
    void add_coinvert();
    void add_coinhoriz();
    void print_coins();
    void delete_coins(int y, int x);
    int return_counter();
protected:
    lartifact coin;
    bool second, last_one;
    int posX2, posY2, tmpY, tmpX, id_room, tmpY2, tmpX2, counter;
};
coins :: coins (WINDOW* win, int y, int x, char c, int y2, int x2, int id) : artifact(win, y,x,c) {
    posY2=y2;
    posX2=x2;
    coin = NULL;
    id_room = id;
    tmpY=posY;
    tmpX=posX;
    tmpY2=posY2;
    tmpX2=posX2;
    counter=0;
}

void coins :: add_coinsquare(int i){
    lartifact node = new artifact_list;
    if (second){
        node->ay = tmpY2;
        node->ax = tmpX2;
        if (i==0){
            tmpY2++;
        }
        else if (i==1){
            tmpX2++;
        }
        else{
            tmpY2--;
        }
    }
    else{
        node->ay = tmpY;
        node->ax = tmpX;
        if (i==0){
            tmpY++;
        }
        else if (i==1){
            tmpX++;
        }
        else{
            tmpY--;
        }
    }
        node->next = coin;
        coin = node;
}

void coins :: add_coinvert(){
    lartifact node = new artifact_list;
    if (second){
        node->ay = tmpY2;
        node->ax = tmpX2;
        tmpY2++;
    }
    else{
        node->ay = tmpY;
        node->ax = tmpX;
        tmpY++;
    }
    node->next = coin;
    coin = node;
}
void coins :: add_coinhoriz(){
    lartifact node = new artifact_list;
    if (second){
        node->ay = tmpY2;
        node->ax = tmpX2;
        tmpX2++;
    }
    else {
        node->ay = tmpY;
        node->ax = tmpX;
        tmpX++;
    }
    node->next = coin;
    coin = node;
}
void coins :: all_coins() {
    if (id_room == 0){      //in base all'id ho diversi modi per far spawnare le coins
        for (int i=0; i<4; i++){
            add_coinsquare(i);      //a quadrato
        }
        second = true;      //serve a far due gruppi di monete nella stessa mappa
        for (int j=0; j<5; j++){
            add_coinvert();     //verticali
        }
        tmpY=posY;
    }
    if (id_room == 1){
        for (int i=0; i<6; i++){
            add_coinvert();
        }
        second = true;
        for (int j=0; j<4; j++){            //sempre minore di 4 dev'essere se c'è square
            add_coinsquare(j);
        }
        tmpX=posX;
    }
    if (id_room == 2){
        for (int i=0; i<9; i++){
            add_coinhoriz();            //orizzontali
        }
        second = true;
        for (int j=0; j<5; j++){
            add_coinvert();
        }
    }
    if (id_room == 3){
        for (int i=0; i<4; i++){
            add_coinsquare(i);
        }
        second = true;
        for (int j=0; j<5; j++){
            add_coinhoriz();
        }
    }
    second = false;
}
void coins ::print_coins() {
    lartifact tmp = coin;
    if(last_one){
        counter++;
        mvwaddch(window, coin->ay, coin->ax, ' ');
        remove = true;
    }
    else{
        while (tmp!=NULL){
            mvwaddch(window, tmp->ay, tmp->ax, 'c');
            tmp = tmp->next;
        }
    }
}
void coins ::delete_coins(int y, int x) {
    if (coin->next == NULL){
        if (coin->ay == y && coin->ax == x){
            last_one=true;
        }
    }
    else{
        bool check;
        lartifact current = coin;
        lartifact previous = coin;
        if (coin->ay == y && coin->ax == x){
            coin = coin->next;
            delete current;
            current = coin;
            previous = coin;
            check=true;
            counter++;
        }
        while (current!=NULL && !check){
            if (current->ay == y && current->ax == x){
                check=true;
                previous->next = current->next;
                delete current;
                current = previous->next;
                counter++;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
    }
}
int coins :: return_counter(){
    return counter;
}