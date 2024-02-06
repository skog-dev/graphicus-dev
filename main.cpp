
#include <iostream>

#include "vector.h"

using namespace std;

int main() {

    Vector<int> vector(2);

    vector += new int(1);
    vector += new int(2);
    vector += new int(3);

    cout << vector << endl;

    return 0;
}