#ifndef SHAPE_H
#include "shape.h"
#endif

#define PI 3.14159265358979323846

class Circle : public Shape
{
public:
    Circle(int x1 = 0, int y1 = 0, int rayon = 1);
    ~Circle();
    double area() override;
    void printTo(std::ostream &s) override;
    bool changeSize(int rayon);
    int getRayon();

private:
    int r;
};

Circle::Circle(int x, int y, int rayon) : Shape(x, y) { r = (rayon > 0) ? rayon : 1; }

Circle::~Circle() { }

double Circle::area() { return PI * r * r; }

int Circle::getRayon() { return r; }

bool Circle::changeSize(int rayon)
{
    r = rayon;
    return true;
}

void Circle::printTo(std::ostream &s)
{
    s << ("C %d %d %d, ", ancrage.x, ancrage.y, r);
}