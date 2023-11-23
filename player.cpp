#include "player.h"

//Player::Player(const char* str)
//{
// this->hp = 20;
//   this->name = str;
//}
Player::Player(){
    for(int i=0;i<BOARD_SIZE_BIG;i++){
        for(int j=0;j<BOARD_SIZE_BIG;j++){

            pole[i][j]=emptyShip;
        }

    }

}
void Player::create_environment(int deck,int x,int y,int gor){

    if(gor){

    pole[x][y+deck]=ship0;
    pole[x-1][y-1]=pole[x+1][y-1]=pole[x][y-1]=ship0;
    for(int i=0;i<deck+1;i++){
            pole[x-1][y+i]=pole[x+1][y+i]=ship0;
        }
    }
    else{
        pole[x+deck][y]=ship0;
        pole[x-1][y-1]=pole[x-1][y+1]=pole[x-1][y]=ship0;
        for(int i=0;i<deck+1;i++){
           pole[x+i][y-1]=pole[x+i][y+1]=ship0;
        }
    }
}
int Player::veriffication(int deck,int x,int y,int gor){
    int flag = 1;
    if(gor){
       for(int i=0;i<deck+1;i++)
           if(pole[x][y+i].number!=-1){
               flag=0;
               break;
           }

    }
    else {
        for(int i=0;i<deck+1;i++)
            if(pole[x+i][y].number!=-1){
                flag=0;
                break;
            }
    }
    return flag;
}
void Player::create_ships(){
    int k=4;
    int deck;
    for(deck = 4;deck>0;deck--){
       int k=0;
       do{
            while(1){
                int x = 1+rand() % BOARD_SIZE;
                int y = 1+rand() % (BOARD_SIZE - deck+1);
                if(veriffication(deck,x,y,1))
                {
                    Ship ship{deck,x,y,1};
                    for(int i=0;i<deck;i++) pole[x][y+i]=ship;
                    create_environment(deck,x,y,1);
                            break;
                }
                x = 1+rand() % (BOARD_SIZE- deck+1);
                y = 1+rand() % (BOARD_SIZE );
                if(veriffication(deck,x,y,0))
                {
                    Ship ship{deck,x,y,0};
                    for(int i=0;i<deck;i++) pole[x+i][y]=ship;
                    create_environment(deck,x,y,0);
                    break;
                }
            }
            n_Ships++;
            k++;
        }
        while(k<4-deck+1);

    }

}
void Player::printPole(){
    for(int i=0;i<BOARD_SIZE_BIG;i++){
        for(int j=0;j<BOARD_SIZE_BIG;j++){

            printf("%4d ",pole[i][j].number);
        }
        printf("\n");
    }
}
void Player::printPole1(){
    for(int i=0;i<BOARD_SIZE_BIG;i++){
        for(int j=0;j<BOARD_SIZE_BIG;j++){

            printf("%4d ",pole[i][j].deckShot);
        }
        printf("\n");
    }
}
const char* Player::getName(){
    return name.c_str();
}
void Player::decreaseShips(){ this->n_Ships--;}


void Player::shot(Player& p) {
    int x=1+rand() % BOARD_SIZE;
    int y=1+rand() % BOARD_SIZE;
    shot_coordinate.setXY(x,y);
    //repeat until we reach a new point
    while (std::count(already_shoted.begin(), already_shoted.end(), shot_coordinate) != 0) {
         x=1+rand() % BOARD_SIZE;
         y=1+rand() % BOARD_SIZE;
        shot_coordinate.setXY(x,y);
    }
    already_shoted.push_back(shot_coordinate);
    message = "";

    if(p.pole[x][y].number>0){////!=emptyShip && pole[x][y]!=ship0){
        //ship is wond or kil
       // printf("  %d  %d %d \n",x,y,pole[x][y].number);
       // printPole();
       p.pole[x][y].wound(x,y);
        p.printPole1();
       p.pole[x][y].x = -2;
        if(p.pole[x][y].kil()){ p.n_Ships--;

        }

       // printf("  %d  %d %s \n",x,y,"str");
        message =  " wound an enemy ship\n";
        already_shoted.push_back(shot_coordinate);
    }
    else {
        message = " miss \n";
        already_shoted.push_back(shot_coordinate);
    }
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
int Player::getShips(){
    return n_Ships;
}
void Player::setName(std::string str){
    name = str;
}

