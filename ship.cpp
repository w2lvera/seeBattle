#include "ship.h"

Ship::Ship(int n,int x,int y,int vert)
{
    number = n;
    this->x=x;
    this->vert=vert;
    this->y = y;
    deckShot = number;
    type=number;
}
Ship::Ship(){}
Ship::Ship(const Ship& s){
    this->number = s.number;
    this->x=s.x;
    this->vert=s.vert;
    this->y =s.y;
    this->deckShot = s.deckShot;
    type=number;
}
void Ship::wound(int x,int y){
    deckShot--;
}
bool Ship::isWounded(){
    if(type==-2)return true;
    return false;
}
bool Ship::isKilShip(){
    if(type==-3) return true;
    return false;
}
bool Ship::isShip(){
    if(number>0)return true;
    return false;
}
bool Ship::isShip0(){
    if(number==0)return true;
    return false;
}
bool Ship::kil(){return deckShot==0;}
//Ship& Ship::operator = (Ship& s){
//    this->number = s.number;
//    this->x=s.x;
//    this->vert=s.vert;
//    this->y =s.y;
//    this->deckShot = s.deckShot;
//    for(int i=0;i<4;i++){
//        this->wounds[i][0]=s.wounds[i][0];
//        this->wounds[i][1]=s.wounds[i][1];
//    }
//    return *this;
//}
bool Ship::operator != (Ship& s){
    return this->number != s.number||
    this->x!=s.x ||
    this->vert!=s.vert ||
    this->y !=s.y ||
    this->deckShot != s.deckShot;
}
bool Ship::operator == (Ship& s){
    return this->number == s.number&&
    this->x ==s.x &&
    this->vert==s.vert &&
    this->y ==s.y &&
    this->deckShot == s.deckShot;
}
