#include "artifacts.hpp"
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
void artifact ::canttake() {    //non hai gli score sufficienti per raccoglierlo
    remove = false;
}
void artifact :: clear() {
    mvwaddch(window, posY, posX, ' ');
}
void artifact :: its_removed(){
    remove = true;
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

key :: key(WINDOW* win, int y, int x, char c):artifact(win, y, x, c){}

bool key ::return_used_right() {
    return used_right;
}
bool key:: return_used_left(){
    return used_left;
}
void key:: print_key_if_necessary(int layout, int vita_e1, int vita_e2, int vita_e3){
    if(vita_e1<=0 && vita_e2<=0 && vita_e3<=0 && !taken){
        if(layout==0){
            posY=14;
            posX=7;
            mvwaddch(window, posY, posX, 'K');
        }
        else if (layout==1){
            posY=12;
            posX=59;
            mvwaddch(window, posY, posX, 'K');
        }
        else if (layout==2){
            posY=20;
            posX=61;
            mvwaddch(window, posY, posX, 'K');
        }
        else if (layout==3){
            posY=13;
            posX=57;
            mvwaddch(window, posY, posX, 'K');
        }
    }
}
bool key :: return_taken(){
    return taken;
}
void key :: taken_true(){
    taken=true;
}
void key :: used_right_true(){
    used_right=true;
}
void key:: used_left_true(){
    used_left=true;
}
void key::open_door_if_necessary(int layout, int Py, int Px){
    if(taken){
        //controllo per aprire porta destra
        if(layout==0 && !used_right){
            if(Px>=69 && Py<13 && Py>9){
                mvwaddch(window,10,71,' ');
                mvwaddch(window,11,71,' ');
                mvwaddch(window,12,71,' ');
                mvwaddch(window,12,71,'_');
                used_right=true;
            }
        }
        else if(layout==1 && !used_right){
            if(Py>18 && Px>44 && Px<52){
                mvwaddch(window,20,46,' ');
                mvwaddch(window,20,47,' ');
                mvwaddch(window,20,48,' ');
                mvwaddch(window,20,49,' ');
                mvwaddch(window,20,50,' ');
                mvwaddch(window,20,51,' ');
                used_right=true;
            }

        }
        else if(layout==2 && !used_right){
            if(Px>68){
                mvwaddch(window,13,70,' ');
                mvwaddch(window,14,70,' ');
                mvwaddch(window,15,70,' ');
                mvwaddch(window,15,70,'_');
                used_right=true;
            }

        }
        else if(layout==3 && !used_right){
            if(Py>18 && Px>35 ){
                mvwaddch(window,20,37,' ');
                mvwaddch(window,20,38,' ');
                mvwaddch(window,20,39,' ');
                mvwaddch(window,20,40,' ');
                mvwaddch(window,20,41,' ');
                mvwaddch(window,20,42,' ');
                used_right=true;
            }
        }
        if(layout==0 && used_right){
            mvwaddch(window,10,71,' ');
            mvwaddch(window,11,71,' ');
            mvwaddch(window,12,71,' ');
            mvwaddch(window,12,71,'_');

        }
        else if(layout==1 && used_right){
            mvwaddch(window,20,46,' ');
            mvwaddch(window,20,47,' ');
            mvwaddch(window,20,48,' ');
            mvwaddch(window,20,49,' ');
            mvwaddch(window,20,50,' ');
            mvwaddch(window,20,51,' ');

        }
        else if(layout==2 && used_right){
            mvwaddch(window,13,70,' ');
            mvwaddch(window,14,70,' ');
            mvwaddch(window,15,70,' ');
            mvwaddch(window,15,70,'_');

        }
        else if(layout==3 && used_right){
            mvwaddch(window,20,37,' ');
            mvwaddch(window,20,38,' ');
            mvwaddch(window,20,39,' ');
            mvwaddch(window,20,40,' ');
            mvwaddch(window,20,41,' ');
            mvwaddch(window,20,42,' ');

        }

        //controlli per porta sinistra

        if(layout==0 && !used_left){
            if(Px>=20 && Px<=27 && Py==18 && Py>9){
                mvwaddch(window,19,21,' ');
                mvwaddch(window,19,22,' ');
                mvwaddch(window,19,23,' ');
                mvwaddch(window,19,24,' ');
                mvwaddch(window,19,25,' ');
                mvwaddch(window,19,26,' ');

                used_left=true;
            }
        }
        else if(layout==1 && !used_left){
            if(Py>14 && Px==11 && Py<19){
                mvwaddch(window,15,10,' ');
                mvwaddch(window,16,10,' ');
                mvwaddch(window,17,10,' ');
                used_left=true;
            }
        }
        else if(layout==2 && !used_left){
            if(Py>9 && Py<15 && Px==7){
                mvwaddch(window,10,6,' ');
                mvwaddch(window,11,6,' ');
                mvwaddch(window,12,6,' ');
                mvwaddch(window,12,6,'_');
                used_left=true;
            }
        }
        else if(layout==3 && !used_left){
            if(Py>16 && Py<20 && Px==7 ){
                mvwaddch(window,17,6,' ');
                mvwaddch(window,18,6,' ');
                mvwaddch(window,19,6,' ');
                used_left=true;
            }
        }
        //controlli: se la porta sinistra è già stata aperta, cancella le x che sbarrano la strada
        if(layout==0 && used_left){
            mvwaddch(window,19,21,' ');
            mvwaddch(window,19,22,' ');
            mvwaddch(window,19,23,' ');
            mvwaddch(window,19,24,' ');
            mvwaddch(window,19,25,' ');
            mvwaddch(window,19,26,' ');
        }
        else if(layout==1 && used_left){
            mvwaddch(window,15,10,' ');
            mvwaddch(window,16,10,' ');
            mvwaddch(window,17,10,' ');
        }
        else if(layout==2 && used_left){
            mvwaddch(window,10,6,' ');
            mvwaddch(window,11,6,' ');
            mvwaddch(window,12,6,' ');
            mvwaddch(window,12,6,'_');
        }
        else if(layout==3 && used_left){
            mvwaddch(window,17,6,' ');
            mvwaddch(window,18,6,' ');
            mvwaddch(window,19,6,' ');

        }

    }
}

coins :: coins (WINDOW* win, int y, int x, char c, int y2, int x2, int id, lartifact co) : artifact(win, y,x,c) {
    posY2=y2;
    posX2=x2;
    coin = co;
    id_room = id;
    tmpY=posY;
    tmpX=posX;
    tmpY2=posY2;
    tmpX2=posX2;
    counter=0;
}
void coins :: add_coinsquare(int i){    //creo i vari layout di spawn, qua faccio un quadrato 2x2
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
            add_coinsquare(i);
        }
        second = true;      //serve a far due gruppi di monete nella stessa mappa
        for (int j=0; j<5; j++){
            add_coinvert();
        }
        tmpY=posY;
    }
    if (id_room == 1){
        for (int i=0; i<6; i++){
            add_coinvert();
        }
        second = true;
        for (int j=0; j<4; j++){            //se c'è square j dev'essere sempre minore di 4
            add_coinsquare(j);
        }
        tmpX=posX;
    }
    if (id_room == 2){
        for (int i=0; i<9; i++){
            add_coinhoriz();
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
        if (coin->ay == y && coin->ax == x){    //controllo se c'è solo una moneta, nel caso attivo il booleano
            last_one=true;
        }
    }
    else{
        bool check;
        lartifact current = coin;
        lartifact previous = coin;
        if (coin->ay == y && coin->ax == x){
            delone = true;
            coin = coin->next;
            delete current;
            current = coin;
            previous = coin;
            check=true;
            counter++;
        }
        while (current!=NULL && !check){
            if (current->ay == y && current->ax == x){
                delone = true;
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
bool coins ::return_delone() {
    return delone;
}
int coins :: return_counter(){
    return counter;
}
lartifact coins ::return_currlist() {
    return coin;
}
void coins :: change_list(lartifact newcoin){
    coin  = newcoin;
}