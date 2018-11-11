#include "Wielomian.h"

using namespace std;

Wielomian::Wielomian(float wspA, float wspB, float wspC) {
    a = wspA;
    b = wspB;
    c = wspC;
}

Wielomian::~Wielomian() {
    cout << "Wielomian usuniety" << endl;
}

Wielomian Wielomian::rozniczkowanie() {
    if (a == 0) return Wielomian(0, 0, b);
    else return Wielomian(0, 2 * a, b);
}

vector<float> Wielomian::obliczPierwiastek() {
    vector<float> pierwiastki;

    if (a == 0) {//jezeli jest to jednomian
        if (b == 0) return pierwiastki;
        pierwiastki.push_back(-c / b);
    } else {//jezeli jest to dwumian
        float delta = b * b - 4 * a * c;
        if (delta == 0) pierwiastki.push_back((-b) / (2 * a));//1 pierwiastek
        else if (delta > 0) {//delta >0 ;2 pierwiastki
            pierwiastki.push_back((-b + sqrt(delta)) / (2 * a));
            pierwiastki.push_back((-b - sqrt(delta)) / (2 * a));
        } else return pierwiastki;//delta <0
    }
    return pierwiastki;
}//koniec obliczPierwiastek()


//Przeciazenia operatorow---------------------
Wielomian operator+(Wielomian &wielomian1, Wielomian &wielomian2) {
    return Wielomian(wielomian1.a + wielomian2.a, wielomian1.b + wielomian2.b, wielomian1.c + wielomian2.c);
}

Wielomian operator-(Wielomian &wielomian1, Wielomian &wielomian2) {
    return Wielomian(wielomian1.a - wielomian2.a, wielomian1.b - wielomian2.b, wielomian1.c - wielomian2.c);
}

void operator+=(Wielomian &zwracany, Wielomian &wielomian2) {
    zwracany = Wielomian(zwracany.a + wielomian2.a, zwracany.b + wielomian2.b, zwracany.c + wielomian2.c);
}

void operator-=(Wielomian &zwracany, Wielomian &wielomian2) {
    zwracany = Wielomian(zwracany.a - wielomian2.a, zwracany.b - wielomian2.b, zwracany.c - wielomian2.c);
}

ostream &operator<<(ostream &wyjscie, Wielomian &w) {
    if (w.a == 0) {
        if (w.b == 0) wyjscie << w.c;//liczba
        else wyjscie << w.b << "x" << ((w.c > 0) ? "+" : "") << w.c;//jednomian
    } else wyjscie << w.a << "x^2" << ((w.b > 0) ? "+" : "") << w.b << "x" << ((w.c > 0) ? "+" : "") << w.c;//dwumian
    return wyjscie;
}
//-------------------------------------------------

void Wielomian::wyswietlPierwiastki() {
    vector<float> v = this->obliczPierwiastek();
    cout << "----Pierwastki " << *this << "----" << endl;
    if (this->a == 0 && this->b == 0) {
        if (this->c == 0) cout << "Wielomian zerowy" << endl;
        else cout << "Wielomian stopnia 0" << endl;
    } else {
        if (v.size() == 0) cout << "Brak pierwiastkow" << endl;
        else if (v.size() == 1) cout << "x1 = " << v[0] << endl;
        else if (v.size() == 2) cout << "x1 = " << v[0] << "   " << "x2 = " << v[1] << endl;
    }
    cout << "-------------------------" << endl << endl;
};
