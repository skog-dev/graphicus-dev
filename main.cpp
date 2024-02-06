
#include <iostream>

#include "couche.h"

using namespace std;

int main() {

    Couche<int> couche;

    couche.addElement(new int(1));
    couche.addElement(new int(2));
    couche.addElement(new int(3));

    couche.printLayer();

    cout << "Resetting the layer" << endl;

    couche.reset();

    cout << "Reset successful" << endl;

    couche.printLayer();

    return 0;
}