#include"mapDef.hpp"
#include"utility.hpp"
#include<iostream>
#include<thread>
#include"menuDef.hpp"
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


void map(bool exit, int life, int score)
{
    //inizializzo lib
    init();
    //assegno dimensioni stanza
    WINDOW* win = newwin (20, 50, 0, 0);
    refresh();
    box (win, 0, 0);
    wrefresh(win);
    keypad(win, TRUE);

  /*  menu1 *home=new menu1(1, win);
    menu2 *opzioni=new menu2(1, win);
    home->titolo();
    while(!home->return_exit() && !home->return_newgame()){
        if(!opzioni->return_opzioni()){
            werase(win);
            wrefresh(win);
            box (win, 0, 0);
            home->disegna1();
            home->muovi1(win);
        }
        if(home->return_opzioni()){
            werase(win);
            wrefresh(win);
            box (win, 0, 0);
            opzioni->disegna2();
            opzioni->muovi2();
        }
    }
    if(home->return_exit()){
        delete opzioni;
        delete home;
        clear();
        refresh();
        endwin();
    }
    if(home->return_newgame()){
        delete opzioni;
        delete home;
        clear();
        refresh();*/

        acsizet.columns = 80;
        acsizet.rows = 24;
        int counter = 1; //conta quante stanze
        int maxStanze = 20; //massimo numero di stanze
        int profondita = 0; //profondita dell albero della mappa
        int id = 0; //identificatore
        bool where;
        pmappaAlbero head = NULL;
        Pwindow stats = newwin(5, 80, 23, 0);   //stats e' la mappa che mostra le statistiche
        Pwindow room = newwin(acsizet.rows,acsizet.columns,0,0);
        head = create(head,StanzaRandom(1,0,room),where,id);
        head->val.draw(stats);
        mvwaddstr(room,21,1,"first");
        wrefresh(room);
        wrefresh(stats);
        //player(room,head->val.getcoordinatesP(),head->val.layout);
        gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
    //main cycle
    while (!exit) // !exit con menu // true senza menu // gestire il gameover
    {   
        if (changemap(head->val.layout,getcury(room),getcurx(room)) == 0) // torno indietro nella mappa
        {
            if (head->parent != NULL)
            {
                head = head->parent;
                head->val = Stanza(1,0,room,head->val.layout); //aggiorno la stanza con quella padre
                head->val.draw(stats);
                mvwaddstr(room,21,1,"0a");
                wrefresh(room);
                wrefresh(stats);
                profondita--;
                gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
                //player(room,head->val.getcoordinatesP(),head->val.layout);
            }
            else
            {
                mvaddstr(21,1,"0b");
                wrefresh(room);
                gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
                //player(room,head->val.getcoordinatesP(),head->val.layout);
            }
        }
        if (changemap(head->val.layout,getcury(room),getcurx(room)) == 1) //vado avanti nella mappa A SINISTRA
        {
            if (counter < maxStanze && head->left == NULL)
            {
                where = true;
                room = newwin(acsizet.rows,acsizet.columns,0,0);
                head = create(head,StanzaRandom(1,0,room),where,id+1);
                head->val.draw(stats);
                mvaddstr(21,1,"1a");
                wrefresh(room);
                wrefresh(stats);
                gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
                //player(room,head->val.getcoordinatesP(),head->val.layout);
                counter++;
                profondita++;
            }
            else if (head->left != NULL)
            {
                head = head->left;
                head->val.draw(stats);
                mvaddstr(21,1,"1b");
                wrefresh(room);
                wrefresh(stats);
                gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
                //player(room,head->val.getcoordinatesP(),head->val.layout);
                profondita++;
            }
            if (counter >= maxStanze)
            {
                mvaddstr(21,1,"1c");
                wrefresh(room);
                gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
                //player(room,head->val.getcoordinatesP(),head->val.layout);
            }
        }
        if (changemap(head->val.layout,getcury(room),getcurx(room)) == 2) //vado avanti nella mappa A DESTRA
        {
            if (counter < maxStanze && head->right == NULL)
            {
                where = false;
                room = newwin(acsizet.rows,acsizet.columns,0,0);
                head = create(head,StanzaRandom(1,0,room),where,id+1);
                head->val.draw(stats);
                mvaddstr(21,1,"2a");
                wrefresh(room);
                wrefresh(stats);
                gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
                //player(room,head->val.getcoordinatesP(),head->val.layout);
                counter++;
                profondita++;
            }
            else if (head->right != NULL)
            {
                head = head->right;
                head->val.draw(stats);
                mvaddstr(21,1,"2b");
                wrefresh(room);
                wrefresh(stats);
                gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
                //player(room,head->val.getcoordinatesP(),head->val.layout);
                profondita++;
            }
            if (counter >= maxStanze)
            {
                mvaddstr(21,1,"2c");
                wrefresh(room);
                gioco(room,stats,head->val.layout,head->val.getcoordinatesP(),head->val.getcoordinatesE1(),head->val.getcoordinatesE2(),head->val.getcoordinatesE3(), life, score);
                //player(room,head->val.getcoordinatesP(),head->val.layout);
            }
        }      
    }
   // }
}