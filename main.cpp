#include <iostream>
#include <vector>
#include <cmath>
#include "Wielomian.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main() {
    Wielomian w1(1, -1, 0);
    Wielomian w2(0, -1, 1);
    w1 += w2;
    w1.wyswietlPierwiastki();
    return 0;
}
