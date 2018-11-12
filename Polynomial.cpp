#include "Polynomial.hpp"

using namespace std;


string stringify(int value){
    string result;
    string valueString = to_string(value);
    if (value == 1)
        return "+";
    if (value == -1)
        return "-";
    if (value > 1)
        return "+" + valueString;
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
    if(a==0 && b==0 && c==0 && d==0) return 0;
    if(a==0 && b==0 && c==0 ) return 1;
    if(a==0 && b==0 ) return 2;
    if(a==0 ) return 3;
    return 4;
}

Polynomial::~Polynomial() {
    cout << "Deleted Polynomial" << endl;
}

ostream &operator<<(ostream &output, Polynomial &p) {
    switch(p.degree){
        case 0:
            output << stringify(p.e);
            break;
        case 1:
            output << stringify(p.d) << "x"
            << ((p.e != 0) ? stringify(p.e): "");
            break;
        case 2:
            output << stringify(p.c) << "x^2"
            << ((p.d != 0) ? stringify(p.d) + "x" : "")
            << ((p.e != 0) ? stringify(p.e): "");
            break;
        case 3:
            output << stringify(p.b) << "x^3"
            << ((p.c != 0) ? stringify(p.c) + "x^2" : "")
            << ((p.d != 0) ? stringify(p.d) + "x" : "")
            << ((p.e != 0) ? stringify(p.e): "");
            break;
        case 4:

            output << stringify(p.a) << "x^4"
            << ((p.b != 0) ? stringify(p.b) + "x^3" : "")
            << ((p.c != 0) ? stringify(p.c) + "x^2" : "")
            << ((p.d != 0) ? stringify(p.d) + "x" : "")
            << ((p.e != 0) ? stringify(p.e): "");
            break;
        default: output << "";
    }
    return output;
}

bool operator ==(Polynomial& p1, Polynomial& p2){
    if(p1.degree != p2.degree) return false;
    return p1.e == p2.e
           && p1.d == p2.d
           && p1.c == p2.c
           && p1.b == p2.b
           && p1.a == p2.a;
}

bool operator !=(Polynomial& p1, Polynomial& p2){
    if(p1.degree != p2.degree) return true;
    return p1.e != p2.e
           || p1.d != p2.d
           || p1.c != p2.c
           || p1.b != p2.b
           || p1.a != p2.a;
}

Polynomial operator +(Polynomial& p1, Polynomial& p2){
    int a = p1.a + p2.a;
    int b = p1.b + p2.b;
    int c = p1.c + p2.c;
    int d = p1.d + p2.d;
    int e = p1.e + p2.e;
    return Polynomial(a, b, c, d, e);

}

Polynomial operator -(Polynomial& p1, Polynomial& p2){
    int a = p1.a - p2.a;
    int b = p1.b - p2.b;
    int c = p1.c - p2.c;
    int d = p1.d - p2.d;
    int e = p1.e - p2.e;
    return Polynomial(a, b, c, d, e);
}

void operator +=(Polynomial& p1, Polynomial& p2){
    p1.a += p2.a;
    p1.b += p2.b;
    p1.c += p2.c;
    p1.d += p2.d;
    p1.e += p2.e;
    p1.degree = p1.calculateDegree();
}

void operator -=(Polynomial& p1, Polynomial& p2){
    p1.a -= p2.a;
    p1.b -= p2.b;
    p1.c -= p2.c;
    p1.d -= p2.d;
    p1.e -= p2.e;
    p1.degree = p1.calculateDegree();
}
