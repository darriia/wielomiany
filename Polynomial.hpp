#ifndef WIELOMIANY_POLYNOMIAL_H
#define WIELOMIANY_POLYNOMIAL_H

#include <iostream>
#include <string>

using namespace std;


class Polynomial {
    int a, b, c, d, e;
    int degree;
public:
    Polynomial(int degree, int a, int b, int c, int d, int e);
    ~Polynomial();
    friend ostream& operator <<(ostream&, Polynomial&);
};


#endif //WIELOMIANY_POLYNOMIAL_H
