#include <ncurses.h>

class artefatto{
protected:
    int posX, posY;
public:
    artefatto(int y, int x){
        posY = y;
        posX = x;
    }
    int cy(){
        return posY;
    }
    int cx(){
        return posX;
    }
    void cancella(WINDOW * window){
        mvwaddch(window, posY, posX, ' ');
        wrefresh(window);
    }
};
class hpup : public artefatto{
private:
    bool elimina=false;
    int vitapersonaggio;
public:
    hpup (int y, int x, int vitapers) : artefatto (y, x){
        vitapersonaggio = vitapers;
    }
    void disegna (WINDOW * win){
        mvwaddch(win, posY, posX, ACS_DIAMOND);
    }
    bool raccolto (int y, int x){                   //controlla se e' sopra all'artefatto, se si aggiunge il bonus.
        bool controllo=false;
        if (posY==y && posX==x){
            flash();
            elimina = true;
            controllo=true;
        }
        return controllo;
    }
    bool return_elimina(){
        return elimina;
    }
};
