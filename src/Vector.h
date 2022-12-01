
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
    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    Vector operator*(const Vector &other) const;
    Vector operator*(int s) const;
    Vector& operator+=(const Vector &other);
    Vector& operator-=(const Vector &other);
    Vector& operator*=(const Vector &other);
    Vector& operator*=(int s);
    Vector& operator-();
    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;
    Array operator[](int index) const;
    Array& operator[](int index);

private:
    Array *m_arr;
    int m_size;
};

Vector operator*(int s, const Vector &other);
std::ostream& operator<< (std::ostream&, const Vector&);