
#include <iostream>

#include "caneva.h"

using namespace std;

int main() {

    Vector<int> vector(2);

    vector.addElement(new int(1));
    vector.addElement(new int(2));
    vector.addElement(new int(3));

    cout << vector << endl;

    return 0;
}