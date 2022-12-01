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
    Zi operator+(const Zi& other) const;
    Zi operator-(const Zi& other) const;
    Zi operator*(const Zi&  other) const;
    Zi operator%(const Zi& other) const;
    Zi operator/(const Zi& other) const;
    Zi& operator+=(const Zi &other);
    Zi& operator-=(const Zi &other);
    Zi& operator*=(const Zi &other);
    Zi& operator%=(const Zi &other);
    Zi& operator/=(const Zi &other);
    Zi operator-() const;
    bool operator==(const Zi &other) const;
    bool operator!=(const Zi &other) const;
    bool dividedBy(const Zi &divisor) const;


private:
    // members:
    ZiData m_ziData;
};

std::ostream& operator<< (std::ostream& os ,const  Zi& z);
