#include <ncurses.h>
#include <ctime>

class nemico {
protected:
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

};
    class mina : public nemico{
    public:
        mina(char c, int d, int y, int x) : nemico (c, d, y, x){}
        bool colpito(personaggio p, int y, int x, WINDOW * win) {
            bool controllo=false;
            if (y==posY && x-1==posX || y==posY && x+1==posX || y-1==posY && x==posX || y+1==posY && x==posX) {
                beep();
                esplode(win);            //vede se la bomba e il pers hanno la stessa posizione, se si la bomba
                p.danneggia(danno);
                controllo=true;
            }
            return controllo;
        }

        void esplode(WINDOW *win) {                    //colora lo bomba di rosso se triggerata
            init_pair(4, COLOR_YELLOW, COLOR_BLACK);
            init_pair(5, COLOR_RED, COLOR_WHITE);
            int colore=4;
            int addposX=posX, addposY=posY, lessposX=posX, lessposY=posY;
            int originalposX=posX, originalposY=posY;
            char A[] = {'x', 'X'};
            addposX++, addposY++, lessposX--, lessposY--;
            for (int i=0; i<3; i++){
                mvwprintw(win, posY, posX, " ");         //alterno gli spazi vuoti con i simboli per simulare l'esplosione
                wrefresh(win);
                napms(400);
                if (i!=2){
                    wattron(win, COLOR_PAIR(colore));
                    mvwaddch(win, posY, posX, A[i]);
                    wattroff(win, COLOR_PAIR(colore));      // problema legato all'attesa, non ci si puo muovere quanto si attiva
                    wrefresh(win);
                    napms(400);
                }
                colore++;
            }
            flash();
            wattron(win, COLOR_PAIR(1));
            /*  mvwprintw(win, posY, posX, "+");
              posX--;
              posY=posY+2;
              for (int k=0; k<3; k++){
                  posY--;
                  mvwprintw(win, posY, posX, "+");
                  wrefresh(win);
              }
              for (int j=0; j<5; j++){
                  if (j<2){
                      posX++;
                      mvwprintw(win, posY, posX, "+");
                  }
                  else if (j<4 && j>1){
                      posY++;
                      mvwprintw(win, posY, posX, "+");
                  }
                  else {
                      posX--;
                      mvwprintw(win, posY, posX, "+");
                  }
                  wrefresh(win);
              }
              wattroff(win, COLOR_PAIR(1));*/
            for (int j=0; j<8; j++){

                if(j==0) {
                    mvwprintw(win, posY, posX, "+");
                }
                if (j<3){
                    mvwprintw(win, addposY, lessposX, "+");
                    addposY--;
                }
                if (j==3){
                    posY--;
                    mvwprintw(win, posY, originalposX, "+");
                }
                if (j<7 && j>3){
                    mvwprintw(win, lessposY, addposX, "+");
                    lessposY++;
                }
                if(j==7){
                    addposY = originalposY;
                    addposY++;
                    mvwprintw(win, addposY, originalposX, "+");
                    wattroff(win, COLOR_PAIR(1));
                }
                wrefresh(win);
            }
        };

    class lanciabomba : public nemico{
    private:
        int lancioY, lancioX;
    public:
        lanciabomba(char c, int d, int y, int x) : nemico (c, d, y, x){}

        void disegna(WINDOW * win){
            wattron(win, COLOR_PAIR(1));
            mvwaddch (win, cy(), cx(), ACS_BLOCK);
            wattroff(win, COLOR_PAIR(1));
            wrefresh(win);
        }

        void muovi(WINDOW * win){
            int origx = posX;
            int origy = posY;
            int uno=0;
            int zero=0;
            srand(10);
            if (getch()!='x'){
                for (int i=0; i<7; i++){
                    int random = rand()%2;
                    mvwaddch (win, posY, posX, ACS_BLOCK);
                    wrefresh(win);
                    if (random == 0){
                        zero++;
                        mvwaddch (win, posY, posX, ' ');
                        posX++;
                        mvwaddch (win, posY, posX, ACS_BLOCK);
                        wrefresh(win);
                        napms(200);
                    }
                    if (random == 1){
                        uno++;
                        mvwaddch (win, posY, posX, ' ');
                        posY++;
                        mvwaddch (win, posY, posX, ACS_BLOCK);
                        wrefresh(win);
                        napms(200);
                    }
                }
                    for (int j=0; j!=zero; j++){
                        mvwaddch (win, posY, posX, ' ');
                        posX--;
                        mvwaddch (win, posY, posX, ACS_BLOCK);
                        wrefresh(win);
                        napms(200);
                    }
                    for (int m=0; m<uno; m++){
                        mvwaddch (win, posY, posX, ' ');
                        posY--;
                        mvwaddch (win, posY, posX, ACS_BLOCK);
                        wrefresh(win);
                        napms(200);
                    }
            }
        }
    };