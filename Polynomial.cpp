#include "Polynomial.hpp"

using namespace std;


Polynomial::Polynomial(int degree_, int a_, int b_, int c_, int d_, int e_) {
    a = a_;
    b = b_;
    c = c_;
    d = d_;
    e = e_;
    degree = degree_;
}

Polynomial::~Polynomial() {
    cout << "Deleted Polynomial" << endl;
}

ostream &operator<<(ostream &output, Polynomial &p) {
    switch(p.degree){
        case 0:
            output << p.e;
            break;
        case 1:
            output << p.d << "x"
            << ((p.e > 0) ? "+" + to_string(p.e): "");
            break;
        case 2:
            output << p.c << "x^2"
            << ((p.d > 0) ? "+" + to_string(p.d) + "x" : "")
            << ((p.e > 0) ? "+" + to_string(p.e): "");
            break;
        case 3:
            output << p.b << "x^3"
            << ((p.c > 0) ? "+" + to_string(p.c) + "x^2" : "")
            << ((p.d > 0) ? "+" + to_string(p.d)+ "x" : "")
            << ((p.e > 0) ? "+" + to_string(p.e): "");
            break;
        case 4:
            output << p.a << "x^4"
            << ((p.b > 0) ? "+" + to_string(p.b)+ "x^3" : "")
            << ((p.c > 0) ? "+" + to_string(p.c)+ "x^2" : "")
            << ((p.d > 0) ? "+" + to_string(p.d)+ "x" : "")
            << ((p.e > 0) ? "+" + to_string(p.e): "");
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


