#include "gameall.h"


GameAll::GameAll()
{


    std::string s1 = "first player";
    p1.setName(s1);
    s1 = "second player";
    p2.setName(s1);
    p1.create_ships();

    p2.create_ships();

    activePlayer = p1;
    passivePlayer = p2;
    passivePlayer.printPole();
    printf("\n");
    printf("\nactivePlaer\n");
    activePlayer.printPole();
   view.print_result_board(activePlayer,passivePlayer);
}
void GameAll::run(){
    while(true){
        activePlayer.shot(passivePlayer);
        view.print_result_board(activePlayer,passivePlayer);
        printf("\n game over\n");
        if(passivePlayer.getShips()==0)break;// kil all ships of passivePlayer
//        winner = activePlayer;
//        activePlayer = passivePlayer;
//        passivePlayer = winner;

        Sleep(5000);

        system("cls");

    printf("\n game over after break %d\n",passivePlayer.getShips());

    }
    printf("\n game over\n");
    winner = activePlayer;

}
const char* GameAll::getWinner(){
    return winner.getName();
}
