#include "gameall.h"


GameAll::GameAll()
{
    std::string s1 = "first player";
    p1.setName(s1);
    s1 = "second player";
    p2.setName(s1);
    pss = new PlayerStrategySimple();
    psh = new PlayerStrategHeuristic();
    pssy = new PlayerStrategySuper();
    p2.setPlayerStrategy(pss);
    p1.setPlayerStrategy(pssy);

    p1.create_ships();
    p2.create_ships();

    activePlayer = p2;
    passivePlayer = p1;

   // passivePlayer.printPole();

    //printf("\n");
    //printf("\nactivePlayer\n");
    //activePlayer.printPole();
    //view.print_result_board(activePlayer,passivePlayer);
}
void GameAll::run(){
    int a=1;
    while(true){
        try{
            if(a){
                activePlayer.shot(passivePlayer);
                view.print_result_board(activePlayer,passivePlayer);
                if(passivePlayer.getShips()==0){// kil all ships of passivePlayer
                    winner = activePlayer;
                    break;
                }
            }
            else{
                passivePlayer.shot(activePlayer);
                view.print_result_board(passivePlayer,activePlayer);
                if(activePlayer.getShips()==0){// kil all ships of activePlayer
                    winner = passivePlayer;
                    break;
                }
            }
            a= !a;
            //        winner = activePlayer;
            //        activePlayer = passivePlayer;
            //        passivePlayer = winner;

            printf("\n number of %s's ships    %2d number of available shots %d\n",passivePlayer.getName(),passivePlayer.getShips(),passivePlayer.n_neverShotedField);
            printf(" number of %s's ships   %2d number of available shots %d\n",activePlayer.getName(),activePlayer.getShips(),activePlayer.n_neverShotedField);

            if(passivePlayer.getShips()==1 || activePlayer.getShips()==1){
                Sleep(5000);
            }
            else{
                Sleep(50);
                system("cls");
                view.setcur(0,0);
            }

        }
        catch(const char* str){// if number shots > BOARD_SIZE*BOARD_SIZE
            printf(str);
            break;
        }
    }
    printf("\n game over                             ");
}
const char* GameAll::getWinner(){
    return winner.getName();
}
