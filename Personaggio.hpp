#include <ncurses.h>

using namespace std;
class personaggio {
private:
    int currX, currY;
    int xMax, yMax;
    char carattere;
    int vita;
    WINDOW * window;
public:
    personaggio(int y, int x, char c, int v, WINDOW * win) {
        window = win;
        getmaxyx (window, yMax, xMax);
        vita = v;
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
    int muovi() {
        int movimento = wgetch(window);             //switch che serve a rivelare il tasto premuto dal giocatore
        switch (movimento) {                        //con i primi 4 casi si esegue il movimento del personaggio
            case 'w':                               //con le KEY si spara, infine con le lettere maiuscole si fanno
                su();                               //le capriole (si incrementa il movimento di 3 e non di 1)
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
            case 'W':
                capsu();
                break;
            case 'S':
                capgiu();
                break;
            case 'D':
                capdestra();
                break;
            case 'A':
                capsinistra();
                break;
            default:
                break;
        }
        return movimento;
    }
    void disegna (){
        wattron(window, COLOR_PAIR(2));
        mvwaddch (window, currY, currX, carattere);
        wattroff(window, COLOR_PAIR(2));
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
  /*  void colpito(int y, int x, int dannobomba, nemico b) {
        if (y==currY && x-1==currX || y==currY && x+1==currX || y-1==currY && x==currX || y+1==currY && x==currX || currX == x && currY == y) {
            b.esplode(window);            //vede se la bomba e il pers hanno la stessa posizione
            vita = vita - dannobomba;
        }
    }*/
    void incrementavita (int b){
            vita = vita + b;
    }

    void danneggia (int d){
        vita = vita - d;
    }

    void sparosu(){
        if (currY != 1){
            int tmp = currY;
            for (int i=0; i<5; i++){
                currY--;
                if (currY == 2){
                    mvwaddch (window, currY, currX, '"');
                    wrefresh(window);
                    i++;
                }
                if (i!=4){
                    mvwaddch (window, currY, currX, ACS_BULLET);
                    wrefresh(window);
                    napms(80);
                    mvwprintw(window, currY, currX, " ");
                }
                else{
                    mvwprintw(window, currY, currX, "*");
                    wrefresh(window);
                    napms(80);
                    mvwprintw(window, currY, currX, " ");
                }
            }
            currY=tmp;
            move (currY, currX);
        }
    }
    void sparogiu(){
        if (currY!=18){
            int tmp = currY;
            for (int i=0; i<5; i++){
                currY++;
                if (currY == 17){
                    mvwaddch (window, currY, currX, '"');
                    refresh();
                    i = 5;
                }
                if (i!=4){
                    mvwaddch (window, currY, currX, ACS_BULLET);
                    wrefresh(window);
                    napms(80);
                    mvwprintw(window, currY, currX, " ");
                }
                else{
                    mvwprintw(window, currY, currX, "*");
                    wrefresh(window);
                    napms(80);
                    mvwprintw(window, currY, currX, " ");
                }
            }
            currY = tmp;
            move (currY, currX);
        }
    }
    void sparodx(){
        if (currX!=48){
            int tmp = currX;
            for (int i=0; i<10; i++){
                currX++;
                if (currX == 47){
                    mvwaddch (window, currY, currX, '"');
                    refresh();
                    i = 10;
                }
                if (i!=9){
                    mvwaddch (window, currY, currX, ACS_BULLET);
                    wrefresh(window);
                    napms(80);
                    mvwprintw(window, currY, currX, " ");
                }
                else{
                    mvwprintw(window, currY, currX, "*");
                    wrefresh(window);
                    napms(80);
                    mvwprintw(window, currY, currX, " ");
                }

            }
            currX = tmp;
            move (currY, currX);
        }
    }
    void sparosx(){
        if (currX!=1){
            int tmp = currX;
            for (int i=0; i<10; i++){
                currX--;
                if (currX == 2){
                    mvwaddch (window, currY, currX, '"');
                    refresh();
                    i = 10;
                }
                if (i!=9){
                    mvwaddch (window, currY, currX, ACS_BULLET);
                    wrefresh(window);
                    napms(80);
                    mvwprintw(window, currY, currX, " ");
                }
                else{
                    mvwprintw(window, currY, currX, "*");
                    wrefresh(window);
                    napms(80);
                    mvwprintw(window, currY, currX, " ");
                }
            }
            currX = tmp;
            move (currY, currX);
        }
    }
    void capsu() {
        if (currY != 0 && currY != 1 && currY != 2 && currY != 3) {
            mvwaddch(window, currY, currX, ' ');
            currY--;
            mvwaddch(window, currY, currX, 'o');
            wrefresh(window);
            napms(100);
            mvwaddch(window, currY, currX, ' ');
            currY--;
            mvwaddch(window, currY, currX, 'o');
            wrefresh(window);
            napms(100);
            mvwaddch(window, currY, currX, ' ');
            currY--;
            //   capriola = true;
        }
    }

    void capgiu() {
        if (currY != 19 && currY != 18 && currY != 17 && currY != 16) {
            mvwaddch(window, currY, currX, ' ');
            currY++;
            mvwaddch(window, currY, currX, 'o');
            wrefresh(window);
            napms(100);
            mvwaddch(window, currY, currX, ' ');
            currY++;
            mvwaddch(window, currY, currX, 'o');
            wrefresh(window);
            napms(100);
            mvwaddch(window, currY, currX, ' ');
            currY++;
            //   capriola = true;
        }
    }

    void capdestra() {
        if (currX != 49 && currX != 48 && currX != 47 && currX != 46) {
            mvwaddch(window, currY, currX, ' ');
            currX++;
            mvwaddch(window, currY, currX, 'o');
            wrefresh(window);
            napms(100);
            mvwaddch(window, currY, currX, ' ');
            currX++;
            mvwaddch(window, currY, currX, 'o');
            wrefresh(window);
            napms(100);
            mvwaddch(window, currY, currX, ' ');
            currX++;
            // capriola = true;
        }
    }

    void capsinistra() {
        if (currX != 0 && currX != 1 && currX != 2 && currX != 3) {
            mvwaddch(window, currY, currX, ' ');
            currX--;
            mvwaddch(window, currY, currX, 'o');
            wrefresh(window);
            napms(100);
            mvwaddch(window, currY, currX, ' ');
            currX--;
            mvwaddch(window, currY, currX, 'o');
            wrefresh(window);
            napms(100);
            mvwaddch(window, currY, currX, ' ');
            currX--;
            //  capriola = true;
        }
    }
};