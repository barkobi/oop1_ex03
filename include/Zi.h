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
    int real() const;
    int imag() const;
    int norm() const;
    Zi conj() const;

    bool dividedBy(const Zi &divisor);

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
std::ostream& operator<< (std::ostream& os ,const  Zi& z);
