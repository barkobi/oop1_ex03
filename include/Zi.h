#pragma once

#include <iostream>
#include <cmath>
#include <iosfwd>
#include "ZiData.h"


class Zi{
public:
    //constructors:
    Zi(int a = 0, int b = 0);

    //getters
    int getReal() const;
    int getImag() const;
    int getNorm() const;
    Zi getConj() const;

    // operators:
    Zi& operator+=(const Zi &other);
    Zi& operator-=(const Zi &other);
    Zi& operator*=(const Zi &other);
    Zi& operator%=(const Zi &other);
    Zi& operator/=(const Zi &other);

private:
    // members:
    ZiData m_ziData;
};

// global operators:
Zi operator+(const Zi& first,const Zi& other);
Zi operator-(const Zi& first,const Zi& other);
Zi operator*(const Zi& first,const Zi& other);
Zi operator%(const Zi& first,const Zi& other);
Zi operator/(const Zi& first,const Zi& other);
Zi operator-(const Zi& origin);
bool operator==(const Zi& first,const Zi& other);
bool operator!=(const Zi& first,const Zi& other);
bool dividedBy(const Zi& divided,const Zi &divisor);
std::ostream& operator<< (std::ostream& os ,const  Zi& z);
