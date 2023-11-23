#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <cstdlib>
//#include <ctime>
#include <algorithm>
#include "point.h"
#include <string>
#define BOARD_SIZE 10
class Player
{
private:
    int find_index(Point coords, std::vector<Point> vec);
    bool check_for_ship_positioning(int x, int y, std::vector<Point> sub_vector);
public:
    std::string name;
    std::string message="";
    std::vector<Point> player_ships;
    std::vector<Point> already_shoted;
    Point shot_coordinate;
    int hp;
   // Player(const char* str);
    Player(){hp = 20;}
    const char* getName();
    void create_player_ships();
    std::vector<Point>& getPlayerShips();
    std::vector<Point>& getAlready_shoted();
    void setMessage(std::string str);
    const char* getMessage();
    void shot(Player& p);
    void decreaseShips();
    int getHp();
    void setName(std::string str);

};

#endif // PLAYER_H
