#ifndef SHIP_H
#define SHIP_H


class Ship
{
private:
    int number;
    int deckShot;
    int x;
    int y;
    int horizontal;
    int type;
public:
    Ship(int n,int x,int y,int horizontal);
    Ship();
    Ship(const Ship& s);
    bool isShip();
    bool isShip0();
    bool isKilShip();
    bool isWounded();
    void setType(int x){type=x;}
    int getX(){return x;}
    int getY(){return y;}
    int getHorizontal(){return horizontal;}
    int getDeck(){return number;}
    int getType(){return type;}
    bool kil();
    void wound(int x,int y);
   // Ship& operator = (Ship& s);
    bool operator != (Ship& s);
    bool operator == (Ship& s);

};

#endif // SHIP_H
