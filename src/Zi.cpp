#include "../include/Zi.h"
#include <ostream>


Zi::Zi(int a, int b) : m_ziData(ZiData(a,b)){}

int Zi::getReal() const {return m_ziData.a;}

int Zi::getImag() const {return m_ziData.b;}

int Zi::getNorm() const {return m_ziData.a * m_ziData.a + m_ziData.b * m_ziData.b;}


Zi Zi::getConj() const {
    return Zi(m_ziData.a,-(m_ziData.b));}

Zi Zi::operator+(const Zi& other) const {
    return Zi(m_ziData.a + other.m_ziData.a , m_ziData.b +other.m_ziData.b);
}

Zi Zi::operator-(const Zi& other) const{
    return Zi(m_ziData.a - other.m_ziData.a,m_ziData.b - other.m_ziData.b);
}

Zi Zi::operator*(const Zi&  other) const {
    return Zi((m_ziData.a * other.m_ziData.a) - (m_ziData.b * other.m_ziData.b),
              (m_ziData.a * other.m_ziData.b) + (m_ziData.b * other.m_ziData.a));
}

Zi Zi::operator%(const Zi& other) const{
    Zi div =  this->operator/(other);
    return Zi(this->m_ziData.a % div.m_ziData.a,this->m_ziData.b % div.m_ziData.b);

}

Zi Zi::operator/(const Zi& other) const {
    Zi div = this->operator*(other.getConj());
    int real = round((double)div.m_ziData.a / (double)other.getNorm());
    int image = round((double)div.m_ziData.b / (double)other.getNorm());
    return Zi(real,image);
}

Zi& Zi::operator+=(const Zi &other) {
    m_ziData.a += other.m_ziData.a;
    m_ziData.b += other.m_ziData.b;
    return *this;
}

Zi& Zi::operator-=(const Zi &other) {
    return this->operator+=(-other);
}

Zi& Zi::operator*=(const Zi &other) {
    return *this = this->operator*(other);;
}

Zi& Zi::operator%=(const Zi &other) {
    return *this = this->operator%(other);
}

Zi& Zi::operator/=(const Zi &other) {

    return *this = this->operator/(other);
}

Zi Zi::operator-() const {
    return Zi(-m_ziData.a,-m_ziData.b);
}

bool Zi::operator==(const Zi &other) const {
    return this->m_ziData.a == other.m_ziData.a && this->m_ziData.b == other.m_ziData.b;
}

bool Zi::operator!=(const Zi &other) const {
    return this->m_ziData.a != other.m_ziData.a && this->m_ziData.b != other.m_ziData.b;;
}

bool Zi::dividedBy(const Zi &divisor) const {
    this->operator%(divisor);
    return divisor.m_ziData.a == 0 && divisor.m_ziData.b == 0;
}


std::ostream& operator<< (std::ostream& os ,const  Zi& z){
    os << z.getReal() << " + " << z.getImag() << 'i';
    return os;
}

