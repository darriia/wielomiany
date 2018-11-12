#include <iostream>
#include <vector>
#include <cmath>
#include "Polynomial.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main() {
    Polynomial w0(0, 0, 0, 0, 0, 1);
    cout << w0 << endl;
    Polynomial w1(1, 0, 0, 0, 2, 1);
    cout << w1 << endl;
    Polynomial w2(2, 0, 0, 1, 2, 1);
    cout << w2 << endl;
    Polynomial w3(3, 0, 1, 1, 2, 1);
    cout << w3 << endl;
    Polynomial w4(4, 1, 1, 1, 2, 1);
    cout << w4 << endl;

    return 0;
}