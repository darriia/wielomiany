#include <iostream>
#include <vector>
#include <cmath>
#include "Polynomial.hpp"

using namespace std;

bool isAllIntegers(const vector<float> &values){
    for (float value: values){
        if (value - (int)(value / 1) != 0)
            return false;
    }
    return true;
}

void runDebug() {
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

    // Test differentiation
    Polynomial p18(0, 0, 0, 1, 1);
    Polynomial diff = p18.differentiation();
    cout << diff << " degree: " << diff.degree << endl;
    cout << diff.a << " " << diff.b << " " << diff.c << " " << diff.d << " " << diff.e << endl;
}

void testPolynomials(Polynomial p1, Polynomial p2) {
    // Test printing & degree calculation
    cout << "Wypisanie" << endl
         << "========================" << endl;
    cout << p1 << " degree: " << p1.degree << endl;
    cout << p2 << " degree: " << p2.degree << endl;

    // Test comparisons ==, !=
    cout << "Porównywanie" << endl
         << "========================" << endl;
    if (p1 == p2)
        cout << "p1==p2" << endl;
    if (p1 != p2)
        cout << "p1!=p2" << endl;

    // Test math operations -, +, -=, +=
    cout << "Operacje matematyczne" << endl
         << "========================" << endl;
    cout << "Dodawanie:" << endl;
    Polynomial sumResult = p1 + p2;
    cout << sumResult << " degree: " << sumResult.degree << endl;

    cout << "Odejmowanie:" << endl;
    Polynomial subResult = p1 - p2;
    cout << subResult << " degree: " << subResult.degree << endl;

    cout << "Zwiększanie:" << endl;
    p1 += p2;
    cout << p1 << " degree: " << p1.degree << endl;
    cout << p1.a << " " << p1.b << " " << p1.c << " " << p1.d << " " << p1.e << endl;

    cout << "Zmniejszanie:" << endl;
    p1 -= p2;
    cout << p1 << " degree: " << p1.degree << endl;
    cout << p1.a << " " << p1.b << " " << p1.c << " " << p1.d << " " << p1.e << endl;

    // Test differentiation
    cout << "Rozniczkowanie" << endl
         << "========================" << endl;
    Polynomial diff1 = p1.differentiation();
    cout << diff1 << " degree: " << diff1.degree << endl;
    cout << diff1.a << " " << diff1.b << " " << diff1.c << " " << diff1.d << " " << diff1.e << endl;
    cout << "------------------------" << endl;
    Polynomial diff2 = p1.differentiation();
    cout << diff2 << " degree: " << diff2.degree << endl;
    cout << diff2.a << " " << diff2.b << " " << diff2.c << " " << diff2.d << " " << diff2.e << endl;
}

int main() {
    // runDebug();
    int i = 0;
    vector<Polynomial> polynomials = {};

    cout << "Podaj wspolczynniki wielomianow, gdzie: a*x^4 + b*x^3 + c*x^2 + d*x + e." << endl;

    while (i < 2) {
        float inpA, inpB, inpC, inpD, inpE;
        cout << "Podaj a, b, c, d, e: " << endl;
        cin >> inpA >> inpB >> inpC >> inpD >> inpE;
        if (cin.fail()) {
            cout << "Podałeś nieprawidłowe dane. Spróbuj jeszcze raz" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;

        } else {
            vector<float> inputVector = vector<float>{inpA, inpB, inpC, inpD, inpE};
            if (!isAllIntegers(inputVector)){
                cout << "Podałeś nieprawidłowe dane. Spróbuj jeszcze raz <no floats>" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            int a = (int) (inpA);
            int b = (int) (inpB);
            int c = (int) (inpC);
            int d = (int) (inpD);
            int e = (int) (inpE);
            polynomials.emplace_back(Polynomial(a, b, c, d, e));
            i += 1;
        }
    }

    testPolynomials(polynomials[0], polynomials[1]);

    return 0;
}