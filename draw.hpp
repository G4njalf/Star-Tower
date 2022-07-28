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
            mvwhline(room,cord.rows,cord.columns,' ',7);
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
            mvprintw(7 ,1,"__|                |_________________________________|                        ");
            mvprintw(8 ,1,"__|                |_________________________________|                        ");
            mvprintw(9 ,1,"__|______          |_________________________________|                 _______");
            mvprintw(10,1,"_________|         |_________________________________|                |_______");
            mvprintw(11,1,"_________|         |_________________________________|                |_______");
            mvprintw(12,1,"_________|         |_________________________________|                |_______");
            mvprintw(13,1,"_________|         |_________________________________|                |_______");
            mvprintw(14,1,"_________|         |_________________________________|                |_______");
            mvprintw(15,1,"_________|         |_________________________________|                |_______");
            mvprintw(16,1,"_________|         |_________________________________|       _________|_______");
            mvprintw(17,1,"_________|                                                  |_________________");
            mvprintw(18,1,"_________|                                                  |_________________");
            mvprintw(19,1,"_________|__________      __________________________________|_________________");
            mvprintw(20,1,"____________________|    |____________________________________________________");
            mvprintw(21,1,"____________________|    |____________________________________________________");
            mvprintw(22,1,"____________________|    |____________________________________________________");
            //porta da uscire LEFT (6 spazi se oriz , 4 spazi se verti)
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
                cord.rows = 7;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 79;
                cord.rows = 7;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.RightExitlocation.columns = cord.columns;
            doorx.RightExitlocation.rows = cord.rows;

            //porta da cui è entrato
            cord.columns = 3;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',7);
            wrefresh(room);
        }
}

void wavefunctioncollapse()
{

}
