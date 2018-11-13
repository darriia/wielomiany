#include "Polynomial.hpp"

using namespace std;


string stringify(int value, bool without_x=false){
    /* Pomocnicza funkcja, która służy do zamiany wartości liczbowej na ciąg znaków.
     * Zamienia zapis 1 -> + oraz -1 -> -
     */
    string valueString = to_string(value);

    if (value == 1){
        valueString = "+";
        if (without_x)
            valueString += "1";
    }

    if (value == -1){
        valueString = "-";
        if (without_x)
            valueString += "1";
    }

    if (value > 1)
        valueString =  "+" + valueString;

    return valueString;
}

Polynomial::Polynomial(int a_, int b_, int c_, int d_, int e_) {
    a = a_;
    b = b_;
    c = c_;
    d = d_;
    e = e_;
    degree = calculateDegree();
}

int Polynomial::calculateDegree() {
    /* Funkcja wyciąga stopień z wielomianu. */
    if(a == 0 && b == 0 && c == 0 && d == 0) return 0;
    if(a == 0 && b == 0 && c == 0 ) return 1;
    if(a == 0 && b == 0 ) return 2;
    if(a == 0) return 3;
    return 4;
}

Polynomial Polynomial::differentiation() {
    /* Funkcja liczy różniczkę wielomianu. */
    int a_ = 0;
    int b_ = 4 * a;
    int c_ = 3 * b;
    int d_ = 2 * c;
    int e_ = d;
    return Polynomial(a_, b_, c_, d_, e_);
}

Polynomial::~Polynomial() {
    cout << "Deleted Polynomial" << endl;
}

ostream &operator<<(ostream &output, Polynomial &p) {
    /* Przeciążenie operatora, który wyświetla wielomian.*/
    switch(p.degree){
        case 0:
            output << p.e;
            break;
        case 1:
            output << stringify(p.d) << "x"
            << ((p.e != 0) ? stringify(p.e, true): "");
            break;
        case 2:
            output << stringify(p.c) << "x^2"
            << ((p.d != 0) ? stringify(p.d) + "x" : "")
            << ((p.e != 0) ? stringify(p.e, true): "");
            break;
        case 3:
            output << stringify(p.b) << "x^3"
            << ((p.c != 0) ? stringify(p.c) + "x^2" : "")
            << ((p.d != 0) ? stringify(p.d) + "x" : "")
            << ((p.e != 0) ? stringify(p.e, true): "");
            break;
        case 4:
            output << stringify(p.a) << "x^4"
            << ((p.b != 0) ? stringify(p.b) + "x^3" : "")
            << ((p.c != 0) ? stringify(p.c) + "x^2" : "")
            << ((p.d != 0) ? stringify(p.d) + "x" : "")
            << ((p.e != 0) ? stringify(p.e, true): "");
            break;
        default: output << "";
    }
    return output;
}

bool operator ==(Polynomial& p1, Polynomial& p2){
    /* Przeciążenie operatora, które porównuje wielomiany.*/
    if(p1.degree != p2.degree) return false;
    return p1.e == p2.e
           && p1.d == p2.d
           && p1.c == p2.c
           && p1.b == p2.b
           && p1.a == p2.a;
}

bool operator !=(Polynomial& p1, Polynomial& p2){
    /* Przeciążenie operatora, który porównuje wielomiany.*/
    if(p1.degree != p2.degree) return true;
    return p1.e != p2.e
           || p1.d != p2.d
           || p1.c != p2.c
           || p1.b != p2.b
           || p1.a != p2.a;
}

Polynomial operator +(Polynomial& p1, Polynomial& p2){
    /* Przeciążenie operatora, który dodaje wielomiany.*/
    int a = p1.a + p2.a;
    int b = p1.b + p2.b;
    int c = p1.c + p2.c;
    int d = p1.d + p2.d;
    int e = p1.e + p2.e;
    return Polynomial(a, b, c, d, e);

}

Polynomial operator -(Polynomial& p1, Polynomial& p2){
    /* Przeciążenie operatora, który odejmuje wielomiany.*/
    int a = p1.a - p2.a;
    int b = p1.b - p2.b;
    int c = p1.c - p2.c;
    int d = p1.d - p2.d;
    int e = p1.e - p2.e;
    return Polynomial(a, b, c, d, e);
}

void operator +=(Polynomial& p1, Polynomial& p2){
    /* Przeciążenie operatora, który zwiększa wielomian o inny.*/
    p1.a += p2.a;
    p1.b += p2.b;
    p1.c += p2.c;
    p1.d += p2.d;
    p1.e += p2.e;
    p1.degree = p1.calculateDegree();
}

void operator -=(Polynomial& p1, Polynomial& p2){
    /* Przeciążenie operatora, który zmniejsza wielomian o inny.*/
    p1.a -= p2.a;
    p1.b -= p2.b;
    p1.c -= p2.c;
    p1.d -= p2.d;
    p1.e -= p2.e;
    p1.degree = p1.calculateDegree();
}
