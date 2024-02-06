
#include <iostream>

#include "vector.h"

using namespace std;

int main() {

    Vector<float> vector(2);

    vector += new float(1.5);
    vector += new float(3.14);
    vector += new float(5.2);

    cout << vector << endl;

    return 0;
}