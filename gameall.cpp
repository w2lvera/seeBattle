#include "gameall.h"


GameAll::GameAll()
{


    std::string s1 = "first player";
    p1.setName(s1);
    s1 = "second player";
    p2.setName(s1);
    p1.create_ships();

    p2.create_ships();

    activePlayer = p2;
    passivePlayer = p1;
   // passivePlayer.printPole();
    //printf("\n");
    //printf("\nactivePlaer\n");
    //activePlayer.printPole();
    //view.print_result_board(activePlayer,passivePlayer);
}
void GameAll::run(){
    while(true){

        activePlayer.shot(passivePlayer);
        view.print_result_board(activePlayer,passivePlayer);

        if(passivePlayer.getShips()==0)break;// kil all ships of passivePlayer
        winner = activePlayer;
        activePlayer = passivePlayer;
        passivePlayer = winner;

        Sleep(50);

        //system("cls");


        printf("\n number of %s's ships   %d\n",passivePlayer.getName(),passivePlayer.getShips());
        view.setcur(0,50);
        view.print_result_board(activePlayer,passivePlayer);
        if(passivePlayer.getShips()==1){
            Sleep(5000);
        }

    }
    printf("\n game over                             \n");
    winner = activePlayer;

}
const char* GameAll::getWinner(){
    return winner.getName();
}
