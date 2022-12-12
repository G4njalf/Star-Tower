#include <ncurses.h>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
//#include "/mnt/c/Users/Lenovo/Desktop/UNIVERSITA/PROGRAMMAZIONE/Progetto/map/draw.hpp"
#include "/mnt/c/Users/Lenovo/Desktop/UNIVERSITA/PROGRAMMAZIONE/Progetto/player/playerNEW.hpp"
#include "enemyDef.hpp"
using namespace std;





void gioco(WINDOW * playwin,int idmap,coordinates p,coordEnemy n1,coordEnemy n2,coordEnemy n3)
{
    srand((unsigned)time(0));
    int idconfig = rand() % 3;

    if(idconfig == 0 && idmap==0)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',0,18,0,3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',0,18,0,15,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',0,18,0,3,7);
        nodelay(playwin,true);
        wtimeout(playwin,1);
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
                nemico2->rightenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 1 && idmap==0)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',n1.col2+15,0,n1.col2-2,0,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',0,18,0,15,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',n3.col2+5,0,n3.col2-15,0,7);
        nodelay(playwin,true);
        wtimeout(playwin,1);
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
                nemico1->downenemsh();
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
                nemico2->rightenemsh();
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
                nemico3->upenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 2 && idmap==0)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        enemy * nemico1= new enemy(playwin,n1.row3,n1.row3,'1');
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row3,n2.col3,'2',n2.col3,0,n2.col3-1,0,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row3,n3.col3,'3',n3.col3+1,0,n3.col3-1,0,7);
        nodelay(playwin,true);
        wtimeout(playwin,1);
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
                nemico1->display();
            }   //tipo di movimento
            else if(false)  //nemico1->life()==0
            {
                //nemico1->undisplaybullets(); 
                delete nemico1; 
                nemico1=NULL; 
                //nemico1->decreaselifenemico(); 
            }

            if(true) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->upenemsh();
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
                nemico3->upenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 0 && idmap==1)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',0,n1.row1+2,0,n1.row1,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',0,n2.row1+3,0,n2.row1-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',0,n3.row1+1,0,n3.row1-2,7);

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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 1 && idmap==1)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',n1.col2+30,0,n1.col2-11,0,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',0,n2.row2+3,0,n2.row2-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',n3.col2+25,0,n3.col2-20,0,7);

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
                nemico1->downenemsh();
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
                nemico3->upenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 2 && idmap==1)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row3,n1.col3,'1',0,n1.row3+2,0,n1.row3,7);
        enemy * nemico2= new enemy(playwin,n2.row3,n2.col3,'2');
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row3,n3.col3,'3',n3.col3+2,0,n3.col3-2,0,7);

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
                //nemico2->leftenemsh();
                nemico2->display();
            }
            else if(false) //nemico2->life()==0
            {
                //nemico2->undisplaybullets(); 
                delete nemico2; 
                nemico2=NULL; 
                //nemico2->decreaselifenemico(); 
            }

            if(true) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 0 && idmap==2)
    {   
        /*prima configurazione prima mappa*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',0,n1.row1+4,0,n1.row1-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',0,n2.row1+8,0,n2.row1-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',n3.col1+2,0,n3.col1-2,0,7);

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
                nemico1->rightenemsh();
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
                nemico2->rightenemsh();
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
                nemico3->upenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 1 && idmap==2)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',0,n1.row2+4,0,n1.row2-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',0,n2.row2+1,0,n2.row2,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',0,n3.row2+1,0,n3.row2-1,7);

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
                nemico1->rightenemsh();
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
                nemico3->rightenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 2 && idmap==2)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row3,n1.col3,'1',0,n1.row3+4,0,n1.row3-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row3,n2.col3,'2',0,n2.row3+7,0,n2.row3-3,7);
        enemy * nemico3= new enemy(playwin,n3.row3,n3.col3,'3');

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
                nemico1->rightenemsh();
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
                //nemico3->leftenemsh();
                nemico3->display();
            }
            else if(false)  //nemico3->life()==0
            {
                //nemico3->undisplaybullets(); 
                delete nemico3; 
                nemico3=NULL; 
                //nemico3->decreaselifenemico(); 
            }

            napms(100);

	    }
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 0 && idmap==3)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',0,n1.row1+5,0,n1.row1-3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',0,n2.row1+1,0,n2.row1-2,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',0,n3.row1+3,0,n3.row1-4,7);

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
                nemico1->rightenemsh();
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
                nemico3->rightenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 1 && idmap==3)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',n1.col2+2,0,n1.col2-2,0,5);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',n2.col2,0,n2.col2-49,0,2);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',n3.col2+4,0,n3.col2-3,0,5);

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
                nemico1->upenemsh();
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
                nemico2->upenemsh();
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
                nemico3->upenemsh();
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
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

    if(idconfig == 2 && idmap==3)
    {   
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1);
        enemy * nemico1= new enemy(playwin,n1.row3,n1.col3,'1');
        enemy * nemico2= new enemy(playwin,n2.row3,n2.col3,'2');
        enemy * nemico3= new enemy(playwin,n3.row3,n3.col3,'3');

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
                //nemico1->leftenemsh();
                nemico1->display();
            }   //tipo di movimento
            else if(false)  //nemico1->life()==0
            {
                //nemico1->undisplaybullets(); 
                delete nemico1; 
                nemico1=NULL; 
                //nemico1->decreaselifenemico(); 
            }

            if(true) //nemico2->life()>0
            {      /*secondo nemico*/
                //nemico2->leftenemsh();
                nemico2->display();
            }
            else if(false) //nemico2->life()==0
            {
                //nemico2->undisplaybullets(); 
                delete nemico2; 
                nemico2=NULL; 
                //nemico2->decreaselifenemico(); 
            }

            if(true) //nemico3->life()>0
            {      /*terzo nemico*/
                //nemico3->leftenemsh();
                nemico3->display();
            }
            else if(false)  //nemico3->life()==0
            {
                //nemico3->undisplaybullets(); 
                delete nemico3; 
                nemico3=NULL; 
                //nemico3->decreaselifenemico(); 
            }

            napms(100);

	    }
        while(player->getmv()!='x' && /*Life>0*/true && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
    }

}
    