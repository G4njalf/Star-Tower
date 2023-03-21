
#include <ncurses.h>
class enemy
{
	public :
		enemy(WINDOW *win, int y, int x, char c, int healt);

		void mvup(); //muovi il nemico di una unità in su
		void mvdown();
		void mvleft();
		void mvright();
		
		void display();// fa il display del nemico si schermo
		int fyloc();//rirtorna la posizione del nemico
		int fxloc();
		int getenemx();
		int getenemy();
		void undisplay();
		void verticalmove();//nemico verticale
		void horizontalmove();//nemico orizzontale
		void diagonal1move();//nemico dioagonale
		void diagonal2move();
        void damage(int d);
        bool return_kill();
		void set_killed_status();
        int currentlife();

	protected :
    int xloc, yloc, xMax, yMax, j, healt;
    bool killed=false;
    char character;
    WINDOW *curwin;
};

struct nemico{
    int bx;
    int by;
    int id;
    nemico *next;
};

typedef nemico *lnemico;

class shootingenemy : public enemy { //nemici che sparano
	protected :
		int xmax, ymax, xmin , ymin , counter, xb, yb, identity, firerate, bulldamage=50;
		bool flag;
		lnemico p ;
		lnemico b ; 
	public:
		shootingenemy(WINDOW *win, int y, int x, char c, int h, int xmax, int ymax, int xmin , int ymin, int firerate ) : enemy(win,y,x,c,h){
			this->xmax= xmax;
			this->ymax=ymax;
			this->xmin= xmin;
			this->ymin=ymin;
			this->firerate= firerate;
			counter = firerate;
			flag = true; 
			p = NULL ;
			b = NULL ; 
		}
		void rightenemsh(); //nemico che spara verso destra muovendosi verticalmente
		void leftenemsh();//
		void upenemsh();//nemico che spara verso l'alto muovendosi orizzontalmente
		void downenemsh();
		void addbullet();//aggiunge un proiettile all lista dei proiettili presenti
		void remove_bullet(); //elimina un proiettile
		void addblank();//aggiunge un nodo  "spazio" vuoto alla lista che cancella i vecchi proiettili
		void remove_blank();//aggiunge un nodo  "spazio" vuoto alla lista che cancella i vecchi proiettili
		void stampa_bullets();//stampa i proiettili su schermo
        int bulletdamage();
		void undisplaybullets();

};




