#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <cstdlib>
//#include <ctime>
#include <algorithm>

#include <string>
#include<stdio.h>
#include "point.h"
#include "ship.h"
#define BOARD_SIZE 10
#define BOARD_SIZE_BIG BOARD_SIZE+2
#define N_SHIPS 10
#include "playerstrategy.h"
class Player
{

private:
    ///////////////// player variable //////////////////
    std::string name;
    int n_Ships;
    void tabLeft(int pointDel);
    std::vector<Point> already_shoted;
public:void deleteIndex(int x,int y);

public:
    ////////////////// play strategy/////////////////
    PlayerStrategy* ps;
    void setPlayerStrategy(PlayerStrategy* ps){
        this->ps = ps;
    }
    void shot(Player& p){
        ps->shot(*this,p);
    }

    std::string message="";
    /////////////// playing field /////////////////////

    Ship pole[BOARD_SIZE_BIG][BOARD_SIZE_BIG];
    Ship emptyShip{-1,-1,-1,0}; // ship to indicate empty field: number = -1
    // ship to indicate the surrounding fields of a ship
    Ship ship0{0,0,0,0}; //used when forming a field with ships: number = 0
    int round=0;//used for super strategy
    Point pointWound;//Point of wound ship: used for super strategy
    /////////////////////// used for shot /////////////

    Point neverShotedField[BOARD_SIZE*BOARD_SIZE];//coordinates where the player did not shoot
    int n_neverShotedField = BOARD_SIZE*BOARD_SIZE;//number of available shot
    Point createRandomShot();// create a random shot

    ///////////////////// function for debugging //////
    void printPole();//help
    void printPole1();//help
    //////////////////// function for creating ships///////
    void create_ships();
    void create_environment(int x,int y,int deck,int vert,Ship& s);
    void delete_environment(int x,int y,int deck,int vert);
    int veriffication(int x,int y,int deck,int vert);
    //////////// function class ////////////////////////////
    Player();
    const char* getName();
    std::vector<Point>& getAlready_shoted();
    void setMessage(std::string str);
    const char* getMessage();
    void decreaseShips();
    int getShips();
    void setName(std::string str);
    void addShot(Point p);

};

#endif // PLAYER_H
