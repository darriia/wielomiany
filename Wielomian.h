#ifndef Wielomian_hpp
#define Wielomian_hpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Wielomian{
  float a,b,c;//wspolczynniki wielomianu
public:
  Wielomian(float wspA,float wspB,float wspC);
  ~Wielomian();
  vector <float> obliczPierwiastek();//zwraca wektor z pierwiastkami wielomianu
  void wyswietlPierwiastki();//wyswietla pierwiastki (zwrocone przez obliczPierwiastek())
  Wielomian rozniczkowanie();//zwraca wielomian bedacy pochodna (wielomianu this)
  friend Wielomian operator +(Wielomian &,Wielomian &);
  friend Wielomian operator -(Wielomian &,Wielomian &);
  friend void operator +=(Wielomian &,Wielomian &);
  friend void operator -=(Wielomian &,Wielomian &);
  friend ostream& operator <<(ostream&,Wielomian&);

};

#endif
