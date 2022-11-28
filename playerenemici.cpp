#include <ncurses.h>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "enemy.h"
using namespace std;





void gioco(WINDOW * playwin,int idconfig, int idmap, coordinates player, coordinates nemico){


    if(idconfig==1 && idmap==1){         /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
Player * p = new Player(playwin, 1, 4, '$', 1);
shootingenemy * nemico1= new shootingenemy(playwin, 18 , 68 , 'X',0, 18 , 0 , 3, 7 );
shootingenemy * nemico1= new shootingenemy(playwin, 18 , 68 , 'X',0, 18 , 0 , 3, 7 );
shootingenemy * nemico1= new shootingenemy(playwin, 18 , 68 , 'X',0, 18 , 0 , 3, 7 );

        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}   //tipo di movimento
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 && /*cambio mappa*/ );



    }

   if(idconfig==2 && idmap==1){         /*seconda configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }


   if(idconfig==3 && idmap==1){             /*terza configurazione prima mappa */
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }

   if(idconfig==1 && idmap==2){           /*prima configurazione seconda mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }

   if(idconfig==2 && idmap==2 ){            /*seconda configurazione seconda mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );

    }


   if(idconfig==3 && idmap==2){        /*terza configurazione seconda mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );

    }

   if(idconfig==1 && idmap==3){            /*prima configurazione terza mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }


   if(idconfig==2 && idmap==3){               /*seconda configurazione terza mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }

   if(idconfig==3 && idmap==3 ){       /*terza configurazione terza mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }


   if(idconfig==1 && idmap==4){                  /*prima configurazione quarta mappa */
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }

   if(idconfig==2 && idmap==4){          /*seconda configurazione quarta mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }


   if(idconfig==3 && idmap==4 ){            /*terza configurazione quarta mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }


   if(idconfig==1  && idmap==5){             /*prima configurazione quinta mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }

   if(idconfig==2 && idmap==5){          /*seconda configurazione quinta mappa */
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }



   if(idconfig==3 && idmap==5){          /*terza configurazione quinta mappa*/
        /*dichairazione player
        dichiarazione nemici*/


        do { 
    
	p->display();
	if(wgetch(playwin) == ERR){}
	else{
	p->getmv();}


    /*collisioni*/



    if(nemico1->life()>0){     /*primo nemico*/
	 nemico1->leftenemsh();}
    else if(nemico1->life()==0){
        e->undisplaybullets(); 
        delete nemico1; 
        nemico1=NULL; 
        nemico2->decreaselifenemico(); 
    }



    if(nemico2->life()>0){      /*secondo nemico*/
	 nemico2->leftenemsh();}
    else if(nemico2->life()==0){
        e->undisplaybullets(); 
        delete nemico2; 
        nemico2=NULL; 
        nemico2->decreaselifenemico(); 
    }


    if(nemico3->life()>0){      /*terzo nemico*/
	 nemico3->leftenemsh();}
    else if(nemico3->life()==0){
        e->undisplaybullets(); 
        delete nemico3; 
        nemico3=NULL; 
        nemico3->decreaselifenemico(); 
    }




    napms(100);

	}while(p->getmv()!='x' && Life>0 );



    }


}