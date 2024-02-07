
#include "square.h"

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
    s << "K " << ancrage.x << " " << ancrage.y << " " << w << std::endl;
}