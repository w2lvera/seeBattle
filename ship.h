#ifndef SHIP_H
#define SHIP_H


class Ship
{
public:
    int number;
    int deckShot;
    int x;
    int y;
    int vert;

    int wounds[4][2];
    Ship(int n,int x,int y,int vert);
    Ship();
    Ship(const Ship& s);
    bool isWound(int x,int y);
    bool kil();
    void wound(int x,int y);
   // Ship& operator = (Ship& s);
    bool operator != (Ship& s);
    bool operator == (Ship& s);

};

#endif // SHIP_H
