#include "player.h"

//Player::Player(const char* str)
//{
// this->hp = 20;
//   this->name = str;
//}
const char* Player::getName(){
    return name.c_str();
}
bool Player::check_for_ship_positioning(int x, int y, std::vector<Point> sub_vector) {

    if (std::count(sub_vector.begin(), sub_vector.end(), Point(x, y)) >= 1 || ((std::count(sub_vector.begin(), sub_vector.end(), Point(x, y - 1)) >= 1) ||
        (std::count(sub_vector.begin(), sub_vector.end(), Point(x, y + 1)) >= 1)
        || (std::count(sub_vector.begin(), sub_vector.end(), Point(x - 1, y)) >= 1) || (std::count(sub_vector.begin(), sub_vector.end(), Point(x - 1, y + 1)) >= 1)
        || (std::count(sub_vector.begin(), sub_vector.end(), Point(x - 1, y - 1)) >= 1) || (std::count(sub_vector.begin(), sub_vector.end(), Point(x + 1, y)) >= 1)
        || (std::count(sub_vector.begin(), sub_vector.end(), Point(x + 1, y + 1)) >= 1) || (std::count(sub_vector.begin(), sub_vector.end(), Point(x + 1, y - 1)) >= 1))) {
        return false;
    }
    else {
        return true;
    }
}
void Player::create_player_ships(){
     /* srand(static_cast<unsigned>(time(NULL)));*/
        int count_of_four = 1;
        for (int i = 0; i < count_of_four;) {
            int vert = 0 + rand() % 2;
            if (vert == 0) {
                int x = rand() % BOARD_SIZE;
                int y = rand() % (BOARD_SIZE - 3);
                if (check_for_ship_positioning(x, y, player_ships) && check_for_ship_positioning(x, y + 1, player_ships) && check_for_ship_positioning(x, y + 2, player_ships)
                    && check_for_ship_positioning(x, y + 3, player_ships)) {
                    player_ships.push_back(Point(x, y));
                    player_ships.push_back(Point(x, y + 1));
                    player_ships.push_back(Point(x, y + 2));
                    player_ships.push_back(Point(x, y + 3));
                    i++;
                }
            }
            else if (vert == 1) {

                int x = rand() % (BOARD_SIZE - 3);;
                int y = rand() % BOARD_SIZE;
                if (check_for_ship_positioning(x, y, player_ships) && check_for_ship_positioning(x + 1, y, player_ships) && check_for_ship_positioning(x + 2, y, player_ships)
                    && check_for_ship_positioning(x + 3, y, player_ships)) {
                    player_ships.push_back(Point(x, y));
                    player_ships.push_back(Point(x + 1, y));
                    player_ships.push_back(Point(x + 2, y));
                    player_ships.push_back(Point(x + 3, y));
                    i++;
                }
            }
        }
        int count_of_tre = 2;
        for (int j = 0; j < count_of_tre;) {
            int vert = 0 + rand() % 2;
            if (vert == 0) {
                int x = rand() % BOARD_SIZE;
                int y = rand() % (BOARD_SIZE - 2);
                if (check_for_ship_positioning(x, y, player_ships) && check_for_ship_positioning(x, y + 1, player_ships) && check_for_ship_positioning(x, y + 2, player_ships)) {
                    player_ships.push_back(Point(x, y));
                    player_ships.push_back(Point(x, y + 1));
                    player_ships.push_back(Point(x, y + 2));
                    j++;
                }
            }
            if (vert == 1) {
                int x = rand() % (BOARD_SIZE - 2);
                int y = rand() % BOARD_SIZE;
                if (check_for_ship_positioning(x, y, player_ships) && check_for_ship_positioning(x + 1, y, player_ships) && check_for_ship_positioning(x + 2, y, player_ships)) {
                    player_ships.push_back(Point(x, y));
                    player_ships.push_back(Point(x + 1, y));
                    player_ships.push_back(Point(x + 2, y));
                    j++;
                }
            }
        }
        int count_of_two = 3;
        for (int k = 0; k < count_of_two;) {
            int vert = 0 + rand() % 2;
            if (vert == 0) {
                int x = rand() % BOARD_SIZE;
                int y = rand() % (BOARD_SIZE - 1);
                if (check_for_ship_positioning(x, y, player_ships) && check_for_ship_positioning(x, y + 1, player_ships)) {
                    player_ships.push_back(Point(x, y));
                    player_ships.push_back(Point(x, y + 1));
                    k++;
                }
            }
            if (vert == 1) {
                int x = rand() % (BOARD_SIZE - 1);
                int y = rand() % BOARD_SIZE;
                if (check_for_ship_positioning(x, y, player_ships) && check_for_ship_positioning(x + 1, y, player_ships)) {
                    player_ships.push_back(Point(x, y));
                    player_ships.push_back(Point(x + 1, y));
                    k++;
                }
            }
        }
        int count_of_one = 4;
        for (int q = 0; q < count_of_one;) {
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;
            if (check_for_ship_positioning(x, y, player_ships) == true) {
                player_ships.push_back(Point(x, y));
                q++;
            }
        }

}

void Player::decreaseShips(){ this->hp--;}
int Player::find_index(Point coords, std::vector<Point> vec) {
    auto it = std::find(vec.begin(), vec.end(), coords);
    int index = std::distance(vec.begin(), it);
    return index;
}
void Player::shot(Player& p) {
    shot_coordinate.setXY(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
    //repeat until we reach a new point
    while (std::count(already_shoted.begin(), already_shoted.end(), shot_coordinate) != 0) {
        shot_coordinate.setXY(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
    }

    message = "";
    if (std::count(p.getPlayerShips().begin(), p.getPlayerShips().end(), shot_coordinate) >= 1) {
        p.getPlayerShips().erase(p.getPlayerShips().begin() + find_index(shot_coordinate, p.getPlayerShips()));
        message =  " hit an enemy ship \n";
        already_shoted.push_back(shot_coordinate);
        p.decreaseShips();

    }
    else {
        message = " miss \n";
        already_shoted.push_back(shot_coordinate);

    }
}

std::vector<Point>& Player::getPlayerShips(){
    return this->player_ships;
}
std::vector<Point>& Player::getAlready_shoted(){
    return this->already_shoted;
}
void Player::setMessage(std::string str){
 message = str;
}
const char* Player::getMessage(){
    return message.c_str();
}
int Player::getHp(){
    return hp;
}
void Player::setName(std::string str){
    name = str;
}

