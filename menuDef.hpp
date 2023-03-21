#include <iostream>
#include <cstring>
#include <ncurses.h>
#define length 25

class menu1{
protected:
    bool options, newgame, exit;
    int  current;
    char stringm1[length], stringm2[length], stringm3[length], stringm4[length];
    int push;
    WINDOW* win;
public:
    menu1(int c, WINDOW* w);

    void position();
    void titolo();
    void disegna1();
    void muovi1(WINDOW* window);
    bool return_opzioni();
    bool return_newgame();
    bool return_exit();
    void cancella();
};

class menu2 : public menu1{
protected:
    bool facile, normale, difficile, effettion, effettioff, options = true;
    char string1[length], string2[length], string3[length], string4[length], string5[length], string6[length];
    char string7[length], string8[length];
public:
    menu2(int curr, WINDOW* window);

    void position2();
    void disegna2();
    void muovi2();
    bool return_effetti();
    bool return_difficile();
    bool return_facile();
    bool return_normale();
};

void colorii();
void inizioo();
bool menu ();