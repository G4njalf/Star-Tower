#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
  public :
     Player(WINDOW *win, int y, int x, char c);

      void mvup();
      void mvdown();
      void mvleft();
      void mvright();
      int  getmv();

      int getplx();
      int getply();
      void display();

      private:
         int xLoc, yLoc, xMax, yMax;
         char character;
         WINDOW * curwin;
};

Player::Player(WINDOW * win, int y, int x, char c)
{
   curwin = win;
   yLoc = y;
   xLoc = x;
   getmaxyx(curwin, yMax, xMax);
   keypad(curwin, true);
   character = c;
}








void Player::mvup()
{
   mvwaddch(curwin, yLoc, xLoc, ' ');
   yLoc--;
   if(yLoc<1)
   yLoc = 1;
	mvwaddch(curwin, yLoc, xLoc, character);

}
void Player::mvdown()
{
   mvwaddch(curwin, yLoc, xLoc, ' ');
   yLoc++;
   if(yLoc > yMax-2)
   yLoc = yMax-2;
	mvwaddch(curwin, yLoc, xLoc, character);

}
void Player::mvleft()
{
   mvwaddch(curwin, yLoc, xLoc, ' ');
   xLoc--;
   if(xLoc < 1 )
    xLoc = 1;
	mvwaddch(curwin, yLoc, xLoc, character);
}
void Player::mvright()
{
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc > xMax-2)
    xLoc = xMax-2;
	mvwaddch(curwin, yLoc, xLoc, character);
}


int Player::getmv()
	{
  int choice= wgetch(curwin);
  switch(choice)
    {
      case KEY_UP:
        mvup();
	wrefresh(curwin);
         break;
      case KEY_DOWN:
        mvdown();
	wrefresh(curwin);
         break;
      case KEY_LEFT:
        mvleft();
	wrefresh(curwin);
         break;
      case KEY_RIGHT:
        mvright();
	wrefresh(curwin);
         break;
       default:
         break;
 }
  return choice;
}





void Player::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);
	wrefresh(curwin);
}
int  Player::getplx(){return (xLoc);}
int  Player::getply(){return (yLoc);}
#endif



























