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
Zi& operator+=(Zi z1, const Zi &z2);
Zi& operator-=(Zi z1, const Zi &z2);
Zi& operator*=(Zi z1, const Zi &z2);
Zi& operator/=(Zi z1, const Zi &z2);
Zi& operator%=(Zi z1, const Zi &z2);
bool operator==(const Zi& first,const Zi& other);
bool operator!=(const Zi& first,const Zi& other);
bool dividedBy(const Zi& divided,const Zi &divisor);
std::ostream& operator<< (std::ostream& os ,const  Zi& z);
