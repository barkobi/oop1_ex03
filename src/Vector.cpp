
#include "../include/Vector.h"

Vector::Vector(int size, const Zi &init)
        : m_arr(Array(size,init)) {}

Vector::Vector(Zi *arr, int size)
        : m_arr(Array(arr, size)) {}

int Vector::size() const {return m_arr.size();}

Zi &Vector::operator[](int index) {return m_arr[index];}

Zi Vector::operator[](int index) const {return m_arr[index];}

bool Vector::operator==(const Vector &other) const{
    return m_arr == other.m_arr;
}

Vector operator+(const Vector &v1, const Vector &v2){
    int max_len = v1.size() >= v2.size() ? v1.size() : v2.size();
    Vector res = Vector(max_len);
    for(int i=0 ; i<v1.size() ; i++)
        res[i] = v1[i];

    for(int i=0 ; i<v2.size() ; i++)
        res[i] += v2[i];

    return res;
}

Vector operator-(const Vector &v1, const Vector &v2){
    Vector res = v1 + (-v2);
    return res;
}

Vector operator-(const Vector &v){
    Vector tmp = Vector(v.size());
    for(int i=0 ; i<v.size() ; i++)
        tmp[i]= -v[i];
    return tmp;
}

Vector operator*(const Vector &v1, const Vector &v2){
    int max_len = v1.size() >= v2.size() ? v1.size() : v2.size();
    Vector res = Vector(max_len);
    for(int i=0 ; i<v1.size() ; i++)
        res[i] = v1[i];

    for(int i=0 ; i<v2.size() ; i++)
        res[i] *= v2[i];

    return res;
}

Vector operator*(const Vector &v, int s){
    Vector tmp = Vector(v.size());
    for(int i=0 ; i<v.size() ; i++){
        tmp[i] = Zi(tmp[i].real()*s, tmp[i].imag()*s);
    }
    return tmp;
}

Vector operator*(int s, const Vector &v){
    return v * s;
}

Vector& operator+=(Vector v1, const Vector &v2){
    v1 = v1+v2;
    return v1;
}

Vector& operator-=(Vector v1, const Vector &v2){
    v1 = v1-v2;
    return v1;
}

Vector& operator*=(Vector v1, const Vector &v2){
    v1 = v1 *v2;
    return v1;
}

Vector& operator*=(Vector v, int s){
    v = v*s;
    return v;
}

bool operator!=(const Vector &v1, const Vector &v2){
    return !(v1 == v2);
}

std::ostream& operator<< (std::ostream&, const Vector& v){
    for(int i=0 ; i<v.size() ; i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}