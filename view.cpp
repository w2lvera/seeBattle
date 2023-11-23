#include "view.h"

View::View()
{
    boardShips = new char* [BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        boardShips[i] = new char[BOARD_SIZE];
        for (int j = 0; j < BOARD_SIZE; j++) {
            boardShips[i][j] = ' ';
        }
    }


}
void View::erase(){
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            boardShips[i][j] = ' ';
        }
    }

}
void View::setcur()
{
    COORD coord; coord.X = 0; coord.Y = 0; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void View::print_result_board(Player activePlayer,Player passivePlayer) {
    //std::cout << ' ';
    std::cout<<"active player "<< activePlayer.getName()<<activePlayer.getMessage()<<std::endl;
    std::vector<Point> player_ships= passivePlayer.getPlayerShips();
    std::vector<Point> already_shoted= activePlayer.getAlready_shoted();
    char border_with_letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    erase();

    for (int i = 0; i < already_shoted.size(); i++) {
        int x = already_shoted[i].x;
        int y = already_shoted[i].y;
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
           boardShips[x][y] = 'X';
        }
    }

    for (int i = 0; i < player_ships.size(); i++) {
        int x = player_ships[i].x;
        int y = player_ships[i].y;
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
           boardShips[x][y] = '1';
        }
    }

    std::cout << " ";
    for (int p = 0; p < BOARD_SIZE; p++) {
        std::cout << border_with_letters[p] << ' ';
    }
    std::cout << '\n';

    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << border_with_letters[i] << ' ';
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout <<boardShips[i][j] << " ";
        }
        std::cout << ("\n");
    }
    Sleep(5000);
    system("cls");
    setcur();
}
