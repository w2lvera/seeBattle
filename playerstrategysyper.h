#ifndef PLAYERSTRATEGYSYPER_H
#define PLAYERSTRATEGYSYPER_H
#include "player.h"

class PlayerStrategySyper:public PlayerStrategy
{
     friend class Player;
public:
    PlayerStrategySyper(){}
    virtual void shot(Player& p1,Player & p)override{
        {
            Point shot_coordinate;
            int x;
            int y;
            int count=0;

            if(p1.round!=0){
                x=p1.pointWound.x;
                y=p1.pointWound.y;
                if(p1.already_shoted.size()>1) shot_coordinate = p1.already_shoted[p1.already_shoted.size()-2];
                switch(p1.round){
                case 4:{
                    y++;
                    if(y>BOARD_SIZE)y-=2;
                    if(p.pole[x][y].getType()==-3)y-=2;
                    while(p.pole[x][y].getType()==-2)y++;

                    p1.round--;break;
                }
                case 3:{
                    y--;
                    if(y==0)y+=2;
                    if(p.pole[x][y].getType()==-3)y+=2;
                    while(p.pole[x][y].getType()==-2)y--;

                    p1.round--;break;
                }
                case 2:{
                    x--;
                    if(x==0)x+=2;
                    if(p.pole[x][y].getType()==-3)x+=2;
                    while(p.pole[x][y].getType()==-2)x++;
                    p1.round--;break;
                }
                case 1:{
                    x++;
                    if(x>BOARD_SIZE)x-=2;
                    if(p.pole[x][y].getType()==-3)x-=2;
                    while(p.pole[x][y].getType()==-2)x--;
                    p1.round--;break;
                }
                }
                shot_coordinate.setXY(x,y);
                p1.deleteIndex(x,y);
            }


            else{
//                x=1+rand() % BOARD_SIZE;
//                y=1+rand() % BOARD_SIZE;

//                shot_coordinate.setXY(x,y);
//                //repeat until we reach a new point or the point isn't point0
//                while (std::count(p1.already_shoted.begin(), p1.already_shoted.end(), shot_coordinate) != 0 || p.pole[x][y].isKilShip()) {
//                    count++;
//                    //if(count>BOARD_SIZE*BOARD_SIZE) throw "no empty square";
//                    if(count>1000) throw "no empty square";
//                    x=1+rand() % BOARD_SIZE;
//                    y=1+rand() % BOARD_SIZE;
//                    shot_coordinate.setXY(x,y);
//            }
                shot_coordinate=p1.createRandomShot();
                x=shot_coordinate.x;
                y = shot_coordinate.y;
                }
        //    printf("\n %d %s   ",p1.n_neverShotedField,p1.getName());
            p1.already_shoted.push_back(shot_coordinate);
            p1.message = "";

            if(p.pole[x][y].isShip()){
                //ship is wond or kil
                p.pole[x][y].wound(x,y);
                //if(p1.round==0)
                    p1.round=4;


                p1.pointWound.setXY(x,y);
                p1.message =  " wound an enemy ship\n";
                p.pole[x][y].setType(-2);
                if(p.pole[x][y].kil()){
                    p.decreaseShips();
                    p1.round=0;
                    //round kil ship -3
                 //   p.create_environment(p.pole[x][y].getDeck(),p.pole[x][y].getX(),p.pole[x][y].getY(),p.pole[x][y].getVert(),p.kilShip);
                    p1.delete_environment(p.pole[x][y].getDeck(),p.pole[x][y].getX()
                                         ,p.pole[x][y].getY(),p.pole[x][y].getVert());
                    // p.printPole1();
                }

                //echo decrease deck in all square of wound ship
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

#endif // PLAYERSTRATEGYSYPER_H
