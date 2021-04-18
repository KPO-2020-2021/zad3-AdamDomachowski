#pragma once  
#include "size.hh"
#include "vector.hh"
#include "matrix.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>


class rectangle {

private:

    Vector wierzcholki[SIZE][SIZE];

public:

    rectangle ();

    rectangle(Vector [SIZE][SIZE]);            // Konstruktor klasy

    rectangle operator + (Vector wek);

    Vector  &operator () ( int row,  int column); // umozliwia odwolywanie sie za pomoca (a,b)

    const Vector &operator () ( int row,  int column) const;

    rectangle rotacja(double angle, int times);
    

};

std::istream &operator>>(std::istream &in, rectangle &rec);
std::ostream &operator<<(std::ostream &out, rectangle const &rec);

// wspolrzedne wierzcholkow
static double a[] = {100,  100};
static double b[] = {100, 150};
static double c[] = {450,150};
static double d[] = {450, 100};
static Vector wsp[][SIZE] = {{ a, b},{ c, d}};

