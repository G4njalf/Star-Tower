#include <ncurses.h>

class artifact {
public:
    artifact(int y, int x, char c);

    int cy();
    int cx();
    void draw(WINDOW * window);
    void drawhpup(WINDOW * window);
    bool collected (int y, int x);
    bool return_remove();

protected:
    int posX, posY;
    char character;
    bool remove = false;
};
artifact :: artifact(int y, int x, char c){
        posY = y;
        posX = x;
        character = c;
    }
    int artifact :: cy(){
        return posY;
    }
    int artifact :: cx(){
        return posX;
    }
    bool artifact :: collected (int y, int x){                   //controlla se e' sopra all'artefatto, se si dice al player
        bool check=false;                                    //di aggiungere il bonus e cancella l'artefatto
        if (posY==y && posX==x){
            remove = true;
            check=true;
        }
        return check;
    }
    bool artifact :: return_remove(){
        return remove;
    }
    void artifact :: draw (WINDOW * win){
        mvwaddch(win, posY, posX, character);
    }
    void artifact :: drawhpup (WINDOW * win){
        mvwaddch(win, posY, posX, ACS_DIAMOND);
    }



class key{
    protected:
        int y;
        int x;
        char c;
    public:
        key(int y, int x, char c){
            this->y=y;
            this->x=x;
            this->c=c;
        };

    void show(WINDOW*win){
        mvwaddch(win, y, x, c);

    };

};
    
        