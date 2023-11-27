
#include <stdio.h>
#include "gameall.h"
int main(){
   GameAll gameAll;
   gameAll.run();
    printf("\n winner is %s                               ",gameAll.getWinner());
    return 0;
}
