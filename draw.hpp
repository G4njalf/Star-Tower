#include<ncurses.h>
#include<cstdlib>

struct coordinates
{
    int columns;
    int rows;
};
struct door
{
    coordinates entranceDlocation; //locazione della porta di ingresso
    coordinates LeftExitlocation; //locazione della porta di uscita Left
    coordinates RightExitlocation; //locazione della porta di uscita right
    bool LeftExitOpen; // true = si    
    bool RightExitOpen; // true = si
};

void layouts(int x, WINDOW* room, coordinates cord, door doorx)
{

        if (x == 0)
        {
            coordinates cord;
            mvwprintw(room,1 ,1,"__|    |______________________________________________________________________");
            mvwprintw(room,2 ,1,"__|    |______________________________________________________________________");
            mvwprintw(room,3 ,1,"__|    |______|                                                      |________");
            mvwprintw(room,4 ,1,"__|    |______|                                                      |_L0_____");
            mvwprintw(room,5 ,1,"__|    |______|     _________________                                |________");
            mvwprintw(room,6 ,1,"__|    |______|    |_________________|                               |________");
            mvwprintw(room,7 ,1,"__|                |_________________|                               |________");
            mvwprintw(room,8 ,1,"__|                |_________________|                               |________");
            mvwprintw(room,9 ,1,"__|________________|_________________|                               |________");
            mvwprintw(room,10,1,"_____________________________________|                                        ");
            mvwprintw(room,11,1,"_____________________________________|                                        ");
            mvwprintw(room,12,1,"_____________________________________|                                ________");
            mvwprintw(room,13,1,"____|                                                                |________");
            mvwprintw(room,14,1,"____|                                                                |________");
            mvwprintw(room,15,1,"____|                                                                |________");
            mvwprintw(room,16,1,"____|                                                                |________");
            mvwprintw(room,17,1,"____|                                                                |________");
            mvwprintw(room,18,1,"____|                                                                |________");
            mvwprintw(room,19,1,"____________________      ___________________________________________|________");
            mvwprintw(room,20,1,"____________________|    |____________________________________________________");
            mvwprintw(room,21,1,"____________________|    |____________________________________________________");
            mvwprintw(room,22,1,"____________________|    |____________________________________________________");

            //porta da uscire LEFT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.LeftExitOpen)
            {
                cord.columns = 22;
                cord.rows = 20;
                mvwhline(room,cord.rows,cord.columns,88,4);
            }
            else
            {
                cord.columns = 21;
                cord.rows = 19;
                mvwhline(room,cord.rows,cord.columns,' ',6);
            }
            doorx.LeftExitlocation.columns = cord.columns;
            doorx.LeftExitlocation.rows = cord.rows;

            //porta da uscire RIGHT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.RightExitOpen)
            {
                cord.columns = 70;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 71;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.RightExitlocation.columns = cord.columns;
            doorx.RightExitlocation.rows = cord.rows;

            //porta da cui è entrato
            cord.columns = 3;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',6);
            wrefresh(room);

        }
        if (x == 1)
        {
            coordinates cord;
            mvwprintw(room,1 ,1,"__|    |______________________________________________________________________");
            mvwprintw(room,2 ,1,"__|    |______________________________________________________________________");
            mvwprintw(room,3 ,1,"__|    |______|                                                 |_____________");
            mvwprintw(room,4 ,1,"__|    |______|                                                 |_____________");
            mvwprintw(room,5 ,1,"__|    |______|                                                 |_____L1______");
            mvwprintw(room,6 ,1,"__|                   _______________________________           |_____________");
            mvwprintw(room,7 ,1,"__|                  |_______________________________|                    |___");
            mvwprintw(room,8 ,1,"__|                  |_______________________________|                    |___");
            mvwprintw(room,9 ,1,"__|______            |_______________________________|                    |___");
            mvwprintw(room,10,1,"_________|           |_______________________________|                    |___");
            mvwprintw(room,11,1,"_________|           |_______________________________|                    |___");
            mvwprintw(room,12,1,"_________|           |_______________________________|                    |___");
            mvwprintw(room,13,1,"_________|           |_______________________________|                    |___");
            mvwprintw(room,14,1,"_________|           |_______________________________|                    |___");
            mvwprintw(room,15,1,"                     |_______________________________|                    |___");
            mvwprintw(room,16,1,"                                                             _____________|___");
            mvwprintw(room,17,1,"_________                                                   |_________________");
            mvwprintw(room,18,1,"_________|                                                  |_________________");
            mvwprintw(room,19,1,"_________|                                                  |_________________");
            mvwprintw(room,20,1,"_________|___________________________________      _________|_________________");
            mvwprintw(room,21,1,"_____________________________________________|    |___________________________");
            mvwprintw(room,22,1,"_____________________________________________|    |___________________________");

            //porta da uscire LEFT (6 spazi se oriz , 3 spazi se verti)
            if (!doorx.LeftExitOpen)
            {
                cord.columns = 10;
                cord.rows = 15;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 10;
                cord.rows = 15;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.LeftExitlocation.columns = cord.columns;
            doorx.LeftExitlocation.rows = cord.rows;

            //porta da uscire RIGHT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.RightExitOpen)
            {
                cord.columns = 46;
                cord.rows = 20;
                mvwhline(room,cord.rows,cord.columns,88,6);
            }
            else
            {
                cord.columns = 46;
                cord.rows = 20;
                mvwhline(room,cord.rows,cord.columns,' ',6);
            }
            doorx.RightExitlocation.columns = cord.columns;
            doorx.RightExitlocation.rows = cord.rows;

            //porta da cui è entrato
            cord.columns = 3;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',6);
            wrefresh(room);
        }
        if (x == 2)
        {
            coordinates cord;
            mvwprintw(room,1 ,1,"_____________________________________________________________|    |___________");
            mvwprintw(room,2 ,1,"_____________________________________________________________|    |___________");
            mvwprintw(room,3 ,1,"_______________________________________________________|          |___________"); 
            mvwprintw(room,4 ,1,"_______________________________________________________|            |_________");
            mvwprintw(room,5 ,1,"____|                                                               |_________");
            mvwprintw(room,6 ,1,"____|                                                               |_________");
            mvwprintw(room,7 ,1,"____|                                                               |___L2____");
            mvwprintw(room,8 ,1,"____|                                                               |_________");
            mvwprintw(room,9 ,1,"____|                                                               |_________");
            mvwprintw(room,10,1,"                                                                    |_________");
            mvwprintw(room,11,1,"                                                                    |_________");
            mvwprintw(room,12,1,"____________________________________                                |_________");
            mvwprintw(room,13,1,"____________________________________|                                         ");
            mvwprintw(room,14,1,"____________________________________|                                         ");
            mvwprintw(room,15,1,"____|                                                              ___________");
            mvwprintw(room,16,1,"____|                                                             |___________");
            mvwprintw(room,17,1,"____|                                                             |___________");
            mvwprintw(room,18,1,"____|_________________                         ___________________|___________");
            mvwprintw(room,19,1,"______________________|                       |______________|          |_____");
            mvwprintw(room,20,1,"______________________|                                                 |_____");
            mvwprintw(room,21,1,"______________________|                                                 |_____");
            mvwprintw(room,22,1,"______________________|_________________________________________________|_____");

            //porta da uscire LEFT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.LeftExitOpen)
            {
                cord.columns = 6;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 6;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.LeftExitlocation.columns = cord.columns;
            doorx.LeftExitlocation.rows = cord.rows;

            //porta da uscire RIGHT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.RightExitOpen)
            {
                cord.columns = 70;
                cord.rows = 13;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 70;
                cord.rows = 13;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.RightExitlocation.columns = cord.columns;
            doorx.RightExitlocation.rows = cord.rows;

            //porta da cui è entrato
            cord.columns = 62;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',6);
            wrefresh(room);
        }
        if (x == 3)
        {
            coordinates cord;
            mvwprintw(room,1 ,1,"______________________________________________________________________________");
            mvwprintw(room,2 ,1,"________________________________|                                          |__");
            mvwprintw(room,3 ,1,"______________________|                                                    |__"); 
            mvwprintw(room,4 ,1,"____L3_____________|                                                          ");
            mvwprintw(room,5 ,1,"___________________|                  ______________                          ");
            mvwprintw(room,6 ,1,"___________________|                 |______________|                      ___");
            mvwprintw(room,7 ,1,"___________________|                 |______________|                     |___");
            mvwprintw(room,8 ,1,"______________|                      |______________|                     |___");
            mvwprintw(room,9 ,1,"______________|                      |______________|                     |___");
            mvwprintw(room,10,1,"______________|                                                           |___");
            mvwprintw(room,11,1,"____|                                                       ______________|___");
            mvwprintw(room,12,1,"____|                                                      |__________________");
            mvwprintw(room,13,1,"____|           ______________                             |__________________");
            mvwprintw(room,14,1,"____|          |______________|                      ______|__________________");
            mvwprintw(room,15,1,"____|          |______________|                     |_________________________");
            mvwprintw(room,16,1,"____|          |______________|                     |_________________________");
            mvwprintw(room,17,1,"               |______________|                     |_________________________");
            mvwprintw(room,18,1,"                                                    |_________________________");
            mvwprintw(room,19,1,"____                                      __________|_________________________");
            mvwprintw(room,20,1,"____|_______________________________     |____________________________________");
            mvwprintw(room,21,1,"____________________________________|    |____________________________________");
            mvwprintw(room,22,1,"____________________________________|    |____________________________________");
            
            //porta da uscire LEFT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.LeftExitOpen)
            {
                cord.columns = 6;
                cord.rows = 17;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 6;
                cord.rows = 17;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.LeftExitlocation.columns = cord.columns;
            doorx.LeftExitlocation.rows = cord.rows;

            //porta da uscire RIGHT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.RightExitOpen)
            {
                cord.columns = 37;
                cord.rows = 20;
                mvwhline(room,cord.rows,cord.columns,88,6);
            }
            else
            {
                cord.columns = 37;
                cord.rows = 20;
                mvwhline(room,cord.rows,cord.columns,' ',6);
            }
            doorx.RightExitlocation.columns = cord.columns;
            doorx.RightExitlocation.rows = cord.rows;

            //porta da cui è entrato
            cord.columns = 79;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 4;
            doorx.entranceDlocation.rows = cord.rows;
            mvwvline(room,cord.rows,cord.columns,' ',3);
            wrefresh(room);
        }
        
}

void statistiche(WINDOW * win){     //per inizializzare la mappa delle statistiche
    box (win, 0, 0);
    mvwprintw(win, 2, 25, "VITA: ");
    mvwprintw(win, 2, 48, "SCORE: ");
}

void wavefunctioncollapse()
{

}