
#include "Zi.h"

class Array{
public:
    // constructors / destructors:
    explicit Array(int size = 1, Zi initial = Zi());
    Array(Zi arr[], int size);
    Array(const Array &old);
    ~Array();

    // getters / setters:
    int getSize() const;
    bool isEmpty() const;

    // operators:
    Array operator+(const Array& other) const;
    Array& operator+=(const Array& other);
    Zi& operator[](int index);
    Zi operator[](int index) const;
    bool operator==(const Array &other) const;
    bool operator!=(const Array &other) const;

private:
    Zi *m_arr;
    int m_size;

};
