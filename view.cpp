#include "view.h"

View::View()
{

    for (int i = 0; i < BOARD_SIZE; i++) {

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
void View::setcur(int x,int y)
{
    COORD coord; coord.X = x; coord.Y = y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void View::print_result_board(Player& activePlayer,Player& passivePlayer) {

    printf("active is the %s %s \n",activePlayer.getName(),activePlayer.getMessage());
    std::vector<Point> already_shoted= activePlayer.getAlready_shoted();
    char border_with_letters[] = "abcdefghij";//{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    char border_with_digits[] = "0123456789";
    erase();

    for (int i = 0; i < already_shoted.size(); i++) {
        int x = already_shoted[i].x;
        int y = already_shoted[i].y;
        boardShips[x-1][y-1] = '*';

    }



    printf("\n ");
    printf(" ");
    for (int p = 0; p < BOARD_SIZE; p++) {
        printf("%2c",border_with_letters[p]);
    }
    for(int i=1;i<BOARD_SIZE+1;i++){
       for(int j=1;j<BOARD_SIZE+1;j++){
           char h;
           if(passivePlayer.pole[i][j].isShip()){
            h=passivePlayer.pole[i][j].getDeck()+'0';
            if(passivePlayer.pole[i][j].isWounded())h ='X';//wound
            boardShips[i-1][j-1]=h;
           }
        }
    }

    for(int i=0;i<BOARD_SIZE;i++){
        printf("\n");
        printf("%2c", border_with_digits[i]) ;
       for(int j=0;j<BOARD_SIZE;j++){
          printf("%2c",boardShips[i][j]);
        }

    }
    printf("\n ");

//    Sleep(50);
//    system("cls");

 setcur(0,0);
}
