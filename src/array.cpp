#include "../include/array.h"


Array::Array(int size, Zi initial) {
    m_arr = new Zi[size];
    m_size = size;

    for (int i = 0; i < m_size; i++)
        m_arr[i] = initial;
}

Array::Array(Zi* arr, int size) {
    m_size = size;
    m_arr = new Zi[size];

    for (int i = 0; i < m_size; i++)
        m_arr[i] = arr[i];
}

Array::Array(const Array& old): Array(old.m_arr, old.m_size){}

Array::~Array() {
    delete[] m_arr;
}

int Array::size() const { return m_size; }

bool Array::isEmpty() const { return m_size == 0; }

bool operator==(const Array& arr1, const Array& arr2) {
    if (arr1.size() != arr2.size())
        return false;

    for (int i = 0; i < arr1.size(); i++)
        if (arr1[i] != arr2[i])
            return false;

    return true;
}

bool operator!=(const Array& arr1, const Array& arr2) {
    return !(arr1 == arr2);
}

Array operator+(const Array& arr1, const Array& arr2) {
    Array res = Array(arr1.size() + arr2.size());

    for (int i = 0; i < arr1.size(); i++)
        res[i] = arr1[i];

    for (int i = 0; i < arr2.size(); i++)
        res[arr1.size() + i] = arr2[i];

    return res;
}

Array& operator+=(Array& arr1, const Array& arr2) {
    arr1 = arr1 + arr2;
    return arr1;
}

Zi& Array::operator[](int index) {
    return m_arr[index];
}

const Zi Array::operator[](int index) const {
    return m_arr[index];
}

Array& Array::operator=(const Array& other)
{
    if (this != &other) {
        Zi* newarr = new Zi[other.m_size];
        for (int i = 0; i < other.m_size; i++) {
            newarr[i] = other[i];
        }
        delete[] this->m_arr;

        this->m_arr = newarr;
        this->m_size = other.m_size;
    }
    return *this;
}
