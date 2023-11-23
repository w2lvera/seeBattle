#ifndef VIEW_H
#define VIEW_H
//#define BOARD_SIZE 10
#include <iostream>
#include <windows.h>
#include "player.h"
class View
{
public:
    char** boardShips;
    View();
    void erase();
    void setcur();
    void print_result_board(Player activePlayer,Player passivePlayer);
};

#endif // VIEW_H
