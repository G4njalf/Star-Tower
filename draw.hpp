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
    coordinates exitDlocation; //locazione della porta di uscita
    bool exitDisOpen; // true = si    
};

void layouts(int x, WINDOW* room, coordinates cord, door doorx)
{
    if (x == 0)
        {

            //muri
            cord.columns = 26;
            cord.rows = 1;    
            mvwvline(room,cord.rows,cord.columns,0,8); //muovi poi disegni riga verticale nella finestra (fuori non si vede)
            mvwvline(room,cord.rows+3,cord.columns+26,0,8);
            cord.columns = 39;
            cord.rows = 12;
            mvwvline(room,cord.rows,cord.columns,0,11);
            cord.columns = 27;
            cord.rows = 12;
            mvwhline(room,cord.rows,cord.columns,0,25);
            //porta da uscire
            if (!doorx.exitDisOpen)
            {
                cord.columns = 42;
                doorx.exitDlocation.columns = cord.columns;
                cord.rows = 23;
                doorx.exitDlocation.rows = cord.rows;
                mvwhline(room,cord.rows,cord.columns,88,5);
            }
            else
            {
                cord.columns = 42;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,' ',5);
            }
            //porta da cui è entrato
            cord.columns = 10;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 23;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',5);
            wrefresh(room);
        } 
        if (x == 1)
        {
            //muri
            coordinates cord;
            cord.columns = 1;
            cord.rows = 12;    
            mvwhline(room,cord.rows,cord.columns,0,78-5);
            cord.columns = 40;
            cord.rows = 1+3;    
            mvwvline(room,cord.rows,cord.columns,0,23-6);

            //porta da uscire (5 spazi se hor , 3 spazi se ver)
            if (!doorx.exitDisOpen)
            {
                cord.columns = 10;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,88,5);
            }
            else
            {
                cord.columns = 10;
                cord.rows = 23;
                mvwhline(room,cord.rows,cord.columns,' ',5);
            }
            doorx.exitDlocation.columns = cord.columns;
            doorx.exitDlocation.rows = cord.rows;
            //porta da cui è entrato
            cord.columns = 10;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',5);
            wrefresh(room);    
        }
        if (x == 2)
        {
            //muri
            coordinates cord;
            cord.columns = 27;
            cord.rows = 1;    
            mvwvline(room,cord.rows,cord.columns,0,12);
            cord.columns = 53;
            cord.rows = 12;    
            mvwvline(room,cord.rows,cord.columns,0,11);

            //porta da uscire (5 spazi se oriz , 3 spazi se verti)
            if (!doorx.exitDisOpen)
            {
                cord.columns = 79;
                cord.rows = 10;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 79;
                cord.rows = 10;
                mvwhline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.exitDlocation.columns = cord.columns;
            doorx.exitDlocation.rows = cord.rows;
            //porta da cui è entrato
            cord.columns = 0;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 10;
            doorx.entranceDlocation.rows = cord.rows;
            mvwvline(room,cord.rows,cord.columns,' ',3);
            wrefresh(room);
        }
        if (x == 3)
        {
            //muri
            coordinates cord;
            cord.columns = 1;
            cord.rows = 3;
            mvwhline(room,cord.rows,cord.columns,0,69);
            cord.columns = 70;
            cord.rows = 4;
            mvwvline(room,cord.rows,cord.columns,0,4);
            cord.columns = 11;
            cord.rows = 8;
            mvwhline(room,cord.rows,cord.columns,0,59);
            cord.columns = 11;
            cord.rows = 8+4;
            mvwhline(room,cord.rows,cord.columns,0,69);
            cord.columns = 11;
            cord.rows = 8+4+4;
            mvwhline(room,cord.rows,cord.columns,0,59);
            cord.columns = 10;
            cord.rows = 17;
            mvwvline(room,cord.rows,cord.columns,0,6);

            //porta da uscire (5 spazi se oriz , 3 spazi se verti)
            if (!doorx.exitDisOpen)
            {
                cord.columns = 79;
                cord.rows = 18;
                mvwvline(room,cord.rows,cord.columns,88,3);
            }
            else
            {
                cord.columns = 79;
                cord.rows = 18;
                mvwvline(room,cord.rows,cord.columns,' ',3);
            }
            doorx.exitDlocation.columns = cord.columns;
            doorx.exitDlocation.rows = cord.rows;
            //porta da cui è entrato
            cord.columns = 0;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwvline(room,cord.rows,cord.columns,' ',3);
            wrefresh(room);
        }
        if (x == 4)
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
            mvprintw(10,1,"_____________________________________________________|    |___________________");
            mvprintw(11,1,"_____________________________________________________|    |___________________");
            mvprintw(12,1,"_____________________________________________________|    |___________________");
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
            //porta da uscire (5 spazi se oriz , 3 spazi se verti)
           if (!doorx.exitDisOpen)
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
            doorx.exitDlocation.columns = cord.columns;
            doorx.exitDlocation.rows = cord.rows;

            //porta da cui è entrato
            cord.columns = 3;
            doorx.entranceDlocation.columns = cord.columns;
            cord.rows = 0;
            doorx.entranceDlocation.rows = cord.rows;
            mvwhline(room,cord.rows,cord.columns,' ',7);
            wrefresh(room);

        }
        if (x == 5)
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
            mvprintw(15,1,"_________|         |_________________________________|                |_______");
            mvprintw(16,1,"_________|         |_________________________________|       _________|_______");
            mvprintw(17,1,"_________|                                                  |_________________");
            mvprintw(18,1,"_________|                                                  |_________________");
            mvprintw(19,1,"_________|__________      __________________________________|_________________");
            mvprintw(20,1,"____________________|    |____________________________________________________");
            mvprintw(21,1,"____________________|    |____________________________________________________");
            mvprintw(22,1,"____________________|    |____________________________________________________");
            //porta da uscire (5 spazi se oriz , 3 spazi se verti)
           if (!doorx.exitDisOpen)
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
            doorx.exitDlocation.columns = cord.columns;
            doorx.exitDlocation.rows = cord.rows;

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
