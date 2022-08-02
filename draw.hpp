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
            mvprintw(1 ,1,"__|     |_____________________________________________________________________");
            mvprintw(2 ,1,"__|     |_____________________________________________________________________");
            mvprintw(3 ,1,"__|     |_____|                                           |___________________");
            mvprintw(4 ,1,"__|     |_____|                                           |___________________");
            mvprintw(5 ,1,"__|     |_____|     _________________________________     |___________________");
            mvprintw(6 ,1,"__|     |_____|    |_________________________________|    |___________________");
            mvprintw(7 ,1,"__|                |_________________________________|    |___________________");
            mvprintw(8 ,1,"__|                |_________________________________|    |___________________");
            mvprintw(9 ,1,"__|________________|_________________________________|    |___________________");
            mvprintw(10,1,"_____________________________________________________|                        ");
            mvprintw(11,1,"_____________________________________________________|                        ");
            mvprintw(12,1,"_____________________________________________________|     ___________________");
            mvprintw(13,1,"_____________________________________________________|    |___________________");
            mvprintw(14,1,"_____________________________________________________|    |___________________");
            mvprintw(15,1,"_____________________________________________________|    |___________________");
            mvprintw(16,1,"_____________________________________________________|    |___________________");
            mvprintw(17,1,"____________________|                                     |___________________");
            mvprintw(18,1,"____________________|                                     |___________________");
            mvprintw(19,1,"____________________|     ________________________________|___________________");
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
            mvprintw(1 ,1,"__|     |_____________________________________________________________________");
            mvprintw(2 ,1,"__|     |_____________________________________________________________________");
            mvprintw(3 ,1,"__|     |_____|                                             |_________________");
            mvprintw(4 ,1,"__|     |_____|                                             |_________________");
            mvprintw(5 ,1,"__|     |_____|     _________________________________       |_________________");
            mvprintw(6 ,1,"__|     |_____|    |_________________________________|      |_________________");
            mvprintw(7 ,1,"__|                |_________________________________|                |_______");
            mvprintw(8 ,1,"__|                |_________________________________|                |_______");
            mvprintw(9 ,1,"__|______          |_________________________________|                |_______");
            mvprintw(10,1,"_________|         |_________________________________|                |_______");
            mvprintw(11,1,"_________|         |_________________________________|                |_______");
            mvprintw(12,1,"_________|         |_________________________________|                |_______");
            mvprintw(13,1,"_________|         |_________________________________|                |_______");
            mvprintw(14,1,"_________|         |_________________________________|                |_______");
            mvprintw(15,1,"                   |_________________________________|                |_______");
            mvprintw(16,1,"                   |_________________________________|       _________|_______");
            mvprintw(17,1,"_________                                                   |_________________");
            mvprintw(18,1,"_________|                                                  |_________________");
            mvprintw(19,1,"_________|___________________________________      _________|_________________");
            mvprintw(20,1,"_____________________________________________|    |___________________________");
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
            mvprintw(3 ,1,"_____________________________________________________________|    |___________"); 
            mvprintw(4 ,1,"_____________________________________________________________|    |___________");
            mvprintw(5 ,1,"____|                                                             |___________");
            mvprintw(6 ,1,"____|                                                             |___________");
            mvprintw(7 ,1,"____|                                                             |___________");
            mvprintw(8 ,1,"____|                                                             |___________");
            mvprintw(9 ,1,"____|                                                             |___________");
            mvprintw(10,1,"                                                                  |___________");
            mvprintw(11,1,"                                                                  |___________");
            mvprintw(12,1,"___________________________________________________               |___________");
            mvprintw(13,1,"___________________________________________________|                          ");
            mvprintw(14,1,"___________________________________________________|                          ");
            mvprintw(15,1,"____|                                                              ___________");
            mvprintw(16,1,"____|                                                             |___________");
            mvprintw(17,1,"____|                                                             |___________");
            mvprintw(18,1,"____|_______________________________      ________________________|___________");
            mvprintw(19,1,"____________________________________|    |___________________|          |_____");
            mvprintw(20,1,"____________________________________|                                   |_____");
            mvprintw(21,1,"____________________________________|                                   |_____");
            mvprintw(22,1,"____________________________________|___________________________________|_____");

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
        if (x == 3)
        {
            coordinates cord;
            mvprintw(1 ,1,"______________________________________________________________________________");
            mvprintw(2 ,1,"______________________________________________________________________________");
            mvprintw(3 ,1,"_________________________________________|                                 |__"); 
            mvprintw(4 ,1,"_________________________________________|                                    ");
            mvprintw(5 ,1,"_________________________________________|          ______________            ");
            mvprintw(6 ,1,"_________________________________________|         |______________|        ___");
            mvprintw(7 ,1,"_________________________________________|         |______________|       |___");
            mvprintw(8 ,1,"________________________________|                  |______________|       |___");
            mvprintw(9 ,1,"________________________________|                  |______________|       |___");
            mvprintw(10,1,"________________________________|                                         |___");
            mvprintw(11,1,"____                                                   ___________________|___");
            mvprintw(12,1,"____|                                                 |_______________________");
            mvprintw(13,1,"____|       ______________                            |_______________________");
            mvprintw(14,1,"____|      |______________|               ____________|_______________________");
            mvprintw(15,1,"____|      |______________|              |____________________________________");
            mvprintw(16,1,"____|      |______________|              |____________________________________");
            mvprintw(17,1,"           |______________|              |____________________________________");
            mvprintw(18,1,"                                         |____________________________________");
            mvprintw(19,1,"____                                     |____________________________________");
            mvprintw(20,1,"____|_______________________________     |____________________________________");
            mvprintw(21,1,"____________________________________|    |____________________________________");

            
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
}

void wavefunctioncollapse()
{

}
