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
            mvprintw(1 ,1,"__|    |______________________________________________________________________");
            mvprintw(2 ,1,"__|    |______________________________________________________________________");
            mvprintw(3 ,1,"__|    |______|                                                     |_________");
            mvprintw(4 ,1,"__|    |______|                                                     |_________");
            mvprintw(5 ,1,"__|    |______|     _________________                               |_________");
            mvprintw(6 ,1,"__|    |______|    |_________________|                              |_________");
            mvprintw(7 ,1,"__|                |_________________|                              |_________");
            mvprintw(8 ,1,"__|                |_________________|                              |_________");
            mvprintw(9 ,1,"__|________________|_________________|                              |_________");
            mvprintw(10,1,"_____________________________________|                                        ");
            mvprintw(11,1,"_____________________________________|                                        ");
            mvprintw(12,1,"_____________________________________|                                ________");
            mvprintw(13,1,"____|                                                                |________");
            mvprintw(14,1,"____|                                                                |________");
            mvprintw(15,1,"____|                                                                |________");
            mvprintw(16,1,"____|                                                                |________");
            mvprintw(17,1,"____|                                                                |________");
            mvprintw(18,1,"____|                                                                |________");
            mvprintw(19,1,"____________________      ___________________________________________|________");
            mvprintw(20,1,"____________________|    |____________________________________________________");
            mvprintw(21,1,"____________________|    |____________________________________________________");
            mvprintw(22,1,"____________________|    |____________________________________________________");
            //porta da uscire LEFT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.LeftExitOpen)
            {
                cord.columns = 21;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,88,6);
            }
            else
            {
                cord.columns = 21;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,' ',6);
            }
            doorx.LeftExitlocation.columns = cord.columns;
            doorx.LeftExitlocation.rows = cord.rows;

            //porta da uscire RIGHT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.RightExitOpen)
            {
                cord.columns = 79;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 79;
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
            mvprintw(1 ,1,"__|    |______________________________________________________________________");
            mvprintw(2 ,1,"__|    |______________________________________________________________________");
            mvprintw(3 ,1,"__|    |______|                                                 |_____________");
            mvprintw(4 ,1,"__|    |______|                                                 |_____________");
            mvprintw(5 ,1,"__|    |______|                                                 |_____________");
            mvprintw(6 ,1,"__|                   _______________________________           |_____________");
            mvprintw(7 ,1,"__|                  |_______________________________|                    |___");
            mvprintw(8 ,1,"__|                  |_______________________________|                    |___");
            mvprintw(9 ,1,"__|______            |_______________________________|                    |___");
            mvprintw(10,1,"_________|           |_______________________________|                    |___");
            mvprintw(11,1,"_________|           |_______________________________|                    |___");
            mvprintw(12,1,"_________|           |_______________________________|                    |___");
            mvprintw(13,1,"_________|           |_______________________________|                    |___");
            mvprintw(14,1,"_________|           |_______________________________|                    |___");
            mvprintw(15,1,"                     |_______________________________|                    |___");
            mvprintw(16,1,"                                                             _____________|___");
            mvprintw(17,1,"_________                                                   |_________________");
            mvprintw(18,1,"_________|                                                  |_________________");
            mvprintw(19,1,"_________|                                                  |_________________");
            mvprintw(20,1,"_________|___________________________________      _________|_________________");
            mvprintw(21,1,"_____________________________________________|    |___________________________");
            mvprintw(22,1,"_____________________________________________|    |___________________________");
            //porta da uscire LEFT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.LeftExitOpen)
            {
                cord.columns = 0;
                cord.rows = 15;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 0;
                cord.rows = 15;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.LeftExitlocation.columns = cord.columns;
            doorx.LeftExitlocation.rows = cord.rows;

            //porta da uscire RIGHT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.RightExitOpen)
            {
                cord.columns = 46;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,88,6);
            }
            else
            {
                cord.columns = 46;
                cord.rows = 23;
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
            mvprintw(1 ,1,"_____________________________________________________________|    |___________");
            mvprintw(2 ,1,"_____________________________________________________________|    |___________");
            mvprintw(3 ,1,"_______________________________________________________|          |___________"); 
            mvprintw(4 ,1,"_______________________________________________________|            |_________");
            mvprintw(5 ,1,"____|                                                               |_________");
            mvprintw(6 ,1,"____|                                                               |_________");
            mvprintw(7 ,1,"____|                                                               |_________");
            mvprintw(8 ,1,"____|                                                               |_________");
            mvprintw(9 ,1,"____|                                                               |_________");
            mvprintw(10,1,"                                                                    |_________");
            mvprintw(11,1,"                                                                    |_________");
            mvprintw(12,1,"____________________________________                                |_________");
            mvprintw(13,1,"____________________________________|                                         ");
            mvprintw(14,1,"____________________________________|                                         ");
            mvprintw(15,1,"____|                                                              ___________");
            mvprintw(16,1,"____|                                                             |___________");
            mvprintw(17,1,"____|                                                             |___________");
            mvprintw(18,1,"____|_________________                         ___________________|___________");
            mvprintw(19,1,"______________________|                       |______________|          |_____");
            mvprintw(20,1,"______________________|                                                 |_____");
            mvprintw(21,1,"______________________|                                                 |_____");
            mvprintw(22,1,"______________________|_________________________________________________|_____");

            //porta da uscire LEFT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.LeftExitOpen)
            {
                cord.columns = 0;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 0;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.LeftExitlocation.columns = cord.columns;
            doorx.LeftExitlocation.rows = cord.rows;

            //porta da uscire RIGHT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.RightExitOpen)
            {
                cord.columns = 79;
                cord.rows = 13;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 79;
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
            mvprintw(1 ,1,"______________________________________________________________________________");
            mvprintw(2 ,1,"________________________________|                                          |__");
            mvprintw(3 ,1,"______________________|                                                    |__"); 
            mvprintw(4 ,1,"___________________|                                                          ");
            mvprintw(5 ,1,"___________________|                  ______________                          ");
            mvprintw(6 ,1,"___________________|                 |______________|                      ___");
            mvprintw(7 ,1,"___________________|                 |______________|                     |___");
            mvprintw(8 ,1,"______________|                      |______________|                     |___");
            mvprintw(9 ,1,"______________|                      |______________|                     |___");
            mvprintw(10,1,"______________|                                                           |___");
            mvprintw(11,1,"____|                                                       ______________|___");
            mvprintw(12,1,"____|                                                      |__________________");
            mvprintw(13,1,"____|           ______________                             |__________________");
            mvprintw(14,1,"____|          |______________|                      ______|__________________");
            mvprintw(15,1,"____|          |______________|                     |_________________________");
            mvprintw(16,1,"____|          |______________|                     |_________________________");
            mvprintw(17,1,"               |______________|                     |_________________________");
            mvprintw(18,1,"                                                    |_________________________");
            mvprintw(19,1,"____                                      __________|_________________________");
            mvprintw(20,1,"____|_______________________________     |____________________________________");
            mvprintw(21,1,"____________________________________|    |____________________________________");
            mvprintw(22,1,"____________________________________|    |____________________________________");

            
            //porta da uscire LEFT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.LeftExitOpen)
            {
                cord.columns = 0;
                cord.rows = 17;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 0;
                cord.rows = 17;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.LeftExitlocation.columns = cord.columns;
            doorx.LeftExitlocation.rows = cord.rows;

            //porta da uscire RIGHT (6 spazi se oriz , 3 spazi se verti)
           if (!doorx.RightExitOpen)
            {
                cord.columns = 37;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,88,6);
            }
            else
            {
                cord.columns = 37;
                cord.rows = 23;
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

void wavefunctioncollapse()
{

}
