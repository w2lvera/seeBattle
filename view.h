#ifndef VIEW_H
#define VIEW_H
//#define BOARD_SIZE 10
#include <stdio.h>
#include <windows.h>
#include "player.h"
class View
{
public:
    char boardShips[BOARD_SIZE][BOARD_SIZE];
    View();
    void erase();
    void setcur(int x,int y);
    void print_result_board(Player& activePlayer,Player& passivePlayer);
    void SetColor(int text, int background);
};

#endif // VIEW_H
