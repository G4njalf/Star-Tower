#include <ncurses.h>
//#include "Personaggio.hpp"
//using namespace std;

class artefatto{
private:
    int posX, posY;
  //  char carattere;
public:
    artefatto(int y, int x){
        posY = y;
        posX = x;
     //   carattere = c;
    }
    void disegna (WINDOW * win){
        mvwaddch(win, posY, posX, ACS_DIAMOND);
    }
    int cy(){
        return posY;
    }
    int cx(){
        return posX;
    }
};
class hpup : public artefatto{
private:
    int bonus;
public:
    hpup (int y, int x, int b) : artefatto (y, x){
        bonus = b;
    }
   bool raccolto (personaggio p){                   //controlla se e' sopra all'artefatto, se si aggiunge il bonus.
        if (cy()==p.cy() && cx()==p.cx()){
            flash();
            p.incrementavita(bonus);
         //  p.cl() == p.cl()+bonus;
        }
        return 1;
    }
    int aggbonus(){
        return bonus;
    }

};