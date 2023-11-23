#ifndef GAMEALL_H
#define GAMEALL_H
#define BOARD_SIZE 10
#include "player.h"
#include "view.h"

class GameAll
{
public:
    Player p1;//("first player");
    Player p2;//("second player");
    Player activePlayer;
    Player passivePlayer;
    Player winner;
    View view;
    GameAll();
    void run();
   const char* getWinner();
};

#endif // GAMEALL_H
