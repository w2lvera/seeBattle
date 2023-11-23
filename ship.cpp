#include "ship.h"

Ship::Ship(int n,int x,int y,int vert)
{
    number = n;
    this->x=x;
    this->vert=vert;
    this->y = y;
    deckShot = number;
    //type1=number;

}
Ship::Ship(){}
Ship::Ship(const Ship& s){
    this->number = s.number;
    this->x=s.x;
    this->vert=s.vert;
    this->y =s.y;
    this->deckShot = s.deckShot;
}
void Ship::wound(int x,int y){
//    wounds[deckShot][0]=x;
//    wounds[deckShot][1]=y;
    deckShot--;

}
bool Ship::isWound(int x,int y){
    for(int i=number;i>=this->deckShot;i--)
        if(x==wounds[i][0]&& y==wounds[i][1])
            return true;
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
