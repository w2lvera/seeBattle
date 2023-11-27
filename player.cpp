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
    n_Ships=0;
    kilShip.setType(-3);
    Point p;
    for(int i=0;i<n_neverShotedField;i++){
        p.setXY(i/BOARD_SIZE+1,i%BOARD_SIZE+1);
        neverShotedField[i]=p;
    }

//    for(int i=0;i<n_neverShotedField;i++){
//        printf("%d %d   ",neverShotedField[i].x,neverShotedField[i].y);
//    }

}
void Player::create_environment(int deck,int x,int y,int gor,Ship& ship){

    if(gor){

    pole[x][y+deck]=ship;
    pole[x-1][y-1]=pole[x+1][y-1]=pole[x][y-1]=ship;
    for(int i=0;i<deck+1;i++){
            pole[x-1][y+i]=pole[x+1][y+i]=ship;
        }
    }
    else{
        pole[x+deck][y]=ship;
        pole[x-1][y-1]=pole[x-1][y+1]=pole[x-1][y]=ship;
        for(int i=0;i<deck+1;i++){
           pole[x+i][y-1]=pole[x+i][y+1]=ship;
        }
    }
}
void Player::delete_environment(int deck,int x,int y,int gor){

    if(gor){

    deleteIndex(x,y+deck);
    deleteIndex(x-1,y-1);  deleteIndex(x+1,y-1); deleteIndex(x,y-1);
    for(int i=0;i<deck+1;i++){
             deleteIndex(x-1,y+i);
             deleteIndex(x+1,y+i);
        }
    }
    else{
         deleteIndex(x+deck,y);
         deleteIndex(x-1,y-1);  deleteIndex(x-1,y+1); deleteIndex(x-1,y);
        for(int i=0;i<deck+1;i++){
            deleteIndex(x+i,y-1);
            deleteIndex(x+i,y+1);
        }
    }
}
int Player::veriffication(int deck,int x,int y,int gor){
    int flag = 1;
    if(gor){
       for(int i=0;i<deck+1;i++)
           if(pole[x][y+i].getDeck()!=-1){
               flag=0;
               break;
           }

    }
    else {
        for(int i=0;i<deck+1;i++)
            if(pole[x+i][y].getDeck()!=-1){
                flag=0;
                break;
            }
    }
    return flag;
}
void Player::create_ships(){
    //int k=4;
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
                    create_environment(deck,x,y,1,ship0);
                            break;
                }
                x = 1+rand() % (BOARD_SIZE- deck+1);
                y = 1+rand() % (BOARD_SIZE );
                if(veriffication(deck,x,y,0))
                {
                    Ship ship{deck,x,y,0};
                    for(int i=0;i<deck;i++) pole[x+i][y]=ship;
                    create_environment(deck,x,y,0,ship0);
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

            printf("%4d ",pole[i][j].getDeck());
        }
        printf("\n");
    }
}
void Player::printPole1(){
    for(int i=0;i<BOARD_SIZE_BIG;i++){
        for(int j=0;j<BOARD_SIZE_BIG;j++){

            printf("%4d ",pole[i][j].getType());
        }
        printf("\n");
    }
}
const char* Player::getName(){
    return name.c_str();
}
void Player::decreaseShips(){ this->n_Ships--;}
void Player::tabLeft(int pointDel){
    for(int i = pointDel;i<n_neverShotedField-1;i++)
        neverShotedField[i]=neverShotedField[i+1];
    n_neverShotedField--;
}
void Player::deleteIndex(int x,int y ){
    int i;
    Point p;
    p.setXY(x,y);
    for(i = 0;i<n_neverShotedField && neverShotedField[i]!=p;i++);

      if(i!=n_neverShotedField)  tabLeft(i);

}
Point Player::createRandomShot(){
    if(n_neverShotedField <=0) throw "nevershuted field is empty";
    int n = rand()%n_neverShotedField;
    Point pointShot = neverShotedField[n];

   // printf("\n %d %d   ",pointShot.x,pointShot.y);
    tabLeft(n);
    return pointShot;
}


//void Player::shot(Player& p) {
//    int x;
//    int y;
//    int count=0;
//    //repeat until we reach a new point or the point isn't point0
//    x=1+rand() % BOARD_SIZE;
//    y=1+rand() % BOARD_SIZE;
//    while (std::count(already_shoted.begin(), already_shoted.end(), shot_coordinate) != 0 || p.pole[x][y].isKilShip()) {
//         count++;
//         if(count>BOARD_SIZE*BOARD_SIZE) throw "no empty square";
//         x=1+rand() % BOARD_SIZE;
//         y=1+rand() % BOARD_SIZE;
//        shot_coordinate.setXY(x,y);
//    }
//    already_shoted.push_back(shot_coordinate);
//    message = "";

//    if(p.pole[x][y].isShip()){
//       //ship is wond or kil
//       p.pole[x][y].wound(x,y);
//       message =  " wound an enemy ship\n";
//       p.pole[x][y].setType(-2);
//       if(p.pole[x][y].kil()){
//           p.n_Ships--;
//           p.create_environment(p.pole[x][y].getDeck(),p.pole[x][y].getX(),p.pole[x][y].getY(),p.pole[x][y].getVert(),kilShip);
//          // p.printPole1();
//       }

//       //echo
//       if(p.pole[x][y].getVert() == 1){
//           for(int i=1;p.pole[x][y+i].isShip();p.pole[x][y+i].wound(x,y),i++);
//           for(int i=1;p.pole[x][y-i].isShip();p.pole[x][y-i].wound(x,y),i++);
//       }
//       else{
//           for(int i=1;p.pole[x+i][y].isShip();p.pole[x+i][y].wound(x,y),i++);
//           for(int i=1;p.pole[x-i][y].isShip();p.pole[x-i][y].wound(x,y),i++);
//       }
//    }
//    else    message = " miss \n";
//}



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

