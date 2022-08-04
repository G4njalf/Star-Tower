#include"map.hpp"
#include"utility.hpp"
#include<iostream>
#include<thread>
#include"menuTURRO.hpp"
using namespace std;

//actual
Pwindow acroom;  // stanza
terminal acsizet; // grandezza della stanza
door acporta;
int aclayout; //tipo di layout
int acId;

struct mappa
{
    Room val = Room(acroom,acsizet,aclayout,acporta,acId);
    mappa* next;
    mappa* prev;
};

typedef mappa *pmappa;

pmappa tail_insert(pmappa head, Room el)
{
    pmappa tmphead;
    tmphead = new mappa;
    if (head == NULL)
    {
        head = new mappa;
        head->prev = NULL;
        head->next = NULL;
        head->val = el; // associazione elemento cosi?
        return head;
    }
    else
    {
        tmphead->val = el;
        tmphead->prev = head;
        tmphead->next = NULL;
        head->next = tmphead;
        return tmphead;
    }
}

struct mappaAlbero
{
    Room val = Room(acroom,acsizet,aclayout,acporta,acId);
    mappaAlbero* left;
    mappaAlbero* right;
    mappaAlbero* parent;
};

typedef mappaAlbero* pmappaAlbero;

pmappaAlbero create(pmappaAlbero radix, Room el, bool where)
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
        }
        else
        {
            tmpradix->val = el; // vai a destra
            tmpradix->left = NULL;
            tmpradix->right = NULL;
            tmpradix->parent = radix;
            radix->right = tmpradix;
        }  
        return tmpradix;
    }
}


int main()
{
    bool exit = menu(); //commentare per togliere il menu
    //inizializzo lib
    init();
    //assegno dimensioni stanza
    acsizet.columns = 80;
    acsizet.rows = 24;
    int counter = 1; //conta quante stanze
    int maxStanze = 20; //massimo numero di stanze
    int profondita = 0; //profondita dell albero della mappa

    //main cycle
    while (!exit) // !exit con menu // true senza menu
    {   
        bool where;
        pmappaAlbero head = NULL;
        head = create(head,StanzaRandom(0,0),where);
        head->val.draw();
      
        int ch =  getch();
        if (ch == 'v')
        {
            break;
        }
        
        if (ch == 'w') // torno indietro nella mappa
        {
            if (head->parent != NULL)
            {
                head = head->parent;
                head->val.draw();
                //head = head->prev;
                profondita--;
            }
            else
            {
                ch = getch();
            }
        }
        if (ch == 'q') //vado avanti nella mappa A SINISTRA
        {
            if (counter < maxStanze && head->left == NULL)
            {
                where = true;
                head = create(head,StanzaRandom(0,0),where);
                head->val.draw();
                counter++;
                profondita++;
            }
            else if (head->left != NULL)
            {
                head = head->left;
                head->val.draw();
                profondita++;
            }
            if (counter >= maxStanze)
            {
                ch = getch();
            }
        }
        if (ch == 'e') //vado avanti nella mappa A DESTRA
        {
            if (counter < maxStanze && head->right == NULL)
            {
                where = false;
                head = create(head,StanzaRandom(0,0),where);
                head->val.draw();
                counter++;
                profondita++;
            }
            else if (head->right != NULL)
            {
                head = head->right;
                head->val.draw();
                profondita++;
            }
            if (counter >= maxStanze)
            {
                ch = getch();
            }
        }      
    }
    

    cout<<counter<<profondita;
    

    int end = getch();
    while (end == 'v')
    {
        reset();
        break;
    }
    
    reset();
    
}