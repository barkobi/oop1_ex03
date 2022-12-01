
#include "../include/Zi.h"
#include "../include/array.h"

class Vector{
public:
    // constructors / destructors:
    explicit Vector(int size = 0, const Zi& init = {});
    Vector(Zi arr[], int size);
    Vector(const Vector &old);
    ~Vector();

    //getters / setters:
    int getSize() const;
    bool isEmpty() const;

    // operators:
    Array operator[](int index) const;
    Array& operator[](int index);

private:
    Array *m_arr;
    int m_size;
};

Vector operator+(const Vector &v1, const Vector &v2);
Vector operator-(const Vector &v1, const Vector &v2);
Vector operator*(const Vector &v1, const Vector &v2);
Vector operator*(const Vector &v, int s);
Vector operator*(int s, const Vector &v);
Vector& operator+=(Vector v1, const Vector &v2);
Vector& operator-=(Vector v1, const Vector &v2);
Vector& operator*=(Vector v1, const Vector &v2);
Vector& operator*=(Vector v, int s);
Vector& operator-(const Vector &v2);
bool operator==(const Vector &v1, const Vector &v2);
bool operator!=(const Vector &v1, const Vector &v2);

std::ostream& operator<< (std::ostream&, const Vector&);