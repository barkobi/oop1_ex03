
#include "Vector.h"

Vector::Vector(int size, const Zi &init) {
    m_size = size;
    m_arr = new (std::nothrow) Array[size];

    for(int i=0 ; i<size ; i++)
        m_arr[i] = Array();
}