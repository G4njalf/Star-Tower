#include <ncurses.h>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
#include "playerNEW.cpp"
#include "enemyDef.cpp"
using namespace std;

void block_spawn_exit_first_layout(WINDOW *win, int layout, bool first_map);
void block_exit_last_layout(WINDOW* win, int idmap, bool final_map);

void gioco(WINDOW * playwin, WINDOW * stats,int idmap,int idconfig,coordinates p,coordEnemy n1,coordEnemy n2,coordEnemy n3, int &life, int &score, int vita_nemici[], bool &nohpup, bool already_added[], bool &key_taken, bool &key_used_right, bool &key_used_left, bool &delone, bool first_map, lartifact &monete_attive, bool &nocoins, int &y, int &x, bool final_map) //MK
{
    block_spawn_exit_first_layout(playwin,idmap, first_map);
    block_exit_last_layout(playwin, idmap, final_map);
    srand((unsigned)time(0));
    if(idconfig == 0 && idmap==0)
    {
        /*prima configurazione prima mappa*/
        /*dichairazione player
        dichiarazione nemici*/
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'V',vita_nemici[0],0,18,0,3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'V',vita_nemici[1],0,18,0,15,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'V',vita_nemici[2],0,18,0,3,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        artifact * hpup = new artifact(playwin, 17, 12, '+');
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();
        if(nohpup)hpup->its_removed();
        nodelay(playwin,true);

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());

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
                    score = score-200;
                }
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;     //collisioni player
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
         while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        nohpup=hpup->return_remove();
     }

    else if(idconfig == 1 && idmap==0)
    {
        int prev, conta=0;
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'V',vita_nemici[0],n1.col2+15,0,n1.col2-2,0,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'V',vita_nemici[1],0,18,0,15,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'V',vita_nemici[2],n3.col2+5,0,n3.col2-15,0,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        key*chiave= new key(playwin,0,0,'K');
        coins * monete = new coins(playwin, 7, 8, 184, 14, 9, idmap, NULL);
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();
        nodelay(playwin,true);
        if(delone) monete->change_list(monete_attive);  //se erano state rimesse delle monete uso la lista dove sono state salvate
        else monete->all_coins();    //inizializzo le monete se non sono già state raccolte in questo nodo
        prev=monete->return_counter();

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true();
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());

            if (!nocoins){      //le stampo solo se di monete ce ne sono ancora
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){  //se è stata rimossa una moneta aggiungo gli score
                    if (!monete->return_remove()) {
                        score = score+10;
                        prev=monete->return_counter();  //aggiorno il numero di monete
                    }
                    else if (monete->return_remove() && conta==0){ //uso conta per vedere se ho gia' raccolto gli score dell'ultima moneta, se e' gia' stata incrementata vuol dire che e' gia' stata raccolta
                        score = score+10;
                        conta++;
                    }
                }
            }
            player->display();
            if(wgetch(playwin) == ERR) 
            {
               
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
                nemico1->downenemsh();
            }
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill()) 
            {      /*secondo nemico*/
                nemico2->rightenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill()) 
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        if(monete->return_currlist()!=monete_attive){ //controllo se le liste sono diverse, se lo sono aggiorno la lista del nodo e i booleani
            nocoins = monete->return_remove(); //se son state tutte rimosse aggiorno
            delone = monete->return_delone();   //aggiorno se e' stata eliminata almeno una moneta
            monete_attive = monete->return_currlist();
        }
       
    }

    else if(idconfig == 2 && idmap==0)
    {
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        enemy * nemico1= new enemy(playwin,n1.row3,n1.col3,'V',vita_nemici[0]);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row3,n2.col3,'V',vita_nemici[1],n2.col3+2,0,n2.col3-1,0,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row3,n3.col3,'V',vita_nemici[2],n3.col3+3,0,n3.col3-2,0,7);
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        nodelay(playwin,true);

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());
            
            player->display();
	        if(wgetch(playwin) == ERR) 
            {
               
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
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->upenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        
    }

    else if(idconfig == 0 && idmap==1)
    {
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'V',vita_nemici[0],0,n1.row1+2,0,n1.row1,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'V',vita_nemici[1],0,n2.row1+3,0,n2.row1-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'V',vita_nemici[2],0,n3.row1+1,0,n3.row1-2,5);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        artifact * hpup = new artifact(playwin, 19, 58, '+');
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();
        if(nohpup)hpup->its_removed();

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());
            
            if(!hpup->return_remove()){
                hpup->draw();
            }
	        player->display();

	        if(wgetch(playwin) == ERR) 
            {
             
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
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }

            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
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
                if(hpup->return_remove()){
                    life = life+50;
                    score = score-200;
                }
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life= life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        nohpup=hpup->return_remove();
     
    }

    else if(idconfig == 1 && idmap==1)
    {
        int prev, conta=0;
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'V',vita_nemici[0],n1.col2+30,0,n1.col2-11,0,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'V',vita_nemici[1],0,n2.row2+3,0,n2.row2-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'V',vita_nemici[2],n3.col2+25,0,n3.col2-20,0,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 8, 72, 184, 14, 15, idmap, NULL);
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();
        if(delone) monete->change_list(monete_attive);
        else monete->all_coins();
        prev=monete->return_counter();

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());

            if (!nocoins){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){  //se è stata rimossa una moneta aggiungo gli score
                    if (!monete->return_remove()) {
                        score = score+10;
                        prev=monete->return_counter();
                    }
                    else if (monete->return_remove() && conta==0){
                        score = score+10;
                        conta++;
                    }
                }
            }
	        player->display();
            if(wgetch(playwin) == ERR) 
            {
                
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
                nemico1->downenemsh();
            }
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }
            if(!nemico3->return_kill())
            {
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        if(monete->return_currlist()!=monete_attive){
            nocoins = monete->return_remove(); //se son state tutte rimosse aggiorno
            delone = monete->return_delone();   //aggiorno se e' stata eliminata almeno una moneta
            monete_attive = monete->return_currlist();
        }
      
    }

    else if(idconfig == 2 && idmap==1)
    {
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row3,n1.col3,'V',vita_nemici[0],0,n1.row3+2,0,n1.row3,7);
        enemy * nemico2= new enemy(playwin,n2.row3,n2.col3,'V',vita_nemici[1]);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row3,n3.col3,'V',vita_nemici[2],n3.col3+2,0,n3.col3-2,0,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());
            
            player->display();
	        if(wgetch(playwin) == ERR) 
            {
              
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
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->verticalmove();
                nemico2->display();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                score = score+50;
                already_added[1]=true;
            }
            if(!nemico3->return_kill())
            {
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
      
    }

    else if(idconfig == 0 && idmap==2)
    {
        int prev, conta=0;
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'V',vita_nemici[0],0,n1.row1+4,0,n1.row1-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'V',vita_nemici[1],0,n2.row1+8,0,n2.row1-3,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'V',vita_nemici[2],n3.col1+2,0,n3.col1-2,0,7);
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 21, 26, 184, 11, 39, idmap, NULL);
        artifact * hpup = new artifact(playwin, 19, 67, '+');
        if(nohpup)hpup->its_removed();
        if(delone) monete->change_list(monete_attive);
        else monete->all_coins();
        prev=monete->return_counter();

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());

            if (!nocoins){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){  //se è stata rimossa una moneta aggiungo gli score
                    if (!monete->return_remove()) {
                        score = score+10;
                        prev=monete->return_counter();
                    }
                    else if (monete->return_remove() && conta==0){
                        score = score+10;
                        conta++;
                    }
                }
            }
            if(!hpup->return_remove()){
                hpup->draw();
            }
	        player->display();
	        if(wgetch(playwin) == ERR) 
            {
                
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
            else if(nemico1->currentlife()<=0 && !already_added[0])  //nemico1->life()==0
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }

            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->rightenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1]) //nemico2->life()==0
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(!hpup->return_remove()){        //serve a raccogliere l'artefatto
                player->healtup(hpup, score);
                if(hpup->return_remove()){
                    life = life+50;
                    score = score-200;
                }
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life= life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        nohpup=hpup->return_remove();
        if(monete->return_currlist()!=monete_attive){
            nocoins = monete->return_remove(); //se son state tutte rimosse aggiorno
            delone = monete->return_delone();   //aggiorno se e' stata eliminata almeno una moneta
            monete_attive = monete->return_currlist();
        }
    
    }

    else if(idconfig == 1 && idmap==2)
    {
        int prev, conta=0;
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'V',vita_nemici[0],0,n1.row2+4,0,n1.row2-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'V',vita_nemici[1],0,n2.row2+1,0,n2.row2,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'V',vita_nemici[2],0,n3.row2+1,0,n3.row2-1,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 16, 8, 184, 5, 12, idmap, NULL);
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();
        if(delone) monete->change_list(monete_attive);
        else monete->all_coins();
        prev=monete->return_counter();

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());

            if (!nocoins){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){  //se è stata rimossa una moneta aggiungo gli score
                    if (!monete->return_remove()) {
                        score = score+10;
                        prev=monete->return_counter();
                    }
                    else if (monete->return_remove() && conta==0){
                        score = score+10;
                        conta++;
                    }
                }
            }
	        player->display();
	        if(wgetch(playwin) == ERR) 
            {
                
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
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->rightenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        if(monete->return_currlist()!=monete_attive){
            nocoins = monete->return_remove(); //se son state tutte rimosse aggiorno
            delone = monete->return_delone();   //aggiorno se e' stata eliminata almeno una moneta
            monete_attive = monete->return_currlist();
        }
      
    }

    else if(idconfig == 2 && idmap==2)
    {
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row3,n1.col3,'V',vita_nemici[0],0,n1.row3+4,0,n1.row3-2,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row3,n2.col3,'V',vita_nemici[1],0,n2.row3+7,0,n2.row3-3,7);
        enemy * nemico3= new enemy(playwin,n3.row3,n3.col3,'V',vita_nemici[2]);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());
            
            player->display();
	        if(wgetch(playwin) == ERR)
            {
            
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
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->horizontalmove();
                nemico3->display();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                score = score+50;
                already_added[2]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
      
    }

    else if(idconfig == 0 && idmap==3)
    {
        artifact * hpup = new artifact(playwin, 18, 50, '+');
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row1,n1.col1,'V',vita_nemici[0],0,n1.row1+5,0,n1.row1-3,7);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row1,n2.col1,'V',vita_nemici[1],0,n2.row1+1,0,n2.row1-2,7);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row1,n3.col1,'V',vita_nemici[2],0,n3.row1+3,0,n3.row1-4,7);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        if(nohpup)hpup->its_removed();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();

        do{
        if(!final_map){
          chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
          }
          if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());
          
          if(!hpup->return_remove()){
                hpup->draw();
            }
	        player->display();

	        if(wgetch(playwin) == ERR) 
            {
                
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
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }

            if(!nemico2->return_kill())
            {
                nemico2->leftenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill())
            {
                nemico3->rightenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(!hpup->return_remove()){        //serve a raccogliere l'artefatto
                player->healtup(hpup, score);
                if(hpup->return_remove()){
                    life = life+50;
                    score = score-200;
                }
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life= life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        nohpup=hpup->return_remove();

    }

    else if(idconfig == 1 && idmap==3)
    {
        int prev, conta=0;
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        shootingenemy * nemico1= new shootingenemy(playwin,n1.row2,n1.col2,'V',vita_nemici[0],n1.col2+2,0,n1.col2-2,0,5);
        shootingenemy * nemico2= new shootingenemy(playwin,n2.row2,n2.col2,'V',vita_nemici[1],n2.col2,0,n2.col2-49,0,2);
        shootingenemy * nemico3= new shootingenemy(playwin,n3.row2,n3.col2,'V',vita_nemici[2],n3.col2+4,0,n3.col2-3,0,5);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        coins * monete = new coins(playwin, 11, 34, 184, 18, 46, idmap, NULL);
        if(delone) monete->change_list(monete_attive);
        else monete->all_coins();
        prev = monete->return_counter();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();

        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());

            if (!nocoins){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){  //se è stata rimossa una moneta aggiungo gli score
                    if (!monete->return_remove()) {
                        score = score+10;
                        prev=monete->return_counter();
                    }
                    else if (monete->return_remove() && conta==0){
                        score = score+10;
                        conta++;
                    }
                }
            }
	        player->display();
	        if(wgetch(playwin) == ERR) 
            {
                
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
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                nemico1->undisplaybullets();
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->upenemsh();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                nemico2->undisplaybullets();
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->upenemsh();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                nemico3->undisplaybullets();
                score = score+50;
                already_added[2]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;
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
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        if(monete->return_currlist()!=monete_attive){
            nocoins = monete->return_remove(); //se son state tutte rimosse aggiorno
            delone = monete->return_delone();   //aggiorno se e' stata eliminata almeno una moneta
            monete_attive = monete->return_currlist();
        }
    }

    else if(idconfig == 2 && idmap==3)
    {
        int prev, conta=0;
        Player * player = new Player(playwin,p.rows,p.columns,'$',3,life,100);
        enemy * nemico1= new enemy(playwin,n1.row3,n1.col3,'V',vita_nemici[0]);
        enemy * nemico2= new enemy(playwin,n2.row3,n2.col3,'V',vita_nemici[1]);
        enemy * nemico3= new enemy(playwin,n3.row3,n3.col3,'V',vita_nemici[2]);
        nemico1->set_killed_status();
        nemico2->set_killed_status();
        nemico3->set_killed_status();
        key*chiave= new key(playwin,0,0,'K' );
        if(key_taken) chiave->taken_true();
        if(key_used_right) chiave->used_right_true();
        if(key_used_left) chiave->used_left_true();
        coins * monete = new coins(playwin, 17, 49, 184, 11, 7, idmap, NULL);
        if(delone) monete->change_list(monete_attive);
        else monete->all_coins();
        prev=monete->return_counter();
        
        do {
            if(!final_map){
            chiave->print_key_if_necessary(idmap, nemico1->currentlife(), nemico2->currentlife(), nemico3->currentlife());
            }
            if(!chiave->return_taken()){
                if(mvwinch(playwin,player->currentY(),player->currentX())=='K') chiave->taken_true(); 
            }
            chiave->open_door_if_necessary(idmap, player->currentY(), player->currentX());

            if (!nocoins){
                monete->print_coins();
                monete->delete_coins(player->currentY(), player->currentX());
                if(monete->return_counter()>prev){  //se è stata rimossa una moneta aggiungo gli score
                    if (!monete->return_remove()) {
                        score = score+10;
                        prev=monete->return_counter();
                    }
                    else if (monete->return_remove() && conta==0){
                        score = score+10;
                        conta++;
                    }
                }
            }
	        player->display();
	        if(wgetch(playwin) == ERR) 
            {
                
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
            else if(nemico1->currentlife()<=0 && !already_added[0])
            {
                score = score+50;
                already_added[0]=true;
            }
            if(!nemico2->return_kill()) //nemico2->life()>0
            {      /*secondo nemico*/
                nemico2->horizontalmove();
                nemico2->display();
            }
            else if(nemico2->currentlife()<=0 && !already_added[1])
            {
                score = score+50;
                already_added[1]=true;
            }

            if(!nemico3->return_kill()) //nemico3->life()>0
            {      /*terzo nemico*/
                nemico3->verticalmove();
                nemico3->display();
            }
            else if(nemico3->currentlife()<=0 && !already_added[2])
            {
                score = score+50;
                already_added[2]=true;
            }
            if(mvwinch(playwin, player->currentY(), player->currentX())=='V')
            {
                life = life-100;
            }
            napms(100);
            mvwprintw(stats, 2, 32, "    ");
            mvwprintw(stats, 2, 55, "    ");
            mvwprintw(stats, 2, 32, "%d", life);
            mvwprintw(stats, 2, 55, "%d", score);
            wrefresh(stats);
	    }
        while(player->getmv()!='x' && life>0 && changemap(idmap,player->currentY(),player->currentX()) == 100);
        vita_nemici[0]=nemico1->currentlife();
        vita_nemici[1]=nemico2->currentlife();
        vita_nemici[2]=nemico3->currentlife();
        y=player->currentY();
        x=player->currentX();
        key_taken=chiave->return_taken();
        key_used_right=chiave->return_used_right();
        key_used_left=chiave->return_used_left();
        if(monete->return_currlist()!=monete_attive){
            nocoins = monete->return_remove(); //se son state tutte rimosse aggiorno
            delone = monete->return_delone();   //aggiorno se e' stata eliminata almeno una moneta
            monete_attive = monete->return_currlist();
        }
      
    }
}

void block_spawn_exit_first_layout(WINDOW *win, int layout, bool first_map){
    if(first_map){
        if(layout==0){
            mvwaddch(win, 2,4, '_');
            mvwaddch(win, 2,5, '_');
            mvwaddch(win, 2,6, '_');
            mvwaddch(win, 2,7, '_');
        }
        if(layout==1){
            mvwaddch(win, 2,4, '_');
            mvwaddch(win, 2,5, '_');
            mvwaddch(win, 2,6, '_');
            mvwaddch(win, 2,7, '_');
        }
        if(layout==2){
            mvwaddch(win, 2,63, '_');
            mvwaddch(win, 2,64, '_');
            mvwaddch(win, 2,65, '_');
            mvwaddch(win, 2,66, '_');

            
        }
        if(layout==3){
            mvwaddch(win, 4,76, '|');
            mvwaddch(win, 5,76, '|');
            mvwaddch(win, 6,76, '|');
        }
    }
}

void block_exit_last_layout(WINDOW* win, int layout, bool final_map){
    if(final_map){
        if(layout==0){
            //porta sx
            mvwaddch(win, 19,21, '_');
            mvwaddch(win, 19,22, '_');
            mvwaddch(win, 19,23, '_');
            mvwaddch(win, 19,24, '_');
            mvwaddch(win, 19,25, '_');
            mvwaddch(win, 19,26, '_');
            //porta dx
            mvwaddch(win, 10,71, '|');
            mvwaddch(win, 11,71, '|');
            mvwaddch(win, 12,71, '|');

        }
        else if(layout==1){
            //porta sx
            mvwaddch(win, 15,10, '|');
            mvwaddch(win, 16,10, '|');
            mvwaddch(win, 17,10, '|');
            //porta dx
            mvwaddch(win, 20,46, '_');
            mvwaddch(win, 20,47, '_');
            mvwaddch(win, 20,48, '_');
            mvwaddch(win, 20,49, '_');
            mvwaddch(win, 20,50, '_');
            mvwaddch(win, 20,51, '_');
        }
        else if(layout==2){
            //porta sx
            mvwaddch(win, 10,5, '|');
            mvwaddch(win, 11,5, '|');
            mvwaddch(win, 12,5, '|');
            mvwaddch(win, 10,6, ' ');
            mvwaddch(win, 11,6, ' ');
            mvwaddch(win, 12,6, ' ');
            mvwaddch(win, 12,6, '_');
            //porta dx
            mvwaddch(win, 13,70, '|');
            mvwaddch(win, 14,70, '|');
            mvwaddch(win, 15,70, '|');
        }
        else if(layout==3){
            //porta sx
            mvwaddch(win, 17,5, '|');
            mvwaddch(win, 18,5, '|');
            mvwaddch(win, 19,5, '|');
            mvwaddch(win, 17,6, ' ');
            mvwaddch(win, 18,6, ' ');
            mvwaddch(win, 19,6, ' ');
            //porta dx
            mvwaddch(win, 20,37, '_');
            mvwaddch(win, 20,38, '_');
            mvwaddch(win, 20,39, '_');
            mvwaddch(win, 20,40, '_');
            mvwaddch(win, 20,41, '_');
            mvwaddch(win, 20,42, '|');
        }
    }
}
    