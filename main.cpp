
#include <iostream>

#include "layer.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"

using namespace std;

int main() {

    Layer layer;

    layer.addElement(new Circle(1, 4, 3));
    layer.addElement(new Square(2, -3, 4));
    layer.addElement(new Rectangle(3, 5, 6, 12));

    layer.printLayer();

    return 0;
}