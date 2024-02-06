#ifndef RECTANGLE_H
#include "rectangle.h"
#endif

class Square : public Rectangle
{
public:
    Square(int x = 0, int y = 0, int side = 1);
    ~Square();
    void printTo(std::ostream &s) override;
    bool changeSize(int side);
};

Square::Square(int x, int y, int side) : Rectangle(x, y, side, side) {}

Square::~Square() {}

bool Square::changeSize(int side)
{
    if (side < 0) { return false; }

    w = side;
    h = side;

    return true;
}

void Square::printTo(std::ostream &s) 
{
    s << ("K %d %d %d", ancrage.x, ancrage.y, w);
}