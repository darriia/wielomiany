#include <iostream>
#include <vector>
#include <cmath>
#include "Polynomial.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main() {

    // Test printing & degree calculation
    Polynomial p0( 0, 0, 0, 0, 1);
    cout << p0 << " degree: " << p0.degree << endl;
    Polynomial p1(0, 0, 0, 2, 1);
    cout << p1 << " degree: " << p1.degree << endl;
    Polynomial p2(0, 0, 1, 2, 1);
    cout << p2 << " degree: " << p2.degree << endl;
    Polynomial p3(0, 1, 1, 2, 1);
    cout << p3 << " degree: " << p3.degree << endl;
    Polynomial p4(1, 1, 1, 2, 1);
    cout << p4 << " degree: " << p4.degree << endl;

    // Test comparisons ==, !=
    Polynomial p5(1, 1, 1, 2, 1);
    Polynomial p6(1, 1, 1, 2, 1);
    Polynomial p7(2, 1, 1, 2, 1);
    if (p5 == p6)
        cout << "p5==p6" << endl;
    if (p6 == p7)
        cout << "p6==p7" << endl;
    if (p5 != p6)
        cout << "p5!=p6" << endl;
    if (p7 != p6)
        cout << "p7!=p6" << endl;

    // Test math operations
    Polynomial p8(0, 1, 1, 2, 1);
    Polynomial p9(0, 0, 1, 2, 1);
    Polynomial p10(2, -1, 1, 2, 1);

    Polynomial p11 = p8 + p9;
    cout << p11 << " degree: " << p11.degree << endl;

    Polynomial p12 = p10 - p9;
    cout << p12 << " degree: " << p12.degree << endl;
    cout << p12.a << " " << p12.b << " " << p12.c << " " << p12.d << " " << p12.e << endl;

    Polynomial p13 = p9 - p10;
    cout << p13 << " degree: " << p13.degree << endl;
    cout << p13.a << " " << p13.b << " " << p13.c << " " << p13.d << " " << p13.e << endl;

    Polynomial p14(0, 1, 1, 2, 1);
    Polynomial p15(0, 0, 1, 2, 1);
    Polynomial p16(2, -1, 1, 2, 1);
    Polynomial p17(2, -1, 1, 2, 1);

    p14 += p15;
    cout << p14 << " degree: " << p14.degree << endl;
    cout << p14.a << " " << p14.b << " " << p14.c << " " << p14.d << " " << p14.e << endl;

    p15 -= p16;
    cout << p15 << " degree: " << p15.degree << endl;
    cout << p15.a << " " << p15.b << " " << p15.c << " " << p15.d << " " << p15.e << endl;

    p16 -= p17;
    cout << p16 << " degree: " << p16.degree << endl;
    cout << p16.a << " " << p16.b << " " << p16.c << " " << p16.d << " " << p16.e << endl;

    return 0;
}