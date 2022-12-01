
#include "../include/array.h"

Array::Array(int size, Zi initial) {
    m_arr = new (std::nothrow) Zi[size];
    m_size = size;

    for(int i=0 ; i<m_size ; i++)
        m_arr[i] = initial;
}

Array::Array(Zi *arr, int size) {
    m_size = size;
    m_arr = new (std::nothrow) Zi[size];

    for(int i=0 ; i<m_size ; i++)
        m_arr[i] = arr[i];
}

Array::Array(const Array &old) {
    Array(old.m_arr, old.m_size);
}

Array::~Array() {
    m_size = 0;
    delete [] m_arr;
}

int Array::getSize() const {return m_size;}

bool Array::isEmpty() const {return m_size == 0;}

bool Array::operator==(const Array &other) const {
    if(m_size != other.m_size)
        return false;

    for(int i=0 ; i<m_size ; i++)
        if(m_arr[i] != other.m_arr[i])
            return false;

    return true;
}

bool Array::operator!=(const Array &other) const {
    return !(this->operator==(other));
}

Array Array::operator+(const Array &other) const {
    Array res = Array(m_size+other.m_size);

    for(int i=0 ; i<m_size ; i++)
        res[i] = m_arr[i];

    for(int i=0 ; i<other.m_size ; i++)
        res[m_size+i] = other.m_arr[i];

    return res;
}

Array &Array::operator+=(const Array &other) {
    Zi *tmp = new (std::nothrow) Zi[m_size+other.m_size];

    for(int i=0 ; i<m_size ; i++)
        tmp[i] = m_arr[i];

    for(int i=0 ; i<other.m_size ; i++)
        tmp[m_size+i] = other.m_arr[i];

    m_size+=other.m_size;
    delete [] m_arr;
    m_arr = tmp;
}

Zi &Array::operator[](int index) {
    return m_arr[index];
}

Zi Array::operator[](int index) const {
    return m_arr[index];
}
