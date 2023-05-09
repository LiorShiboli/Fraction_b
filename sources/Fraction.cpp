#include "Fraction.hpp" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    Fraction::Fraction(int nume,int denom):numerator(nume),denominator(denom)
    {
        if (denominator == 0){
            throw runtime_error("cannot divide by 0");
        }
        this->reduce();
    }
    Fraction::Fraction(float num)
    {
        this->denominator=1000;
        this->numerator = (int)(num*1000);
        this->reduce();
    }
    int Fraction::getDenominator() const{
        return this->denominator;
    }
    int Fraction::getNumerator() const {
        return this->numerator;
    }
    
    void Fraction::reduce(){
    this->denominator = 1;
    }
    Fraction operator-(const Fraction &frac){
        return Fraction(-(frac.getNumerator()),frac.getDenominator());
    }
    Fraction operator+(const Fraction& fraction1 ,const Fraction& fraction2 ){
        int numerator = fraction1.denominator*fraction2.numerator+fraction2.denominator*fraction1.numerator;
        int denominator = fraction1.denominator*fraction2.denominator;
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
        return fraction1.numerator*fraction2.denominator<fraction1.denominator*fraction2.numerator;
    }
    bool operator>(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return fraction1<fraction2;
    }
    Fraction operator-(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return fraction1 + -fraction2;
    }
    Fraction operator*(const Fraction& fraction1 ,const Fraction& fraction2 ){
        return Fraction(fraction1.numerator*fraction2.numerator,fraction1.denominator*fraction2.denominator);
    }
    Fraction operator/(const Fraction& fraction1 ,const Fraction& fraction2) {
        Fraction oneOver = Fraction(fraction2.denominator,fraction1.numerator);
        return fraction1*oneOver;
    }
    Fraction operator++(const Fraction& fraction ){
        return Fraction(0);
    }
    Fraction operator--(const Fraction& fraction ){
        return Fraction(0);
    }
    Fraction operator++(const Fraction& fraction ,int){
        return Fraction(0);
    }
    Fraction operator--(const Fraction& fraction, int){
        return Fraction(0);
    }
    ostream& operator<<(ostream& os, const Fraction& fraction ){
        return os<<"default default";
    }
    istream & operator >> (istream &in,  Fraction &fraction){
        in>>fraction.denominator;
        in>>fraction.numerator;
        return in;
    }
    
    
} // namespace 
