#pragma once

#include <iostream>
#include <cmath>
#include "ZiData.h"
#include <iosfwd>


class Zi{
public:
    //--ctor
    Zi(int a = 0, int b = 0);
    //getters
    int getReal() const;
    int getImag() const;
    int getNorm() const;
    Zi getConj() const;
    // overloding
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
    ZiData m_ziData;
};

std::ostream& operator<< (std::ostream& os ,const  Zi& z);
