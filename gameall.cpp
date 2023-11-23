#include "gameall.h"


GameAll::GameAll()
{
    std::string s1 = "first player";
    p1.setName(s1);
    s1 = "second player";
    p2.setName(s1);
    p1.create_player_ships();
    p2.create_player_ships();
    activePlayer = p1;
    passivePlayer = p2;
     view.print_result_board(activePlayer,passivePlayer);
}
void GameAll::run(){
    while(true){
        activePlayer.shot(passivePlayer);
        view.print_result_board(activePlayer,passivePlayer);
        if(passivePlayer.getHp()==0)break;// kil all ships of passivePlayer
        winner = activePlayer;
        activePlayer = passivePlayer;
        passivePlayer = winner;

    }
    winner = activePlayer;

}
const char* GameAll::getWinner(){
    return winner.getName();
}
