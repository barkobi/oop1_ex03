#include "../include/Zi.h"
#include <ostream>


Zi::Zi(int a, int b) : m_ziData(ZiData(a,b)){}

int Zi::real() const {return m_ziData.a;}

int Zi::imag() const {return m_ziData.b;}

int Zi::norm() const {return m_ziData.a * m_ziData.a + m_ziData.b * m_ziData.b;}

bool Zi::dividedBy(const Zi &divisor) {
    Zi temp = operator%(*this, divisor);
    return temp.real() == 0 && temp.imag() == 0;
}

Zi Zi::conj() const {
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
    char op = z.imag() >= 0 ? '+' : '-';
    os << z.real() << " " << op << " " << abs(z.imag()) << 'i';
    return os;
}

Zi operator+(const Zi& first, const Zi& other) {
    return Zi(first.real() + other.real(),first.imag() + other.imag());
}

Zi operator-(const Zi& first, const Zi& other) {
    return Zi(first.real() - other.real(),first.imag() - other.imag());
}

Zi operator*(const Zi& first,const Zi& other) {
    return Zi((first.real() * other.real()) - (first.imag() * other.imag()),
              (first.real() * other.imag()) + (first.imag() * other.real()));
}

Zi operator-(const Zi& origin ) {
    return Zi(-origin.real(),-origin.imag());
}

Zi operator/(const Zi& first,const Zi& other) {
    Zi div = first * other.conj();
    int real = round((double)div.real() / (double)other.norm());
    int imag = round((double)div.imag() / (double)other.norm());
    return Zi(real,imag);
}

Zi operator%(const Zi& first,const Zi& other) {
    Zi div =  first / other;
    return Zi(first.real() % div.real(),first.imag() % div.imag());
}

bool operator==(const Zi& first,const Zi& other) {
    return first.real() == other.real() && first.imag() == other.imag();
}

bool operator!=(const Zi& first,const Zi& other) {
    return first.real() != other.real() && first.imag() != other.imag();
}