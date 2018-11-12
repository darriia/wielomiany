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

ostream &operator<<(ostream &output, Polynomial &w) {
    switch(w.degree){
        case 0:
            output << w.e;
            break;
        case 1:
            output << w.d << "x"
            << ((w.e > 0) ? "+" + to_string(w.e): "");
            break;
        case 2:
            output << w.c << "x^2"
            << ((w.d > 0) ? "+" + to_string(w.d) + "x" : "")
            << ((w.e > 0) ? "+" + to_string(w.e): "");
            break;
        case 3:
            output << w.b << "x^3"
            << ((w.c > 0) ? "+" + to_string(w.c) + "x^2" : "")
            << ((w.d > 0) ? "+" + to_string(w.d)+ "x" : "")
            << ((w.e > 0) ? "+" + to_string(w.e): "");
            break;
        case 4:
            output << w.a << "x^4"
            << ((w.b > 0) ? "+" + to_string(w.b)+ "x^3" : "")
            << ((w.c > 0) ? "+" + to_string(w.c)+ "x^2" : "")
            << ((w.d > 0) ? "+" + to_string(w.d)+ "x" : "")
            << ((w.e > 0) ? "+" + to_string(w.e): "");
            break;
        default: output << "";
    }
    return output;
}