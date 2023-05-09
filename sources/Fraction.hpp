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
        friend Fraction operator++(const Fraction&);
        friend Fraction operator--(const Fraction&);
        friend Fraction operator++(const Fraction&,int);
        friend Fraction operator--(const Fraction&,int);
        friend ostream& operator<<(ostream& os, const Fraction&);
        friend Fraction operator>>(ostream& os, const Fraction&);
        friend istream & operator>>(istream &in,  Fraction &c);
    };
    
    
} 