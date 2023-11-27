#ifndef PLAYERSTRATEGYSIMPLE_H
#define PLAYERSTRATEGYSIMPLE_H
#include "player.h"
#include "playerstrategy.h"

class PlayerStrategySimple:public PlayerStrategy
{
     friend class Player;
public:
    PlayerStrategySimple(){}
      void shot(Player& p1,Player & p)override{
        {
            Point shot_coordinate;
            int x;
            int y;
            int count=0;
            //shot
            shot_coordinate=p1.createRandomShot();
            x=shot_coordinate.x;
            y = shot_coordinate.y;
            p1.addShot(shot_coordinate);
            p1.message = "";
            //check shot
            if(p.pole[x][y].isShip()){
               //ship is wond or kil
               p.pole[x][y].wound(x,y);
               p1.message =  " wound an enemy ship\n";
               p.pole[x][y].setType(-2);
               if(p.pole[x][y].kil()){
                   p.decreaseShips();

               }

               //echo
               if(p.pole[x][y].getHorizontal() == 1){
                   for(int i=1;p.pole[x][y+i].isShip();p.pole[x][y+i].wound(x,y),i++);
                   for(int i=1;p.pole[x][y-i].isShip();p.pole[x][y-i].wound(x,y),i++);
               }
               else{
                   for(int i=1;p.pole[x+i][y].isShip();p.pole[x+i][y].wound(x,y),i++);
                   for(int i=1;p.pole[x-i][y].isShip();p.pole[x-i][y].wound(x,y),i++);
               }
            }
            //no ship
            else    p1.message = " miss \n";
        }

    }
};

#endif // PLAYERSTRATEGYSIMPLE_H
