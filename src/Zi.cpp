#include "../include/Zi.h"
#include <ostream>


Zi::Zi(int a, int b) : m_ziData(ZiData(a,b)){}

int Zi::getReal() const {return m_ziData.a;}

int Zi::getImag() const {return m_ziData.b;}

int Zi::getNorm() const {return m_ziData.a * m_ziData.a + m_ziData.b * m_ziData.b;}


Zi Zi::getConj() const {
    return Zi(m_ziData.a,-(m_ziData.b));}

Zi& operator+=(Zi z1, const Zi &z2){
    z1 = z1+z2;
    return z1;
}

Zi& operator-=(Zi z1, const Zi &z2){
    z1 = z1-z2;
    return z1;
}

Zi& operator*=(Zi z1, const Zi &z2){
    z1 = z1*z2;
    return z1;
}

Zi& operator/=(Zi z1, const Zi &z2)
{
    z1 = z1/z2;
    return z1;
}

Zi& operator%=(Zi z1, const Zi &z2){
    z1 = z1%z2;
    return z1;
}

std::ostream& operator<< (std::ostream& os ,const  Zi& z){
    char op = z.getImag() >= 0 ? '+' : '-';
    os << z.getReal() << " " << op << " " << abs(z.getImag()) << 'i';
    return os;
}

Zi operator+(const Zi& first, const Zi& other) {
    return Zi(first.getReal() + other.getReal(),first.getImag() + other.getImag());
}

Zi operator-(const Zi& first, const Zi& other) {
    return Zi(first.getReal() - other.getReal(),first.getImag() - other.getImag());
}

Zi operator*(const Zi& first,const Zi& other) {
    return Zi((first.getReal() * other.getReal()) - (first.getImag() * other.getImag()),
              (first.getReal() * other.getImag()) + (first.getImag() * other.getReal()));
}

Zi operator-(const Zi& origin ) {
    return Zi(-origin.getReal(),-origin.getImag());
}

Zi operator/(const Zi& first,const Zi& other) {
    Zi div = first * other.getConj();
    int real = round((double)div.getReal() / (double)other.getNorm());
    int image = round((double)div.getImag() / (double)other.getNorm());
    return Zi(real,image);
}

Zi operator%(const Zi& first,const Zi& other) {
    Zi div =  first / other;
    return Zi(first.getReal() % div.getReal(),first.getImag() % div.getImag());
}

bool operator==(const Zi& first,const Zi& other) {
    return first.getReal() == other.getReal() && first.getImag() == other.getImag();
}

bool operator!=(const Zi& first,const Zi& other) {
    return first.getReal() != other.getReal() && first.getImag() != other.getImag();
}

bool dividedBy(const Zi &divided, const Zi &divisor) {
    Zi temp = divided % divisor;
    return temp.getReal() == 0 && temp.getImag() == 0;
}
