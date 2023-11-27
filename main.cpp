
#include <stdio.h>
#include <time.h>
#include "gameall.h"
int main(){
    srand(time(NULL));
   GameAll gameAll;
   gameAll.run();
    printf("\n winner is %s                               ",gameAll.getWinner());
    return 0;
}
