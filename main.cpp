#include"map.hpp"

int main()
{
    bool exit = menu(); 
    
    if (exit){
        endwin();
    }
    else{
        map(exit);
    }
}