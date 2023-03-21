
#include <ncurses.h>
#include "artifacts.cpp"

struct personaggio{
    int bx;
    int by;
    int id;
    personaggio *next;
};

typedef personaggio *lpersonaggio;

int changemap(int layout, int rows, int columns);
class Player
{
  public :
     Player(WINDOW *win, int y, int x, char c, int firerate, int h, int bd);

      void mvup();//il player si muove in su di una unità
      void mvdown();
      void mvleft();
      void mvright();
      int  getmv();//ritorna l'input della tastiera
      void addbullet();//aggiunge un proiettile all lista dei proiettili presenti
      void remove_bullet();//elimina un proiettile
      void addblank();//aggiunge un nodo  "spazio" vuoto alla lista che cancella i vecchi proiettili
      void remove_blank();//elimina un nodo  "spazio" vuoto alla lista che cancella i vecchi proiettili
      void stampa_bullets();//stampa i proiettili su schermo
      int getplx();//ritorna le coordinate del player
      int getply();
      void display();
      void mvup2();
      void mvdown2();
      void mvleft2();
      void mvright2();
      void healtup(artifact * h, int score);
      int currentlife();
      int currentY();
      int currentX();
      int currdamage();
      void print_jump();

      protected:
      int xLoc, yLoc, xMax, yMax, xb, yb, identity, identity2, counter, counter2, firerate, mvdelay;
      bool flag, flag2;
      int healt, bulldamage;
      char character;
      WINDOW * curwin;
      lpersonaggio  p ;
      lpersonaggio  b ;
};