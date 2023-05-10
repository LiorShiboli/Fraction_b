#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
        
        void reduce();
    public:
        
        Fraction(int nume,int denom);
        Fraction(float number);
        Fraction();
        int getNumerator() const;
        int getDenominator() const;
        friend Fraction operator-(const Fraction &);
        friend Fraction operator+(const Fraction&,const Fraction&);
        friend bool operator==(const Fraction&,const Fraction&);
        friend bool operator<=(const Fraction&,const Fraction&);
        friend bool operator>=(const Fraction&,const Fraction&);
        friend bool operator<(const Fraction&,const Fraction&);
        friend bool operator>(const Fraction&,const Fraction&);
        friend Fraction operator-(const Fraction&,const Fraction&);
        friend Fraction operator*(const Fraction&,const Fraction&);
        friend Fraction operator/(const Fraction&,const Fraction&);
        Fraction& operator++();
        Fraction& operator--();
        Fraction operator++(int);
        Fraction operator--(int);
        friend ostream& operator<<(ostream& output, const Fraction&);
        friend istream & operator>>(istream &input,  Fraction &);
    };
    
    
} 