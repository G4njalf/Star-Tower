#include"map.hpp"
#include<thread>

Pwindow room;  // stanza
terminal sizet; // grandezza della stanza
door porta; //dati porte
int layout; //tipo di layout

void init()
{
    initscr();
    noecho();
    cbreak();
}

void reset()
{
    endwin();
}

struct mappa
{
    Room val = Room(room,sizet,layout,porta);
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
    init();
    sizet.columns = 80;
    sizet.rows = 24;
    porta.isOpen = false;
    Room Roompa = Room(room,sizet,0,porta);
    //Roompa.borders();
    int ch = getch();
    while (ch == 'v')
    {
        reset();
        break;
    }
    
    reset();
    
}