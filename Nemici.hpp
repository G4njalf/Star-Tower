#include <ncurses.h>
#include <ctime>

using namespace std;
class nemico {
private:
    int danno;
    int posY;
    int posX;
    char carattere;
public:
    nemico(char c, int d, int y, int x) {
        posY = y;
        posX = x;
        carattere = c;
        danno = d;
    }

    void esplode(WINDOW *win) {                    //colora lo bomba di rosso se triggerata
        mvwprintw(win, posY, posX, " ");
        napms(500);
        wrefresh(win);

        attron(COLOR_PAIR(1));                 // o almeno dovrebbe, ma non funziona dio cane
        mvwprintw(win, posY, posX, "x");
        attroff(COLOR_PAIR(1));
        wrefresh(win);
        napms(500);

        mvwprintw(win, posY, posX, " ");        //alterno gli spazi vuoti con i simboli per simulare l'esplosione
        wrefresh(win);
        napms(500);

        attron(COLOR_PAIR(1));
        mvwprintw(win, posY, posX, "X");        // problema legato all'attesa, non ci si puo muovere quanto si attiva
        attroff(COLOR_PAIR(1));
        wrefresh(win);
        napms(500);

        mvwprintw(win, posY, posX, " ");
        wrefresh(win);
        napms(500);
    }

    void disegna(WINDOW *win) {
        mvwaddch(win, posY, posX, carattere);
    }

    int dannobomba() {
        return danno;
    }

    int cy() {                  //ritorna la posizione attuale nelle y
        return posY;
    }

    int cx() {                  //ritorna la posizione attuale nelle x
        return posX;
    }
    /* void colpito(int y, int x, int vita, WINDOW * win) {
        if (y==posY && x-1==posX || y==posY && x+1==posX || y-1==posY && x==posX || y+1==posY && x==posX) {
            esplode(y, x, win);            //vede se la bomba e il pers hanno la stessa posizione, se si la bomba
            vita = vita - danno;        //danneggia il giocatore
        }
    }*/
};

    class lanciabomba : public nemico{
    private:
        int lancioY, lancioX;
    public:
        lanciabomba(char c, int d, int y, int x) : nemico (c, d, y, x){}

        void disegna(WINDOW * win){
            mvwaddch (win, cy(), cx(), ACS_BLOCK);
            wrefresh(win);
        }

        void muovi(WINDOW * win){
            int x=cx();
            int y=cy();
            int origx = x;
            int origy = y;
            int uno=0;
            int zero=0;
            srand(10);
            while (getch()!='x'){
                for (int i=0; i<7; i++){
                    int random = rand()%2;
                    mvwaddch (win, y, x, ACS_BLOCK);
                    wrefresh(win);
                    if (random == 0){
                        zero++;
                        mvwaddch (win, y, x, ' ');
                        x++;
                        mvwaddch (win, y, x, ACS_BLOCK);
                        wrefresh(win);
                        napms(200);
                    }
                    if (random == 1){
                        uno++;
                        mvwaddch (win, y, x, ' ');
                        y++;
                        mvwaddch (win, y, x, ACS_BLOCK);
                        wrefresh(win);
                        napms(200);
                    }
                }
                    for (int j=0; j!=zero; j++){
                        mvwaddch (win, y, x, ' ');
                        x--;
                        mvwaddch (win, y, x, ACS_BLOCK);
                        wrefresh(win);
                        napms(200);
                    }
                    for (int m=0; m<uno; m++){
                        mvwaddch (win, y, x, ' ');
                        y--;
                        mvwaddch (win, y, x, ACS_BLOCK);
                        wrefresh(win);
                        napms(200);
                    }

                    if (getch()=='x'){
                        return;
                    }
                }
            }
};


