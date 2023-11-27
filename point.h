#ifndef POINT_H
#define POINT_H


class Point
{
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
    Point():x(0),y(0){}

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }
    bool operator!=(const Point& other) const {
        return (x != other.x) || (y != other.y);
    }
    void setXY(int x,int y){this->x=x;this->y = y;}
};

#endif // POINT_H
