#include <ncurses.h>

typedef WINDOW *Pwindow;

class personaggio {
protected:
    int currX, currY;
    int xMax, yMax;
    char carattere;
    Pwindow window;
    int vita;
public:
    personaggio(int y, int x, char c, Pwindow win) {
        vita = 100;
        window = win;
        getmaxyx(win, yMax, xMax);
        currX = x;
        currY = y;
        carattere = c;
    }

    void su() {
        currY--;
        if (mvwinch(window, currY, currX)!=32||currY==0) {              //se e' diverso dallo spazio vuoto non si muove
            currY++;
            refresh();
        }
    }

    void giu() {
        currY++;
        if (mvwinch(window, currY, currX)!=32||currY==23) {
            currY--;
            refresh();
        }
    }

    void destra() {
        currX++;
        if (mvwinch(window, currY, currX)!=32||currX==79) {
            currX--;
            refresh();
        }
    }

    void sinistra() {
        currX--;
        if (mvwinch(window, currY, currX)!=32||currX==0) {
            currX++;
            refresh();
        }
    }

    int muovi(int movimento) {
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
            case 'W':
                su2();
                break;
            case 'S':
                giu2();
                break;
            case 'D':
                destra2();
                break;
            case 'A':
                sinistra2();
                break;
        }
        return movimento;
    }

    void disegna() {
        mvwaddch(window, currY, currX, carattere);
        wrefresh(window);
    }
    void cancella(){
        mvwaddch(window, currY, currX, ' ');
        wrefresh(window);
    }
    int cy() {                  //ritorna la posizione attuale nelle y
        return currY;
    }

    int cx() {                  //ritorna la posizione attuale nelle x
        return currX;
    }

    int cl() {                              //mi ritorna il valore della vita attuale
        return vita;
    }

    void su2() {
        int tmp = currY;
        bool controllo;
        for (int j=3; j>0; j--){
            if(tmp==j){
                controllo=true;
            }
        }
        if(!controllo){
            for (int i=0; i<3; i++) {
                tmp--;
                if (mvwinch(window, tmp, currX) == 95 || mvwinch(window, tmp, currX) == 124) {
                    i = 5;
                }
                else {
                    mvwaddch(window, currY, currX, ' ');
                    currY--;
                    mvwaddch(window, currY, currX, 'o');
                    wrefresh(window);
                    napms(100);
                }
            }
        }
    }

    void giu2() {
        int tmp = currY;
        bool controllo;
        for (int j=20; j<24; j++){
            if(tmp==j){
                controllo=true;
            }
        }
        if(!controllo){
            for (int i=0; i<3; i++) {
                tmp++;
                if (mvwinch(window, tmp, currX) == 95 || mvwinch(window, tmp, currX) == 124) {
                    i = 5;
                }
                else {
                    mvwaddch(window, currY, currX, ' ');
                    currY++;
                    mvwaddch(window, currY, currX, 'o');
                    wrefresh(window);
                    napms(100);
                }
            }
        }
    }

    void destra2() {
        int tmp = currX;
        bool controllo;
        for (int j=76; j<80; j++){
            if(tmp==j){
                controllo=true;
            }
        }
        if(!controllo){
            for (int i=0; i<3; i++) {
                tmp++;
                if (mvwinch(window, currY, tmp) == 95 || mvwinch(window, currY, tmp) == 124) {
                    i = 5;
                }
                else {
                    mvwaddch(window, currY, currX, ' ');
                    currX++;
                    mvwaddch(window, currY, currX, 'o');
                    wrefresh(window);
                    napms(100);
                }
            }
        }
    }

    void sinistra2() {
        int tmp = currX;
        bool controllo;
        for (int j = 3; j > 0; j--) {
            if (tmp == j) {
                controllo = true;
            }
        }
        if (!controllo) {
            for (int i = 0; i < 3; i++) {
                tmp--;
                if (mvwinch(window, currY, tmp) == 95 || mvwinch(window, currY, tmp) == 124) {
                    i = 5;
                } else {
                    mvwaddch(window, currY, currX, ' ');
                    currX--;
                    mvwaddch(window, currY, currX, 'o');
                    wrefresh(window);
                    napms(100);
                }
            }
        }
    }
};

    class sparo : public personaggio {
    private:
        int danno;
        bool ostacolo;
    public:
        sparo (int y, int x, char c, WINDOW *window) : personaggio(y, x, c, window){
            danno = 50;
        }

        void sparosu(){
            if(currY==2){
                currY--;
                ostacolo = true;
            }
            else if (currY!=1){
                    currY--;
                    if(mvwinch(window, currY, currX)!=32){
                        currY++;
                        ostacolo = true;
                    }
            }
        }
        void sparogiu(){
            if(currY==21){
                currY++;
                ostacolo = true;
            }
            else if (currY!=22){
                    currY++;
                    if(mvwinch(window, currY, currX)!=32){
                        currY--;
                        ostacolo = true;
                    }
                }
        }
        void sparodx(){
            if(currX==77){
                currX++;
                ostacolo = true;
            }
            else if (currX!=78){
                    currX++;
                    if(mvwinch(window, currY, currX)!=32){
                        currX--;
                        ostacolo = true;
                    }
            }
        }
        void sparosx(){
            if(currX==2){
                currX--;
                ostacolo = true;
            }
            else if (currX!=1){
                    currX--;
                    if(mvwinch(window, currY, currX)!=32){
                        currX++;
                        ostacolo = true;
                    }
                }
        }
        void disegna(){
            mvwaddch(window, currY, currX,  carattere);
            wrefresh(window);
        }
        void incrementavita (int b){            //funzioni usate per l'interazione col personaggio
            vita = vita + b;
        }
        void danneggia (int d){
            vita = vita - d;
        }
        void cancella(){
            mvwaddch(window, currY, currX, ' ');
            wrefresh(window);
        }
        void cancella2(){
            mvwaddch(window, currY, currX, ' ');
            wrefresh(window);
            ostacolo = false;
        }
        bool return_ostacolo(){
            return ostacolo;
        }
};