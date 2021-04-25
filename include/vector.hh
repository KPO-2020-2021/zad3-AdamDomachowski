#pragma once

#include "size.hh"
#include <iostream>
#include <cmath>

class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    bool operator == ( const Vector &v) const;

    Vector operator + (const Vector &v);

    Vector operator - (const Vector &v);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);

    double length(const Vector &v);


};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);

