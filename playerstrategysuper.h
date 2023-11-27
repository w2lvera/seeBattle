#ifndef PLAYERSTRATEGYSYPER_H
#define PLAYERSTRATEGYSYPER_H
#include "player.h"

class PlayerStrategySuper:public PlayerStrategy
{
    friend class Player;
public:
    PlayerStrategySuper(){}
    virtual void shot(Player& p1,Player & p)override{
        {
            Point shot_coordinate;
            int x;
            int y;
            int count=0;
            //shoot
            if(p1.round!=0){//the ship is wound. Finishing off wound ship
                x=p1.pointWound.x;
                y=p1.pointWound.y;

                switch(p1.round){
                case 4:{
                    y++;
                    if(y>BOARD_SIZE)y-=2;
                    while(p.pole[x][y].getType()==-2)y++;
                    p1.round--;break;
                }
                case 3:{
                    y--;
                    if(y==0)y+=2;
                    while(p.pole[x][y].getType()==-2)y--;
                    p1.round--;break;
                }
                case 2:{
                    x--;
                    if(x==0)x+=2;
                    while(p.pole[x][y].getType()==-2)x++;
                    p1.round--;break;
                }
                case 1:{
                    x++;
                    if(x>BOARD_SIZE)x-=2;
                    while(p.pole[x][y].getType()==-2)x--;
                    p1.round--;break;
                }
                }
                shot_coordinate.setXY(x,y);
                p1.deleteIndex(x,y);
            }


            else{
                shot_coordinate=p1.createRandomShot();
                x = shot_coordinate.x;
                y = shot_coordinate.y;
            }

            p1.addShot(shot_coordinate);
            p1.message = "";

            if(p.pole[x][y].isShip()){
                //ship is wond or kil
                p.pole[x][y].wound(x,y);
                p1.round=4;
                p1.pointWound.setXY(x,y);
                p1.message =  " wound an enemy ship\n";
                p.pole[x][y].setType(-2);
                if(p.pole[x][y].kil()){
                    p.decreaseShips();
                    p1.round=0;
                    //delete environment of kil ship
                    p1.delete_environment(p.pole[x][y].getDeck(),p.pole[x][y].getX()
                                          ,p.pole[x][y].getY(),p.pole[x][y].getHorizontal());

                }

                //echo decrease deck in all square of wound ship
                if(p.pole[x][y].getHorizontal() == 1){
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

#endif // PLAYERSTRATEGYSYPER_H
