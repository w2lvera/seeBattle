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
class Player
{
private:
    int find_index(Point coords, std::vector<Point> vec);
    bool check_for_ship_positioning(int x, int y, std::vector<Point> sub_vector);
    void create_environment(int x,int y,int deck,int vert,Ship& s);
    int veriffication(int x,int y,int deck,int vert);
public:
    std::string name;
    std::string message="";
    Ship pole[BOARD_SIZE_BIG][BOARD_SIZE_BIG];

    Ship emptyShip{-1,-1,-1,0};
    Ship ship0{0,0,0,0};
    Ship kilShip{0,0,0,0};
    void printPole();
    void printPole1();
    void create_ships();
    int n_Ships;
    std::vector<Point> already_shoted;
    Point shot_coordinate;
    int hp;
   // Player(const char* str);
    Player();
    const char* getName();
//    void create_player_ships();
//    std::vector<Point>& getPlayerShips();
    std::vector<Point>& getAlready_shoted();
    void setMessage(std::string str);
    const char* getMessage();
    void shot(Player& p);
    void decreaseShips();
    int getShips();
    void setName(std::string str);
    bool isWound(int x,int y);

};

#endif // PLAYER_H
