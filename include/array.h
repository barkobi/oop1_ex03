
#include "Zi.h"

class Array{
public:
    // constructors / destructors:
    explicit Array(int size = 0, Zi initial = Zi());
    Array(Zi arr[], int size);
    Array(const Array &old);
    ~Array();

    // getters / setters:
    int getSize() const;
    bool isEmpty() const;

    const Zi operator[](int index) const;
    Zi& operator[](int index);


private:
    Zi *m_arr;
    int m_size;

};

// operators:
Array operator+(const Array& arr1, const Array& arr2);
Array& operator+=(Array &arr1, const Array& arr2);
bool operator==(const Array& arr1, const Array& arr2);
bool operator!=(const Array& arr1, const Array& arr2);