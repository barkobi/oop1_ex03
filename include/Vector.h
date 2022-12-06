#pragma once

#include "Zi.h"
#include "array.h"

class Vector {
public:
    // constructors / destructors:
    explicit Vector(int size = 0, const Zi& init = {});
    Vector(Zi arr[], int size);

    ~Vector();

    //getters / setters:
    int size() const;

    // operators:
    Zi operator[](int index) const;
    Zi& operator[](int index);
    bool operator==(const Vector& other) const;
    Vector& operator=(const Vector& other);
private:
    Array m_arr;
};

Vector operator+(const Vector& v1, const Vector& v2);
Vector operator-(const Vector& v1, const Vector& v2);
Vector operator-(const Vector& v);
Vector operator*(const Vector& v1, const Vector& v2);
Vector operator*(const Vector& v, int s);
Vector operator*(int s, const Vector& v);
Vector& operator+=(Vector& v1, const Vector& v2);
Vector& operator-=(Vector& v1, const Vector& v2);
Vector& operator*=(Vector& v1, const Vector& v2);
Vector& operator*=(Vector& v, int s);
bool operator!=(const Vector& v1, const Vector& v2);

std::ostream& operator<< (std::ostream&, const Vector& v);