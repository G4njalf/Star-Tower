#include"mapDef.cpp"
#include"utility.hpp"
#include<iostream>
#include"menuDef.cpp"
#include"playerEnemy.hpp"
using namespace std;

//actual
Pwindow acroom;  // stanza
terminal acsizet; // grandezza della stanza
door acporta;
int aclayout; //tipo di layout
int acId;
const int numNemici = 3; // numero nemici


struct mappaAlbero
{
    Room val = Room(acroom,acsizet,aclayout,acporta,acId);
    mappaAlbero* left;
    mappaAlbero* right;
    mappaAlbero* parent;
    int key;
    int enemies_life[3];
    bool already_added[3];
    bool nohpup;
    bool key_taken;
    bool key_used_right;
    bool key_used_left;
    bool delone;
    bool nocoins;
    bool first_map;
    bool final_map;
    lartifact monete_attive = new artifact_list;
};

typedef mappaAlbero* pmappaAlbero;

pmappaAlbero create(pmappaAlbero radix, Room el, bool where, int identificatore)
{
    pmappaAlbero tmpradix;
    tmpradix = new mappaAlbero;
    if (radix == NULL)
    {
        radix = new mappaAlbero;
        radix->val = el;
        radix->left = NULL;
        radix->right = NULL;
        radix->parent = NULL;
        radix->key = identificatore;
        return radix;
    }
    else
    {
        if (where) //vai a sinistra
        {
            tmpradix->val = el;
            tmpradix->left = NULL;
            tmpradix->right = NULL;
            tmpradix->parent = radix;
            radix->left = tmpradix;
            radix->key = identificatore;
        }
        else
        {
            tmpradix->val = el; // vai a destra
            tmpradix->left = NULL;
            tmpradix->right = NULL;
            tmpradix->parent = radix;
            radix->right = tmpradix;
            radix->key = identificatore;
        }  
        return tmpradix;
    }
}


void map(bool exit)
{
    //inizializzo lib
    init();
    //assegno dimensioni stanza
    WINDOW* win = newwin (20, 50, 0, 0);
    refresh();
    box (win, 0, 0);
    wrefresh(win);
    keypad(win, TRUE);

    int life=500;
    int score=0;
    acsizet.columns = 80;
    acsizet.rows = 24;
    int counter = 1; //conta quante stanze
    int maxStanze = 20; //massimo numero di stanze
    int profondita = 0; //profondita dell albero della mappa
    int id = rand()%4; //identificatore
    bool where;
    pmappaAlbero head = NULL;
    Pwindow stats = newwin(5, 80, 23, 0);   //stats e' la mappa che mostra le statistiche
    Pwindow room = newwin(acsizet.rows,acsizet.columns,0,0);
    head = create(head,StanzaRandom(0,0,room),where,id);
    for(int i=0; i<3;i++){
        head->enemies_life[i]=200;
    }
    head->key_taken=false;
    head->key_used_right=false;
    head->key_used_left=false;
    head->final_map=false;
    head->val.draw(stats);
    wrefresh(room);
    wrefresh(stats);
    head->first_map=true;
    int x, y;


    gioco(room,stats,head->val.layout,head->val.id,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score, head->enemies_life, head->nohpup, head->already_added, head->key_taken,head->key_used_right, head->key_used_left, head->delone, head->first_map, head->monete_attive, head->nocoins, y,x, head->final_map);
    
//main cycle
while (!exit) // !exit con menu // true senza menu // gestire il gameover
{
    if (changemap(head->val.layout,y,x) == 0) // torno indietro nella mappa
    {
        if (head->parent != NULL)
        {
            head = head->parent;
            head->val = Stanza(0,0,room,head->val.layout,head->val.id); //aggiorno la stanza con quella padre
            head->val.draw(stats);
            wrefresh(room);
            wrefresh(stats);
            profondita--;
            gioco(room,stats,head->val.layout,head->val.id,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score, head->enemies_life, head->nohpup, head->already_added, head->key_taken,head->key_used_right, head->key_used_left, head->delone, head->first_map, head->monete_attive, head->nocoins, y,x, head->final_map);
        }
    }
    if (changemap(head->val.layout,y,x) == 1) //vado avanti nella mappa A SINISTRA
    {
        if (head->left == NULL)
        {
            counter++;
            profondita++;
            where = true;
            room = newwin(acsizet.rows,acsizet.columns,0,0);
            head = create(head,StanzaRandom(0,0,room),where,id+1);
            for(int i=0; i<3;i++){
                head->enemies_life[i]=100;
            }
            head->key_taken=false;
            head->key_used_right=false;
            head->key_used_left=false;
            head->val.draw(stats);
            wrefresh(room);
            wrefresh(stats);
            head->final_map=false;
            if(counter>=maxStanze) head->final_map=true;
            gioco(room,stats,head->val.layout,head->val.id,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score, head->enemies_life, head->nohpup, head->already_added, head->key_taken,head->key_used_right, head->key_used_left, head->delone, head->first_map, head->monete_attive, head->nocoins, y,x, head->final_map);
            
        }
        else if (head->left != NULL)
        {
            head = head->left;
            head->val = Stanza(0,0,room,head->val.layout,head->val.id); //aggiorno la stanza con quella padre
            head->val.draw(stats);
            wrefresh(room);
            wrefresh(stats);
            gioco(room,stats,head->val.layout,head->val.id,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score, head->enemies_life, head->nohpup, head->already_added, head->key_taken,head->key_used_right, head->key_used_left, head->delone, head->first_map, head->monete_attive, head->nocoins, y,x, head->final_map);
            profondita++;
        }
    }
    if (changemap(head->val.layout,y,x) == 2) //vado avanti nella mappa A DESTRA
    {
        if (head->right == NULL)
        {
            counter++;
            profondita++;
            where = false;
            room = newwin(acsizet.rows,acsizet.columns,0,0);
            head = create(head,StanzaRandom(0,0,room),where,id+1);
            for(int i=0; i<3;i++){
                head->enemies_life[i]=100;
            }
            head->key_taken=false;
            head->key_used_right=false;
            head->key_used_left=false;
            head->val.draw(stats);
            wrefresh(room);
            wrefresh(stats);
            head->final_map=false;
            if(counter>=maxStanze) head->final_map=true;
            gioco(room,stats,head->val.layout,head->val.id,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score, head->enemies_life, head->nohpup, head->already_added, head->key_taken,head->key_used_right, head->key_used_left, head->delone, head->first_map, head->monete_attive, head->nocoins, y,x, head->final_map);
            
        }
        else if (head->right != NULL)
        {
            head = head->right;
            head->val = Stanza(0,0,room,head->val.layout,head->val.id); //aggiorno la stanza con quella padre
            head->val.draw(stats);
            wrefresh(room);
            wrefresh(stats);
            gioco(room,stats,head->val.layout,head->val.id,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score, head->enemies_life, head->nohpup, head->already_added, head->key_taken,head->key_used_right, head->key_used_left, head->delone, head->first_map, head->monete_attive, head->nocoins, y,x, head->final_map);
            profondita++;
        }
    }
    if(life<=0){
        exit = true;
    }
}
wclear(room);
wclear(stats);
wrefresh(room);
wrefresh(stats);

gameover();
}