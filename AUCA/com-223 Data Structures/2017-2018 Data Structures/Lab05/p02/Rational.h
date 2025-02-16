#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

class Rational
{
    friend std::ostream& operator<<(std::ostream& out, const Rational& a);
    friend std::istream& operator>>(std::istream& inp, Rational& a);
    friend Rational operator+(const Rational& a, const Rational& b);
    friend Rational operator-(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend Rational operator/(const Rational& a, const Rational& b);
    
    private:
    
    int num;
    int den;
    
    public:
    
    Rational()
    : num(0), den(1)
    {
    }
      
    Rational(int aNum, int aDen);
    
    // inline method
    double toDouble() const
    {
        return double(num) / den;
    }
    
    std::string toSchoolForm() const; 
};

#endif