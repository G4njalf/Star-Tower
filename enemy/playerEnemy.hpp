#include <ncurses.h>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
//#include "/mnt/c/Users/Lenovo/Desktop/UNIVERSITA/PROGRAMMAZIONE/Progetto/map/draw.hpp"
#include "/mnt/c/Users/Lenovo/Desktop/UNIVERSITA/PROGRAMMAZIONE/Progetto/player/playerNEW.hpp"
#include "enemyDef.hpp"
using namespace std;





void gioco(WINDOW * playwin,int idmap,coordinates p,coordinates n1,coordinates n2,coordinates n3)
{
    if(idmap==0)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.rows,n1.columns,'V',0,18,0,3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.rows,n2.columns,'V',0,18,0,3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.rows,n3.columns,'V',0,18,0,3,7);

        do { 
    
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
	            player->getmv();
            }
        /*collisioni*/
            if(true) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->leftenemsh();
            }   //tipo di movimento
            else if(false)  //nemico1->life()==0
            {
                nemico1->undisplaybullets(); 
                delete nemico1; 
                nemico1=NULL; 
                //nemico1->decreaselifenemico(); 
            }

            if(true) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(false) //nemico2->life()==0
            {
                nemico2->undisplaybullets(); 
                delete nemico2; 
                nemico2=NULL; 
                //nemico2->decreaselifenemico(); 
            }

            if(true) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->leftenemsh();
            }
            else if(false)  //nemico3->life()==0
            {
                nemico3->undisplaybullets(); 
                delete nemico3; 
                nemico3=NULL; 
                //nemico3->decreaselifenemico(); 
            }

            napms(100);

	    }
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) != 100);
    }

    if(idmap==1)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.rows,n1.columns,'V',0,18,0,3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.rows,n2.columns,'V',0,18,0,3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.rows,n3.columns,'V',0,18,0,3,7);

        do { 
    
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
	            player->getmv();
            }
        /*collisioni*/
            if(true) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->leftenemsh();
            }   //tipo di movimento
            else if(false)  //nemico1->life()==0
            {
                nemico1->undisplaybullets(); 
                delete nemico1; 
                nemico1=NULL; 
                //nemico1->decreaselifenemico(); 
            }

            if(true) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(false) //nemico2->life()==0
            {
                nemico2->undisplaybullets(); 
                delete nemico2; 
                nemico2=NULL; 
                //nemico2->decreaselifenemico(); 
            }

            if(true) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->leftenemsh();
            }
            else if(false)  //nemico3->life()==0
            {
                nemico3->undisplaybullets(); 
                delete nemico3; 
                nemico3=NULL; 
                //nemico3->decreaselifenemico(); 
            }

            napms(100);

	    }
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) != 100);
    }

    if(idmap==2)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.rows,n1.columns,'V',0,18,0,3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.rows,n2.columns,'V',0,18,0,3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.rows,n3.columns,'V',0,18,0,3,7);

        do { 
    
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
	            player->getmv();
            }
        /*collisioni*/
            if(true) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->leftenemsh();
            }   //tipo di movimento
            else if(false)  //nemico1->life()==0
            {
                nemico1->undisplaybullets(); 
                delete nemico1; 
                nemico1=NULL; 
                //nemico1->decreaselifenemico(); 
            }

            if(true) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(false) //nemico2->life()==0
            {
                nemico2->undisplaybullets(); 
                delete nemico2; 
                nemico2=NULL; 
                //nemico2->decreaselifenemico(); 
            }

            if(true) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->leftenemsh();
            }
            else if(false)  //nemico3->life()==0
            {
                nemico3->undisplaybullets(); 
                delete nemico3; 
                nemico3=NULL; 
                //nemico3->decreaselifenemico(); 
            }

            napms(100);

	    }
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) != 100);
    }

    if(idmap==3)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.rows,n1.columns,'V',0,18,0,3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.rows,n2.columns,'V',0,18,0,3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.rows,n3.columns,'V',0,18,0,3,7);

        do { 
    
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
	            player->getmv();
            }
        /*collisioni*/
            if(true) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->leftenemsh();
            }   //tipo di movimento
            else if(false)  //nemico1->life()==0
            {
                nemico1->undisplaybullets(); 
                delete nemico1; 
                nemico1=NULL; 
                //nemico1->decreaselifenemico(); 
            }

            if(true) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(false) //nemico2->life()==0
            {
                nemico2->undisplaybullets(); 
                delete nemico2; 
                nemico2=NULL; 
                //nemico2->decreaselifenemico(); 
            }

            if(true) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->leftenemsh();
            }
            else if(false)  //nemico3->life()==0
            {
                nemico3->undisplaybullets(); 
                delete nemico3; 
                nemico3=NULL; 
                //nemico3->decreaselifenemico(); 
            }

            napms(100);

	    }
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) != 100);
    }

}
    