#include <stdexcept>
#include <sstream>
#include <cstdlib>

#include "Rational.h"
#include "mathutils.h"

using namespace std;

Rational::Rational(int aNum, int aDen)
: num(aNum), den(aDen)
{
    if (den == 0)
    {
        throw std::runtime_error("Rational exception: denominator equal to 0");
    }
    
    int d = gcd(abs(num), abs(den));
    num /= d;
    den /= d;
    
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

string Rational::toSchoolForm() const
{
    ostringstream sout;
    
    sout << "School form: ";
    int whole = num / den;
    if (whole != 0)
    {
        sout << whole;
    }
    if (num % den != 0)
    {
        sout << "(" << num % den << "/" << den << ")";
    }
    
    return sout.str();
}

ostream& operator<<(ostream& out, const Rational& a)
{
    return out << a.num << '/' << a.den;
}

Rational operator+(const Rational& a, const Rational& b)
{
    return Rational(a.num * b.den + a.den * b.num, a.den * b.den);
}


Rational operator-(const Rational& a, const Rational& b)
{
    return Rational(a.num * b.den - a.den * b.num, a.den * b.den);
}

Rational operator*(const Rational& a, const Rational& b)
{
    return Rational(a.num * b.num, a.den * b.den);
}

Rational operator/(const Rational& a, const Rational& b)
{
    return Rational(a.num * b.den, a.den * b.num);
}

istream& operator>>(istream& inp, Rational& a)
{
    int num;
    char ch;
    int den;
    
    if (inp >> num >> noskipws and inp >> ch and ch == '/' and inp >> den)
    {
        Rational t(num, den);
        a = t;
    }
    else
    {
        inp.setstate(ios::failbit);
    }
    
    return inp >> skipws;
}

