#include"map.hpp"
#include"utility.hpp"
#include<iostream>
#include<thread>
#include"menu_T.hpp"
#include"main_personaggio_test_player.hpp"
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
        if (where == true) //vai a sinistra
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
    acsizet.columns = 80;
    acsizet.rows = 24;
    int counter = 1; //conta quante stanze
    int maxStanze = 20; //massimo numero di stanze
    int profondita = 0; //profondita dell albero della mappa
    int id = 0; //identificatore
    bool where;
    pmappaAlbero head = NULL;
    Pwindow room = newwin(acsizet.rows,acsizet.columns,0,0);
    head = create(head,StanzaRandom(1,0,room),where,id);
    head->val.draw();
    mvaddstr(21,1,"first");
    wrefresh(room);
    player(room,head->val.getcoordinates(),head->val.layout);
    //main cycle
    while (!exit) // !exit con menu // true senza menu
    {   
        if (changemap(head->val.layout,getcury(room),getcurx(room)) == 0) // torno indietro nella mappa
        {
            if (head->parent != NULL)
            {
                head = head->parent;
                head->val = Stanzatest(1,0,room,head->val.layout);
                head->val.draw();
                mvwaddstr(room,21,1,"0a");
                wrefresh(room);
                profondita--;
                mvwprintw(room,22,1,"%d",profondita);
                player(room,head->val.getcoordinates(),head->val.layout);
            }
            else
            {
                mvaddstr(21,1,"0b");
                wrefresh(room);
                player(room,head->val.getcoordinates(),head->val.layout);
            }
        }
        if (changemap(head->val.layout,getcury(room),getcurx(room)) == 1) //vado avanti nella mappa A SINISTRA
        {
            if (counter < maxStanze && head->left == NULL)
            {
                where = true;
                room = newwin(acsizet.rows,acsizet.columns,0,0);
                head = create(head,StanzaRandom(1,0,room),where,id+1);
                head->val.draw();
                mvaddstr(21,1,"1a");
                wrefresh(room);
                player(room,head->val.getcoordinates(),head->val.layout);
                counter++;
                profondita++;
            }
            else if (head->left != NULL)
            {
                head = head->left;
                head->val.draw();
                mvaddstr(21,1,"1b");
                wrefresh(room);
                player(room,head->val.getcoordinates(),head->val.layout);
                profondita++;
            }
            if (counter >= maxStanze)
            {
                mvaddstr(21,1,"1c");
                wrefresh(room);
                player(room,head->val.getcoordinates(),head->val.layout);
            }
        }
        if (changemap(head->val.layout,getcury(room),getcurx(room)) == 2) //vado avanti nella mappa A DESTRA
        {
            if (counter < maxStanze && head->right == NULL)
            {
                where = false;
                room = newwin(acsizet.rows,acsizet.columns,0,0);
                head = create(head,StanzaRandom(1,0,room),where,id+1);
                head->val.draw();
                mvaddstr(21,1,"2a");
                wrefresh(room);
                player(room,head->val.getcoordinates(),head->val.layout);
                counter++;
                profondita++;
            }
            else if (head->right != NULL)
            {
                head = head->right;
                head->val.draw();
                mvaddstr(21,1,"2b");
                wrefresh(room);
                player(room,head->val.getcoordinates(),head->val.layout);
                profondita++;
            }
            if (counter >= maxStanze)
            {
                mvaddstr(21,1,"2c");
                wrefresh(room);
                player(room,head->val.getcoordinates(),head->val.layout);
            }
        }      
    }
    cout<<counter<<profondita<<aclayout;
    

    int end = getch();
    while (end == 'v')
    {
        reset();
        break;
    }
    
    reset();
    
}