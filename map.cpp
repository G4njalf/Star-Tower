#include"map.hpp"
#include"utility.hpp"
#include<iostream>
#include<thread>
using namespace std;

//actual
Pwindow acroom;  // stanza
terminal acsizet; // grandezza della stanza
door acporta;
int aclayout; //tipo di layout

struct mappa
{
    Room val = Room(acroom,acsizet,aclayout,acporta);
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

int main()
{
    //inizializzo lib
    init();
    //assegno dimensioni stanza
    acsizet.columns = 80;
    acsizet.rows = 24;
    //Room Room1 = Room(room,sizet,0,porta);
    //Roompa.borders();

    pmappa head = NULL;
    head = tail_insert(head,StanzaRandom());
    head->val.draw();
    int counter = 1; //conta quante stanze
    int maxStanze = 5; //massimo numero di stanze
    //main cycle
    while (true)
    {   
        int ch =  getch();
        if (ch == 'v')
        {
            break;
        }
        
        if (ch == 'a') // torno indietro nella mappa
        {
            if (head->prev != NULL)
            {
                head->prev->val.draw();
            }
            else
            {
                ch = getch();
            }
        }
        if (ch == 's') //vado avanti nella mappa
        {
            if (counter < maxStanze && head->next == NULL)
            {
                head = tail_insert(head,StanzaRandom());
                head->val.draw();
                counter++;
            }
            else if (head->next != NULL)
            {
                head->next->val.draw();
            }
            if (counter >= maxStanze)
            {
                ch = getch();
            }
        }      
    }
    

    cout<<counter;


    int end = getch();
    while (end == 'v')
    {
        reset();
        break;
    }
    
    reset();
    
}