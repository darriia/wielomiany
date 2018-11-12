#ifndef WIELOMIANY_POLYNOMIAL_H
#define WIELOMIANY_POLYNOMIAL_H

#include <iostream>
#include <string>

using namespace std;


class Polynomial {
public:
    int degree, a, b, c, d, e;

    Polynomial(int a, int b, int c, int d, int e);
    ~Polynomial();
    Polynomial differentiation();
    int calculateDegree();
    friend Polynomial operator +(Polynomial&, Polynomial&);
    friend Polynomial operator -(Polynomial&, Polynomial&);
    friend bool operator ==(Polynomial&, Polynomial&);
    friend bool operator !=(Polynomial&, Polynomial&);
    friend void operator +=(Polynomial&, Polynomial&);
    friend void operator -=(Polynomial&, Polynomial&);
    friend ostream& operator <<(ostream&, Polynomial&);

};


#endif //WIELOMIANY_POLYNOMIAL_H
