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
            //repeat until we reach a new point
//            x=1+rand() % BOARD_SIZE;
//            y=1+rand() % BOARD_SIZE;
//            while (std::count(p1.already_shoted.begin(), p1.already_shoted.end(), shot_coordinate) != 0 ) {
//                 count++;
//                 //if(count>BOARD_SIZE*BOARD_SIZE) throw "no empty square";
//                 if(count>1000) throw "no empty square";
//                 x=1+rand() % BOARD_SIZE;
//                 y=1+rand() % BOARD_SIZE;
//                shot_coordinate.setXY(x,y);

//            }
            shot_coordinate=p1.createRandomShot();
            x=shot_coordinate.x;
            y = shot_coordinate.y;
            p1.already_shoted.push_back(shot_coordinate);
            p1.message = "";

            if(p.pole[x][y].isShip()){
               //ship is wond or kil
               p.pole[x][y].wound(x,y);
               p1.message =  " wound an enemy ship\n";
               p.pole[x][y].setType(-2);
               if(p.pole[x][y].kil()){
                   p.decreaseShips();
                   //p.create_environment(p.pole[x][y].getDeck(),p.pole[x][y].getX(),p.pole[x][y].getY(),p.pole[x][y].getVert(),kilShip);
                  // p.printPole1();
               }

               //echo
               if(p.pole[x][y].getVert() == 1){
                   for(int i=1;p.pole[x][y+i].isShip();p.pole[x][y+i].wound(x,y),i++);
                   for(int i=1;p.pole[x][y-i].isShip();p.pole[x][y-i].wound(x,y),i++);
               }
               else{
                   for(int i=1;p.pole[x+i][y].isShip();p.pole[x+i][y].wound(x,y),i++);
                   for(int i=1;p.pole[x-i][y].isShip();p.pole[x-i][y].wound(x,y),i++);
               }
            }
            else    p1.message = " miss \n";
        }

    }
};

#endif // PLAYERSTRATEGYSIMPLE_H
