#include <ncurses.h>
#include "Nemici.hpp"

using namespace std;
class personaggio {
private:
    int currX, currY;
    int xMax, yMax;
    char carattere;
    int vita = 100;
    WINDOW * window;
public:
    personaggio(int y, int x, char c, WINDOW * win) {
        window = win;
        getmaxyx (window, yMax, xMax);
        currX = x;
        currY = y;
        carattere = c;
    }
    void su(){
        mvwaddch (window, currY, currX, ' ');
        currY--;
        if(currY == 0){
            currY = 1;
            refresh();
        }
    }
    void giu(){
        mvwaddch (window, currY, currX, ' ');
        currY++;
        if(currY == 19){
            currY = 18;
            refresh();
        }
    }
    void destra(){
        mvwaddch (window, currY, currX, ' ');
        currX++;
        if (currX == 49){
            currX = 48;
            refresh();
        }
    }
    void sinistra(){
        mvwaddch (window, currY, currX, ' ');
        currX--;
        if (currX == 0){
            currX = 1;
            refresh();
        }
    }
    int muovi(){
        int movimento = wgetch(window);     //
        switch (movimento) {
            case 'w':
                su();
                break;
            case 's':
                giu();
                break;
            case 'd':
                destra();
                break;
            case 'a':
                sinistra();
                break;
            default:
                break;
        }
        return movimento;
    }
    void disegna (){
        mvwaddch (window, currY, currX, carattere);
    }
    int cy (){                  //ritorna la posizione attuale nelle y
        return currY;
    }
    int cx (){                  //ritorna la posizione attuale nelle x
        return currX;
    }
    int cl (){                              //mi ritorna il valore della vita attuale
        return vita;
    }
    void colpito(int y, int x, int dannobomba, nemico b) {
        if (y==currY && x-1==currX || y==currY && x+1==currX || y-1==currY && x==currX || y+1==currY && x==currX || currX == x && currY == y) {
            b.esplode(window);            //vede se la bomba e il pers hanno la stessa posizione
            vita = vita - dannobomba;
        }
    }
    void power1 (int b){
            vita = vita + b;
    }
    void sparosu(){
        int tmp = currY;
        for (int i=0; i<5; i++){
            currY--;
            if (currY == 1){
                mvwaddch (window, currY, currX, '"');
                refresh();
                i = 5;
            }
            if (i<4) {
                mvwaddch(window, currY, currX, ACS_UARROW);
                napms(100);
                mvwprintw(window, currY, currX, " ");
            }
            mvwaddch(window, currY, currX, ACS_UARROW);
            napms(100);
            mvwprintw(window, currY, currX, " ");
        }
        currY=tmp;
        move (currY, currX);
    }
    void sparogiu(){
        int tmp = currY;
        for (int i=0; i<5; i++){
            currY++;
            if (currY == 18){
                mvwaddch (window, currY, currX, '"');
                refresh();
                i = 5;
            }
            if (i<4) {
                mvwaddch(window, currY, currX, ACS_DARROW);
                napms(500);
                mvwprintw(window, currY, currX, " ");
            }
            mvwaddch(window, currY, currX, ACS_DARROW);
            napms(500);
            mvwprintw(window, currY, currX, " ");
        }
        currY = tmp;
        move (currY, currX);
    }
    void sparodx(){
        int tmp = currX;
        for (int i=0; i<5; i++){
            currX++;
            if (currX == 48){
                mvwaddch (window, currY, currX, '"');
                refresh();
                i = 5;
            }
            if (i<4){
                mvwaddch(window, currY, currX, ACS_RARROW);
                napms(500);
                mvwprintw(window, currY, currX, " ");
            }
            mvwaddch(window, currY, currX, ACS_RARROW);
            napms(500);
            mvwprintw(window, currY, currX, " ");
        }
        currX = tmp;
        move (currY, currX);
    }
    void sparosx(){
        int tmp = currX;
        for (int i=0; i<5; i++){
            currX--;
            if (currX == 1){
                mvwaddch (window, currY, currX, '"');
                refresh();
                i = 5;
            }
            if (i<4){
                mvwaddch(window, currY, currX, ACS_LARROW);
                napms(100);
                mvwprintw(window, currY, currX, " ");
            }
            mvwaddch(window, currY, currX, ACS_LARROW);
            napms(100);
            mvwprintw(window, currY, currX, " ");
        }
        currX = tmp;
        move (currY, currX);
    }
    int spara(){
        int sparo = wgetch(window);
        switch (sparo) {
            case KEY_UP:
                sparosu();
                break;
            case KEY_DOWN:
                sparogiu();
                break;
            case KEY_RIGHT:
                sparodx();
                break;
            case KEY_LEFT:
                sparosx();
                break;
            default:
                break;
        }
        return sparo;
    }
};