#include <ncurses.h>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
#include "playerNEW.hpp"
#include "enemyDef.hpp"
using namespace std;


void gioco(WINDOW * playwin, WINDOW * stats,int idmap,int idconfig,coordinates p,coordEnemy n1,coordEnemy n2,coordEnemy n3, int &life, int &score, int vita_nemici[], bool nohpup[], bool already_added[], bool &key_taken)
{
    srand((unsigned)time(0)); 
    //idconfig=0;
    if(idconfig == 0 && idmap==0)
    {
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',vita_nemici[0],0,18,0,3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',vita_nemici[1],0,18,0,15,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',vita_nemici[2],0,18,0,3,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        artifact * hpup = new artifact(playwin, 17, 12, '+');
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(nohpup[0]){
            hpup->its_removed();
        }
        nodelay(playwin,true);

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            //chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());

            if(!hpup->return_remove()){         //disegno finchè non viene raccolto
                hpup->draw();
            }
	        player->display();
	        if(wgetch(playwin) == ERR){}
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());      //collisioni nemico
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }

            if(!nemico1->return_kill())     //si muove finche' non muore
            {
                nemico1->leftenemsh();
            }
            else if(nemico1->currentlife()<=0 && !already_added[0])     //se ucciso aggiunge gli score
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->rightenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }
            if(!nemico3->return_kill())
            {
                nemico3->leftenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(!hpup->return_remove()){        //serve a raccogliere l'artefatto
                player->healtup(hpup, score);
                if(hpup->return_remove()){      //costa 100 score raccoglierlo, se no non lo prende
                    life = life+50;
                    score = score-100;
                }
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;     //collisioni player
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
             napms(100);

            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");        //aggiorno i dati del player
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);
         }
         while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
        nohpup[0]=hpup->return_remove();
        
     }

     else if(idconfig == 1 && idmap==0)
     {
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',vita_nemici[0],n1.col2+15,0,n1.col2-2,0,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',vita_nemici[1],0,18,0,15,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',vita_nemici[2],n3.col2+5,0,n3.col2-15,0,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 7, 8, 184, 14, 9, idmap);
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        prev=monete->return_counter();
        monete->all_coins();        //inizializzo le monete
        nodelay(playwin,true);

         do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            if (!monete->return_remove()){      //finche' non si raccolgono sono stampate
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){  //se è stata rimossa una moneta aggiungo gli score
                    score = score+10;
                    prev=monete->return_counter();
                }
            }
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }

            if(!nemico1->return_kill()) //nemico1->life()>0
            {
                nemico1->downenemsh();
            }
            else if(nemico1->currentlife()<=0 && !already_added[3])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[3]=true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->rightenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[4])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[4]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[5])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[5]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
            napms(100);
             mvwprintw(stats, 2, 32, "    ");
             mvwprintw(stats, 2, 55, "    ");
             mvwprintw(stats, 2, 32, "%d", life);
             mvwprintw(stats, 2, 55, "%d", score);
             wrefresh(stats);

	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
         /*nemico1->undisplay();
         nemico2->undisplay();
         nemico3->undisplay();*/
    }

    else if(idconfig == 2 && idmap==0)
    {
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        enemy * nemico1= new enemy(playwin,n1.row3,n1.row3,'1',vita_nemici[0]);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row3,n2.col3,'2',vita_nemici[1],n2.col3,0,n2.col3-1,0,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row3,n3.col3,'3',vita_nemici[2],n3.col3+1,0,n3.col3-1,0,7);
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        nodelay(playwin,true);

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill())
            {
                nemico1->display();
                nemico1->horizontalmove();
            }
            else if(nemico1->currentlife()<=0 && !already_added[6])
            {
                score = score+50;
                already_added[6]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->upenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[7])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[7]=true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[8])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[8]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);
	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
        /*nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();*/
    }

    else if(idconfig == 0 && idmap==1)
    {
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',vita_nemici[0],0,n1.row1+2,0,n1.row1,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',vita_nemici[1],0,n2.row1+3,0,n2.row1-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',vita_nemici[2],0,n3.row1+1,0,n3.row1-2,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        artifact * hpup = new artifact(playwin, 19, 58, '+');
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(nohpup[1]){
            hpup->its_removed();
        }

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            if(!hpup->return_remove()){
                hpup->draw();
            }
	        player->display();

	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }

            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill()) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->leftenemsh();
            }   //tipo di movimento
            else if(nemico1->currentlife()<=0 && !already_added[9])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[9]=true;
            }

            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[10])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[10]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->leftenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[11])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[11]=true;
            }
            if(!hpup->return_remove()){        //serve a raccogliere l'artefatto
                player->healtup(hpup, score);
                if(hpup->return_remove()){
                    life = life+50;
                    score = score-100;
                }
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life= life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);
	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
        nohpup[1]=hpup->return_remove();
        /*nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();*/
    }

    else if(idconfig == 1 && idmap==1)
    {
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',vita_nemici[0],n1.col2+30,0,n1.col2-11,0,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',vita_nemici[1],0,n2.row2+3,0,n2.row2-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',vita_nemici[2],n3.col2+25,0,n3.col2-20,0,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 8, 72, 184, 14, 15, idmap);
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        prev=monete->return_counter();
        monete->all_coins();

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            if (!monete->return_remove()){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){
                    score = score+10;
                    prev=monete->return_counter();
                }
            }
	        player->display();
            if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill()) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->downenemsh();
            }   //tipo di movimento
            else if(nemico1->currentlife()<=0 && !already_added[12])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[12]=true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[13])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[13]=true;
            }
            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[14])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[14]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);

	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
        /*nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();*/
    }

    else if(idconfig == 2 && idmap==1)
    {
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row3,n1.col3,'1',vita_nemici[0],0,n1.row3+2,0,n1.row3,7);
        enemy * nemico2= new enemy(playwin,n2.row3,n2.col3,'2',vita_nemici[1]);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row3,n3.col3,'3',vita_nemici[2],n3.col3+2,0,n3.col3-2,0,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill()) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->leftenemsh();
            }   //tipo di movimento
            else if(nemico1->currentlife()<=0 && !already_added[15])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[15]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->verticalmove();
                nemico2->display();
            }
            else if(nemico2->currentlife()<=0 && !already_added[16])
            {
                score = score+50;
                already_added[16]=true;
            }
            if(!nemico3->return_kill())
            {
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[17])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[17]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);

	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
        /*nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();*/
    }

    else if(idconfig == 0 && idmap==2)
    {
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',vita_nemici[0],0,n1.row1+4,0,n1.row1-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',vita_nemici[1],0,n2.row1+8,0,n2.row1-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',vita_nemici[2],n3.col1+2,0,n3.col1-2,0,7);
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        artifact * hpup = new artifact(playwin, 19, 67, '+');
        if(nohpup[2]){
            hpup->its_removed();
        }
        coins * monete = new coins(playwin, 21, 26, 184, 11, 39, idmap);
        prev=monete->return_counter();
        monete->all_coins();

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            if (!monete->return_remove()){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){
                    score = score+10;
                    prev=monete->return_counter();
                }
            }
            if(!hpup->return_remove()){
                hpup->draw();
            }
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill()) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->rightenemsh();
            }   //tipo di movimento
            else if(nemico1->currentlife()<=0 && !already_added[18])  //nemico1->life()==0
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[18]=true;
            }

            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->rightenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[19]) //nemico2->life()==0
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[19]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[20])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[20]=true;
            }
            if(!hpup->return_remove()){        //serve a raccogliere l'artefatto
                player->healtup(hpup, score);
                if(hpup->return_remove()){
                    life = life+50;
                    score = score-100;
                }
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life= life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life= life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);

	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
        nohpup[2]=hpup->return_remove();
        /*nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();*/
    }

    else if(idconfig == 1 && idmap==2)
    {
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',vita_nemici[0],0,n1.row2+4,0,n1.row2-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',vita_nemici[1],0,n2.row2+1,0,n2.row2,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',vita_nemici[2],0,n3.row2+1,0,n3.row2-1,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 16, 8, 184, 5, 12, idmap);
        prev=monete->return_counter();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        monete->all_coins();

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            if (!monete->return_remove()){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){
                    score = score+10;
                    prev=monete->return_counter();
                }
            }
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill())
            {
                nemico1->rightenemsh();
            }   //tipo di movimento e score
            else if(nemico1->currentlife()<=0 && !already_added[21])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[21]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[22])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[22]=true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->rightenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[23])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[23]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);
	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
       /* nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();*/
    }

    else if(idconfig == 2 && idmap==2)
    {
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row3,n1.col3,'1',vita_nemici[0],0,n1.row3+4,0,n1.row3-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row3,n2.col3,'2',vita_nemici[1],0,n2.row3+7,0,n2.row3-3,7);
        enemy * nemico3= new enemy(playwin,n3.row3,n3.col3,'3',vita_nemici[2]);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill())
            {
                nemico1->rightenemsh();
            }
            else if(nemico1->currentlife()<=0 && !already_added[24])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[24]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[25])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[25]=true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->horizontalmove();
                nemico3->display();
            }
            else if(nemico3->currentlife()<=0 && !already_added[26])
            {
                score = score+50;
                already_added[26]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);

	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
        /*nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();*/
    }

    else if(idconfig == 0 && idmap==3)
    {
        artifact * hpup = new artifact(playwin, 18, 50, '+');
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',vita_nemici[0],0,n1.row1+5,0,n1.row1-3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',vita_nemici[1],0,n2.row1+1,0,n2.row1-2,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',vita_nemici[2],0,n3.row1+3,0,n3.row1-4,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        if(nohpup[3]){
            hpup->its_removed();
        }
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();

        do {
          chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
          if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
          
          if(!hpup->return_remove()){
                hpup->draw();
            }
	        player->display();

	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill())
            {
                nemico1->rightenemsh();
            }
            else if(nemico1->currentlife()<=0 && !already_added[27])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[27]=true;
            }

            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[28])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[28]=true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->rightenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[29])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[29]=true;
            }
            if(!hpup->return_remove()){        //serve a raccogliere l'artefatto
                player->healtup(hpup, score);
                if(hpup->return_remove()){
                    life = life+50;
                    score = score-100;
                }
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life= life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life= life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);

        }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
        nohpup[3]=hpup->return_remove();
        /*nemico1->undisplay();
               nemico2->undisplay();
               nemico3->undisplay();*/
    }

    else if(idconfig == 1 && idmap==3)
    {
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',vita_nemici[0],n1.col2+2,0,n1.col2-2,0,5);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',vita_nemici[1],n2.col2,0,n2.col2-49,0,2);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',vita_nemici[2],n3.col2+4,0,n3.col2-3,0,5);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 11, 34, 184, 18, 46, idmap);
        prev=monete->return_counter();
        monete->all_coins();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            if (!monete->return_remove()){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){
                    score = score+10;
                    prev=monete->return_counter();
                }
            }
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill()) //nemico1->life()>0
            {     /*primo nemico*/
                nemico1->upenemsh();
            }   //tipo di movimento
            else if(nemico1->currentlife()<=0 && !already_added[30])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[30]=true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->upenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[31])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[31]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[32])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[32]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;
            }
            if (mvwinch(playwin, player->currentY(), player->currentX())=='*'){
                life = life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);

        }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();
    }

    else if(idconfig == 2 && idmap==3)
    {
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        enemy * nemico1= new enemy(playwin,n1.row3,n1.col3,'1',vita_nemici[0]);
        enemy * nemico2= new enemy(playwin,n2.row3,n2.col3,'2',vita_nemici[1]);
        enemy * nemico3= new enemy(playwin,n3.row3,n3.col3,'3',vita_nemici[2]);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 17, 49, 184, 11, 7, idmap);
        prev=monete->return_counter();
        monete->all_coins();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();

        do {
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            
            if (!monete->return_remove()){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){
                    score = score+10;
                    prev=monete->return_counter();
                }
            }
	        player->display();
	        if(wgetch(playwin) == ERR) //che cazzo vuol dire?
            {
                //exit;//continue;??
            }
	        else
            {
                player->getmv();
            }
            if (mvwinch(playwin,nemico1->getenemy(),nemico1->getenemx())=='.'||mvwinch(playwin,nemico1->getenemy()+1,nemico1->getenemx())=='.'){
                nemico1->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico2->getenemy(),nemico2->getenemx())=='.'||mvwinch(playwin,nemico2->getenemy()+1,nemico2->getenemx())=='.'){
                nemico2->damage(player->currdamage());
            }
            if (mvwinch(playwin,nemico3->getenemy(),nemico3->getenemx())=='.'||mvwinch(playwin,nemico3->getenemy()+1,nemico3->getenemx())=='.'){
                nemico3->damage(player->currdamage());
            }
            if(!nemico1->return_kill())
            {     /*primo nemico*/
                nemico1->horizontalmove();
                nemico1->display();
            }   //tipo di movimento
            else if(nemico1->currentlife()<=0 && !already_added[33])
            {
                score = score+50;
                already_added[33]=true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->horizontalmove();
                nemico2->display();
            }
            else if(nemico2->currentlife()<=0 && !already_added[34])
            {
                score = score+50;
                already_added[34]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->verticalmove();
                nemico3->display();
            }
            else if(nemico3->currentlife()<=0 && !already_added[35])
            {
                score = score+50;
                already_added[35]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='1' || mvwinch(playwin, player->currentY(), player->currentX())=='2' || mvwinch(playwin, player->currentY(), player->currentX())=='3')
            {
                life = life-50;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);
	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,getcury(playwin),getcurx(playwin)) == 100);
        mvwaddch(playwin, player->currentY(), player->currentX(), ' ');
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        key_taken=chiave->return_taken();

        /*nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();*/
    }
}
    