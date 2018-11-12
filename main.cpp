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

    Polynomial w5(4, 1, 1, 1, 2, 1);
    Polynomial w6(4, 1, 1, 1, 2, 1);
    Polynomial w7(4, 2, 1, 1, 2, 1);

    if (w5 == w6)
        cout << "w5==w6" << endl;

    if (w6 == w7)
        cout << "w6==w7" << endl;

    if (w5 != w6)
        cout << "w5!=w6" << endl;

    if (w7 != w6)
        cout << "w7!=w6" << endl;

    return 0;
}