#define _PLAYER_H_
#include "artifacts.hpp"

struct personaggio{
    int bx;
    int by;
    int id;
    personaggio *next;
};

typedef personaggio *lpersonaggio;

class Player
{
public :
    Player(WINDOW *win, int y, int x, char c, int firerate, int h, int bd, int Score);

    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int  getmv();
    void addbullet();
    void remove_bullet();
    void addblank();
    void remove_blank();
    void stampa_bullets();
    void display();
    void mvup2();
    void mvdown2();
    void mvleft2();
    void mvright2();
    void healtup(artifact * h);
    void damage(int dm);
    int currentlife();
    int currentY();
    int currentX();
    int currdamage();
    void print_score();
    int cscore();
    void add_score();

protected:
    int xLoc, yLoc, xMax, yMax, xb, yb, identity, counter, firerate;
    bool flag;
    int healt, bulldamage;
    char character;
    WINDOW * curwin;
    lpersonaggio  p ;
    lpersonaggio  b ;
    int score;

};

Player::Player(WINDOW * win, int y, int x, char c, int firerate, int h, int bd, int Score)
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
    p = NULL;
    this->firerate = firerate;
    counter= firerate;
    flag = true;
    healt = h;
    bulldamage = bd;
    score=Score;
}


void Player :: healtup (artifact * h){            //funzioni usate per l'interazione col personaggio
    if (h->collected(yLoc, xLoc)){
        healt = healt + 50;
    }
}
void Player :: damage (int d){
    healt = healt - d;
}

int Player :: currentlife() {
    return healt;
}

int Player :: currentY(){
    return yLoc;
}

int Player ::currentX() {
    return xLoc;
}

int Player ::currdamage() {
    return bulldamage;
}

void Player :: mvup2() {
    int tmp = yLoc;
    bool check;
    for (int j=3; j>0; j--){
        if(tmp==j){
            check=true;
        }
    }
    if(!check){
        for (int i=0; i<3; i++) {
            tmp--;
            if (mvwinch(curwin, tmp, xLoc) == 95 || mvwinch(curwin, tmp, xLoc) == 124) {
                i = 5;
            }
            else {
                mvwaddch(curwin, yLoc, xLoc, ' ');
                yLoc--;
                mvwaddch(curwin, yLoc, xLoc, 'o');
                wrefresh(curwin);
                napms(100);
            }
        }
    }
}

void Player:: mvdown2() {
    int tmp = yLoc;
    bool check;
    for (int j=20; j<24; j++){
        if(tmp==j){
            check=true;
        }
    }
    if(!check){
        for (int i=0; i<3; i++) {
            tmp++;
            if (mvwinch(curwin, tmp, xLoc) == 95 || mvwinch(curwin, tmp, xLoc) == 124) {
                i = 5;
            }
            else {
                mvwaddch(curwin, yLoc, xLoc, ' ');
                yLoc++;
                mvwaddch(curwin, yLoc, xLoc, 'o');
                wrefresh(curwin);
                napms(100);
            }
        }
    }
}

void Player:: mvright2() {
    int tmp = xLoc;
    bool check;
    for (int j=76; j<80; j++){
        if(tmp==j){
            check=true;
        }
    }
    if(!check){
        for (int i=0; i<3; i++) {
            tmp++;
            if (mvwinch(curwin, yLoc, tmp) == 95 || mvwinch(curwin, yLoc, tmp) == 124) {
                i = 5;
            }
            else {
                mvwaddch(curwin, yLoc, xLoc, ' ');
                xLoc++;
                mvwaddch(curwin, yLoc, xLoc, 'o');
                wrefresh(curwin);
                napms(100);
            }
        }
    }
}

void Player:: mvleft2() {
    int tmp = xLoc;
    bool check;
    for (int j = 3; j > 0; j--) {
        if (tmp == j) {
            check = true;
        }
    }
    if (!check) {
        for (int i = 0; i < 3; i++) {
            tmp--;
            if (mvwinch(curwin, yLoc, tmp) == 95 || mvwinch(curwin, yLoc, tmp) == 124) {
                i = 5;
            } else {
                mvwaddch(curwin, yLoc, xLoc, ' ');
                xLoc--;
                mvwaddch(curwin, yLoc, xLoc, 'o');
                wrefresh(curwin);
                napms(100);
            }
        }
    }
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
        case 'w':
            if(mvwinch(curwin, yLoc-1 , xLoc)!=124 && mvwinch(curwin, yLoc-1 , xLoc)!=95){
                mvup();}
            break;
        case 's':
            if(mvwinch(curwin, yLoc+1 , xLoc)!=124 && mvwinch(curwin, yLoc+1 , xLoc)!=95){
                mvdown();}
            break;
        case 'a':
            if(mvwinch(curwin, yLoc , xLoc-1)!=124 && mvwinch(curwin, yLoc , xLoc-1)!=95){
                mvleft();}
            break;
        case 'd':
            if(mvwinch(curwin, yLoc , xLoc+1)!=124 && mvwinch(curwin, yLoc , xLoc+1)!=95){
                mvright();}
            break;
        case KEY_UP:
            mvwaddch(curwin, yLoc, xLoc, character);
            if(counter==firerate){
                xb = xLoc;
                yb = yLoc-1;
                identity =  1 ;
                addbullet();
                addblank();}
                flag=true;
            break;
        case KEY_LEFT:
            mvwaddch(curwin, yLoc, xLoc, character);
            if(counter==firerate){
                xb = xLoc-1;
                yb = yLoc;
                identity =  2 ;
                addbullet();
                addblank();}
                flag=true;
            break;
        case KEY_DOWN:
            mvwaddch(curwin, yLoc, xLoc, character);
            if(counter==firerate){
                xb = xLoc;
                yb = yLoc+1;
                identity =  3 ;
                addbullet();
                addblank();}
                flag=true;
            break;
        case KEY_RIGHT:
            mvwaddch(curwin, yLoc, xLoc, character);
            if(counter==firerate){
                xb = xLoc+1;
                yb = yLoc;
                identity =  4 ;
                addbullet();
                addblank();}
                flag=true;
            break;
        case 'W':
            mvup2();
            break;
        case 'S':
            mvdown2();
            break;
        case 'D':
            mvright2();
            break;
        case 'A':
            mvleft2();
            break;
        default:
            break;
    }
    stampa_bullets();
    if(counter!=firerate){counter++;}
    if(counter==firerate && flag){
        counter=0;
    }
    flag=false;

    return choice;
}



void Player::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);
    wrefresh(curwin);
}


void Player:: addbullet(){
    lpersonaggio tmp = p;
    if(p==NULL){
        if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
            p = new personaggio;
            p->bx=xb;
            p->by=yb;
            p->id = identity;
            p->next = NULL;
        }
    }
    else{
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
            tmp->next = new personaggio;
            tmp = tmp->next;
            tmp->bx=xb;
            tmp->by=yb;
            tmp->id = identity;
            tmp->next = NULL;
        }
    }

}

void Player:: remove_bullet(){
    lpersonaggio aux = p;
    lpersonaggio prec = NULL;
    lpersonaggio tmp;
    int bbx, bby;
    while(aux!=NULL){
        bby = aux->by;
        bbx = aux->bx;
        if(mvwinch(curwin, bby , bbx)==124 ||mvwinch(curwin, bby , bbx)==95){
            tmp = aux;
            if(prec == NULL){
                p = p->next ;
            }else {
                prec->next = aux->next ;
            }
            aux = aux->next;
            delete (tmp);
        }
        else{
            prec = aux ;
            aux = aux->next ;
        }
    }

}


void Player:: stampa_bullets(){
    lpersonaggio tmp = p;
    while (tmp!=NULL){
        if(tmp->id == 1 ){
            mvwaddch(curwin, tmp->by, tmp->bx, '.');
            tmp->by--;
        }
        else if(tmp->id == 2 ){
            mvwaddch(curwin, tmp->by, tmp->bx, '.');
            tmp->bx--;
        }
        else if(tmp->id == 3 ){
            mvwaddch(curwin, tmp->by, tmp->bx, '.');
            tmp->by++;
        }
        else if(tmp->id == 4 ){
            mvwaddch(curwin, tmp->by, tmp->bx, '.');
            tmp->bx++;
        }
        tmp = tmp->next ;
    }
    remove_bullet();
    tmp = b;
    while (tmp!=NULL){
        if(tmp->id == 1 ){
            if(tmp->by!=yLoc || tmp->bx!=xLoc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
            }
            tmp->by--;
        }
        else if(tmp->id == 2 ){
            if(tmp->by!=yLoc || tmp->bx!=xLoc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
            }
            tmp->bx--;
        }
        else if(tmp->id == 3 ){
            if(tmp->by!=yLoc || tmp->bx!=xLoc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
            }
            tmp->by++;
        }
        else if(tmp->id == 4 ){
            if(tmp->by!=yLoc || tmp->bx!=xLoc){
                mvwaddch(curwin, tmp->by, tmp->bx, ' ');
            }
            tmp->bx++;
        }
        tmp = tmp->next ;
    }
    remove_blank();
}



void Player:: remove_blank(){
    lpersonaggio aux = b;
    lpersonaggio prec = NULL;
    lpersonaggio tmp;
    int bbx, bby;
    while(aux!=NULL){
        bby = aux->by;
        bbx = aux->bx;
        if(mvwinch(curwin, bby , bbx)==124 ||mvwinch(curwin, bby , bbx)==95){
            tmp = aux;
            if(prec == NULL){
                b = b->next ;
            }else {
                prec->next = aux->next ;
            }
            aux = aux->next;
            delete (tmp);
        }
        else{
            prec = aux ;
            aux = aux->next ;
        }
    }

}

void Player:: addblank(){
    lpersonaggio tmp = b;
    if(b==NULL){
        if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
            b = new personaggio;
            b->bx=xLoc;
            b->by=yLoc;
            b->id = identity;
            b->next = NULL;
        }
    }
    else{
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        if(mvwinch(curwin, yb , xb)!=124 ||mvwinch(curwin, yb , xb)!=95){
            tmp->next = new personaggio;
            tmp = tmp->next;
            tmp->bx=xLoc;
            tmp->by=yLoc;
            tmp->id = identity;
            tmp->next = NULL;
        }
    }
}

    void Player:: print_score(){
        mvwprintw(curwin, 23, 12, "SCORE: ");
        mvwprintw(curwin, 23, 19, "%d", score);
    }

    int Player:: cscore(){
        return score;
    };

    void Player:: add_score(){
        score=score+100;
    }
