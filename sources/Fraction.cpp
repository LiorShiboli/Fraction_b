#include "Fraction.hpp" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include<math.h>
using namespace std;

namespace ariel
{
    Fraction::Fraction(int nume,int denom):numerator(nume),denominator(denom)
    {
        if (denominator == 0){
            throw invalid_argument("cannot divide by 0");
        }
        this->reduce();
    }
    Fraction::Fraction(float num)
    {
        this->denominator=1000;
        this->numerator = (int)(num*1000);
        this->reduce();
    }
    Fraction::Fraction(){
        this->denominator = 1;
        this->numerator = 1;
    }
    int Fraction::getDenominator() const{
        return this->denominator;
    }
    int Fraction::getNumerator() const {
        return this->numerator;
    }
    
    void Fraction::reduce(){
        int gcd = abs(__gcd(this->denominator,this->numerator));
        int sign = -2*signbit(this->denominator)+1;
        this->numerator =sign*(this->numerator/gcd);
        this->denominator = abs(this->denominator/gcd);
    }

    Fraction Fraction::operator--(int){
        Fraction ret = Fraction(this->numerator,this->denominator);
        *this = *this-1;
        return ret;
    }
    Fraction Fraction::operator++(int){
        Fraction ret = Fraction(this->numerator,this->denominator);
        *this = *this+1;
        return ret;
    }
    Fraction& Fraction::operator--(){
        
        *this = *this-1;
        return *this;
    }
    Fraction& Fraction::operator++(){
        *this = *this+1;
        return *this;
    }




    Fraction operator-(const Fraction &frac){
        if (frac.numerator == numeric_limits<int>::min()){
            throw overflow_error("subtraction overflow");
        }
        return Fraction(-(frac.numerator),frac.denominator);
    }
    Fraction operator+(const Fraction& fraction1 ,const Fraction& fraction2 ){
        int numerator1 = fraction1.denominator*fraction2.numerator;
        int numerator2 = fraction2.denominator*fraction1.numerator;
        if (fraction2.numerator!=0 && numerator1/fraction2.numerator!=fraction1.denominator)
        {
            throw overflow_error("addition overflow");
        }
        if (fraction1.numerator!=0 && numerator2/fraction1.numerator!=fraction2.denominator)
        {
            throw overflow_error("addition overflow");
        }
        int denominator = fraction1.denominator*fraction2.denominator;
         if (fraction2.denominator!=0 && denominator/fraction2.denominator!=fraction1.denominator)
        {
            throw overflow_error("addition overflow");
        }
        if (numerator1 > 0 && numerator2 >numeric_limits<int>::max()- numerator1) {
        throw overflow_error("addition overflow");
        } else if (numerator1 < 0 && numerator2 < INT32_MIN - numerator1) {
           throw overflow_error("addition overflow");
        }
        
        int numerator=numerator1+numerator2;
        return Fraction(numerator,denominator);
    }
    bool operator==(const Fraction& fraction1, const Fraction& fraction2 ){
        return ((fraction1.denominator==fraction2.denominator)&&(fraction1.numerator==fraction2.numerator));
    }
    bool operator<=(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return fraction1.numerator*fraction2.denominator<=fraction1.denominator*fraction2.numerator;
    }
    bool operator>=(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return fraction2 <= fraction1;
    }
    bool operator<(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return (fraction1.numerator*fraction2.denominator)<(fraction1.denominator*fraction2.numerator);
    }
    bool operator>(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return fraction2<fraction1;
    }
    Fraction operator-(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return fraction1 + -fraction2;
    }
    Fraction operator*(const Fraction& fraction1 ,const Fraction& fraction2 ){
        int numerator = fraction1.numerator*fraction2.numerator;
        int denominator = fraction1.denominator*fraction2.denominator;
        
        
        if (fraction2.denominator!=0 && denominator/fraction2.denominator!=fraction1.denominator)
        {
            throw overflow_error("multiplication overflow");
        }
        if (fraction2.numerator!=0 && numerator/fraction2.numerator!=fraction1.numerator)
        {
            throw overflow_error("multiplication overflow");
        }
        
        return Fraction(numerator,denominator);
    }
    Fraction operator/(const Fraction& fraction1 ,const Fraction& fraction2) {
        if (fraction2.numerator==0)
        {
            throw runtime_error("c");
        }
        Fraction oneOver = Fraction(fraction2.denominator,fraction2.numerator);
        return fraction1*oneOver;
    }
   
    ostream& operator<<(ostream& output, const Fraction& fraction ){
        return output<<fraction.numerator<<"/"<<fraction.denominator;
    }
    istream & operator >> (istream &input,  Fraction &fraction){
        int numerator,denominator=0;
        input>>numerator>>denominator;
        if (denominator==0){
            throw runtime_error("invalid input");
        }
        fraction.denominator=denominator;
        fraction.numerator = numerator;
        fraction.reduce();
        return input;
    }
    
    
} // namespace 
