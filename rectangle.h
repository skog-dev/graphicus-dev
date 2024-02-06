#ifndef FORME_H
#include "shape.h"
#endif

#define RECTANGLE_H

class Rectangle : public Shape
{
public:
    Rectangle(int x = 0, int y = 0, int width = 1, int height = 1);
    ~Rectangle();
    virtual void printTo(std::ostream &s) override;
    double area() override;
    bool changeSize(int width, int height);
    double getWidth();
    double getHeight();

protected:
    int w;
    int h;
};

Rectangle::Rectangle(int x, int y, int width, int height) : Shape(x, y)
{
    w = (width >= 0) ? width : 1;
    h = (height >= 0) ? height : 1;
}

Rectangle::~Rectangle() {}

bool Rectangle::changeSize(int width, int height)
{
    if (width < 0 || height < 0) { return false; }

    w = width;
    h = height;

    return true;
}

void Rectangle::printTo(std::ostream &s)
{
    s << ("R %d %d %d %d", ancrage.x, ancrage.y, w, h);
}

double Rectangle::area() { return h * w; }

double Rectangle::getWidth() { return w; }

double Rectangle::getHeight() { return h; }