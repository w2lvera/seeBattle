#ifndef GAMEALL_H
#define GAMEALL_H
#include "player.h"
#include "playerstrategheuristic.h"
#include "playerstrategysimple.h"
#include "playerstrategysuper.h"
#include "view.h"

class GameAll
{
public:
    Player p1;//("first player");
    Player p2;//("second player");
    Player activePlayer;
    Player passivePlayer;
    Player winner;
    PlayerStrategySimple* pss;
    PlayerStrategHeuristic* psh;
    PlayerStrategySuper* pssy;
    View view;
    GameAll();
    void run();
    const char* getWinner();
};

#endif // GAMEALL_H
