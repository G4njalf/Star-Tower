#include <ncurses.h>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
#include "playerNEW.hpp"
#include "enemyDef.hpp"
using namespace std;

void gioco(WINDOW * playwin, WINDOW * stats,int idmap,coordinates p,coordEnemy n1,coordEnemy n2,coordEnemy n3, int life, int score)
{
    srand((unsigned)time(0));
    //int idconfig = rand() % 3;
    int idconfig = 1;

    if(idconfig == 0 && idmap==0)
    {
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        bool already_added_score1, already_added_score2, already_added_score3;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',100,0,18,0,3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',100,0,18,0,15,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',100,0,18,0,3,7);
        artifact * hpup = new artifact(playwin, 17, 12, '+');
        nodelay(playwin,true);

        do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)     //se ucciso aggiunge gli score
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->rightenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }
            if(!nemico3->return_kill())
            {
                nemico3->leftenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
     }

     if(idconfig == 1 && idmap==0)
     {
        bool already_added_score1, already_added_score2, already_added_score3;
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',100,n1.col2+15,0,n1.col2-2,0,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',100,0,18,0,15,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',100,n3.col2+5,0,n3.col2-15,0,7);
        coins * monete = new coins(playwin, 7, 8, 184, 14, 9, idmap);
        prev=monete->return_counter();
        monete->all_coins();        //inizializzo le monete
        nodelay(playwin,true);

         do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->rightenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
         nemico1->undisplay();
         nemico2->undisplay();
         nemico3->undisplay();
    }

    if(idconfig == 2 && idmap==0)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        enemy * nemico1= new enemy(playwin,n1.row3,n1.row3,'1',100);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row3,n2.col3,'2',100,n2.col3,0,n2.col3-1,0,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row3,n3.col3,'3',100,n3.col3+1,0,n3.col3-1,0,7);
        nodelay(playwin,true);

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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->upenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 0 && idmap==1)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',100,0,n1.row1+2,0,n1.row1,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',100,0,n2.row1+3,0,n2.row1-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',100,0,n3.row1+1,0,n3.row1-2,7);
        artifact * hpup = new artifact(playwin, 19, 58, '+');

        do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }

            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->leftenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 1 && idmap==1)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',100,n1.col2+30,0,n1.col2-11,0,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',100,0,n2.row2+3,0,n2.row2-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',100,n3.col2+25,0,n3.col2-20,0,7);
        coins * monete = new coins(playwin, 8, 72, 184, 14, 15, idmap);
        prev=monete->return_counter();
        monete->all_coins();

        do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }
            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 2 && idmap==1)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row3,n1.col3,'1',100,0,n1.row3+2,0,n1.row3,7);
        enemy * nemico2= new enemy(playwin,n2.row3,n2.col3,'2',100);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row3,n3.col3,'3',100,n3.col3+2,0,n3.col3-2,0,7);

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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->verticalmove();
                nemico2->display();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                score = score+50;
                already_added_score2 = true;
            }
            if(!nemico3->return_kill())
            {
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 0 && idmap==2)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',100,0,n1.row1+4,0,n1.row1-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',100,0,n2.row1+8,0,n2.row1-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',100,n3.col1+2,0,n3.col1-2,0,7);
        artifact * hpup = new artifact(playwin, 19, 67, '+');
        coins * monete = new coins(playwin, 21, 26, 184, 11, 39, idmap);
        prev=monete->return_counter();
        monete->all_coins();

        do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)  //nemico1->life()==0
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }

            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->rightenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2) //nemico2->life()==0
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 1 && idmap==2)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',100,0,n1.row2+4,0,n1.row2-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',100,0,n2.row2+1,0,n2.row2,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',100,0,n3.row2+1,0,n3.row2-1,7);
        coins * monete = new coins(playwin, 16, 8, 184, 5, 12, idmap);
        prev=monete->return_counter();
        monete->all_coins();

        do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->rightenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 2 && idmap==2)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row3,n1.col3,'1',100,0,n1.row3+4,0,n1.row3-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row3,n2.col3,'2',100,0,n2.row3+7,0,n2.row3-3,7);
        enemy * nemico3= new enemy(playwin,n3.row3,n3.col3,'3',100);

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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->horizontalmove();
                nemico3->display();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 0 && idmap==3)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        artifact * hpup = new artifact(playwin, 18, 11, '+');
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'1',100,0,n1.row1+5,0,n1.row1-3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'2',100,0,n2.row1+1,0,n2.row1-2,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'3',100,0,n3.row1+3,0,n3.row1-4,7);

        do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }

            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->rightenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 1 && idmap==3)
    {
        int prev;
        bool already_added_score1, already_added_score2, already_added_score3;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'1',100,n1.col2+2,0,n1.col2-2,0,5);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'2',100,n2.col2,0,n2.col2-49,0,2);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'3',100,n3.col2+4,0,n3.col2-3,0,5);
        coins * monete = new coins(playwin, 11, 34, 184, 18, 46, idmap);
        prev=monete->return_counter();
        monete->all_coins();

        do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->upenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }

    if(idconfig == 2 && idmap==3)
    {
        bool already_added_score1, already_added_score2, already_added_score3;
        int prev;
        Player * player = new Player(playwin,p.rows,p.columns,'$',1,life,100);
        enemy * nemico1= new enemy(playwin,n1.row3,n1.col3,'1',100);
        enemy * nemico2= new enemy(playwin,n2.row3,n2.col3,'2',100);
        enemy * nemico3= new enemy(playwin,n3.row3,n3.col3,'3',100);
        coins * monete = new coins(playwin, 17, 49, 184, 11, 7, idmap);
        prev=monete->return_counter();
        monete->all_coins();

        do {
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
            else if(nemico1->currentlife()<=0 && !already_added_score1)
            {
                score = score+50;
                already_added_score1 = true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->horizontalmove();
                nemico2->display();
            }
            else if(nemico2->currentlife()<=0 && !already_added_score2)
            {
                score = score+50;
                already_added_score2 = true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->verticalmove();
                nemico3->display();
            }
            else if(nemico3->currentlife()<=0 && !already_added_score3)
            {
                score = score+50;
                already_added_score3 = true;
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
        nemico1->undisplay();
        nemico2->undisplay();
        nemico3->undisplay();
    }
}
    