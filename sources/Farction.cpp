// #pragma once

#include "Fraction.hpp"

using namespace std;
using namespace ariel;

namespace ariel{

    Fraction::Fraction(int num, int denom)
    {
        if(denom == 0) throw runtime_error("divide by zero is illegal\n");

        else
        {
           numerator = num;
           denominator = denom; 
        }
        int gc = gcd(numerator, denominator);
        numerator /= gc;
        denominator /= gc;
    }

    //private - support functions:

    int Fraction::gcd(int a, int b) const{

    a = abs(a);
    b = abs(b);
    if(b==0) return a;

    return gcd(b, a%b);

    }

    int Fraction::digits_after_point(float a) const{ 
    
    string s = to_string(a);
    bool zeros = true;
    int dig_num = 0;

    for (size_t i = s.length()-1; i > 0; i--)
    {
        if (s[i] == '.') break;
        else if (s[i] != '0') zeros = false;
        if(!zeros)dig_num++;
    }
    return dig_num;
    }

    Fraction Fraction::convert(float a) const{    

    int decimal = digits_after_point(a); 
    if (decimal > 3) a = floor(a*1000)/1000;

    float new_numerator = a * pow(10, decimal);
    int new_denominator = pow(10, decimal);

    return Fraction(int(new_numerator), new_denominator);

    }

    //Operators - Operator + ///

    Fraction Fraction::operator+(const Fraction& other) const{

    int lcm = (this->denominator * other.denominator)/ gcd(this-> denominator, other.denominator);  
    int new_numerator = this->numerator *(lcm/this->denominator) + other.numerator*(lcm/other.denominator);
    return Fraction(new_numerator, lcm);

    }

    Fraction Fraction::operator+(float f) const{

        Fraction add = convert(f);
        Fraction result = *this + add;
        return result;
    }

    Fraction operator+(float f, const Fraction& other){

        return other.convert(f) + other;
    }

    //Operators - Operator - ///

    Fraction Fraction::operator-(const Fraction& other) const{

    int lcm = (this->denominator * other.denominator)/ gcd(this-> denominator, other.denominator);  
    int new_numerator = this->numerator *(lcm/this->denominator) - other.numerator*(lcm/other.denominator);
    return Fraction(new_numerator, lcm);

    }

    Fraction Fraction::operator-(float f) const{

        Fraction sub = convert(f);
        Fraction result = *this - sub;
        return result;
    }

    Fraction operator-(float f, const Fraction& other){

        return other.convert(f) - other;
    }

    //Operators - Operator * ///
    Fraction Fraction::operator*(const Fraction& other) const{

       return Fraction(this->numerator*other.numerator, this->denominator*other.denominator);

    }

    Fraction Fraction::operator*(float f) const{

        Fraction mul = convert(f);
        Fraction result = *this * mul;
        return result;
    }

    Fraction operator*(float f, const Fraction& other){

        return other.convert(f) * other;
    }

    //Operators - Operator / ///

    Fraction Fraction::operator/(const Fraction& other) const{

       if(other.numerator == 0) throw runtime_error("divide by zero is illegal\n");
       Fraction div(other.denominator, other.numerator);

       return *this * div;

    }

     Fraction Fraction::operator/(float f) const{

        Fraction div = convert(f);
        Fraction result = *this / div;
        return result;
    }

    Fraction operator/(float f, const Fraction& other){

        return other.convert(f) / other;
    }

    // Operators ++ && -- //////

    Fraction Fraction::operator++(int){

        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& Fraction::operator++(){

        numerator += denominator;
        return *this;
    }

     Fraction Fraction::operator--(int){
        Fraction temp = *this;
        --(*this);
        return temp;
    }

     Fraction& Fraction::operator--(){

        numerator -= denominator;
        return *this;
    }

    ///IO Operators ////

    ostream& operator<<(ostream& os, const Fraction& frac) {

    os << frac.numerator << "/" << frac.denominator;
    return os;

    }

    istream& operator>>(istream& is, Fraction& frac) {
    
    is >> frac.numerator >> frac.denominator;
    if (frac.denominator == 0) {
        throw runtime_error("divide by zero is illegal\n");
    }

    int gc = frac.gcd(frac.numerator, frac.denominator);
    frac.numerator /= gc;
    frac.denominator /= gc;
    return is;

    }

    //// Comparison Operators ////////

      /////Operator == /////

    bool Fraction::operator == (const Fraction& other) const{

        int gc = gcd(other.numerator, other.denominator);

        return this->numerator == (other.numerator/gc) && this->denominator ==(other.denominator/gc);
    }
    
    bool Fraction::operator == (float f) const{

        return *this == this->convert(f);

    }

    bool operator == (float f, const Fraction& other){

        return other.convert(f) == other ;

    } 

    //// Operator > //////

    bool Fraction::operator > (const Fraction& other) const{

        int lcm = (this->denominator * other.denominator)/gcd(this->denominator, other.denominator);
        int num_this = this->numerator *(lcm/this->denominator);
        int num_other = other.numerator *(lcm/other.denominator);

        return num_this > num_other ; 
    }
    
    bool Fraction::operator > (float f) const{

        return *this > this->convert(f);

    }

    bool operator > (float f, const Fraction& other){

        return other.convert(f) > other;

    }

    ///// Operator < ////////

    bool Fraction::operator < (const Fraction& other) const{

        int lcm = (this->denominator * other.denominator)/gcd(this->denominator, other.denominator);
        int num_this = this->numerator *(lcm/this->denominator);
        int num_other = other.numerator *(lcm/other.denominator);

        return num_this < num_other ; 

    }
    
    bool Fraction::operator < (float f) const{

        return *this < this->convert(f);
    }

    bool operator < (float f, const Fraction& other){

        return other.convert(f) < other;
    }

    ///// Operator >= ////

    bool Fraction::operator >= (const Fraction& other) const{

        return *this > other || *this == other ;
    }
    
    bool Fraction::operator >= (float f) const{

        return *this >= this->convert(f);

    }

    bool operator >= (float f, const Fraction& other){

        return other.convert(f) >= other ;

    }

     ///// Operator <= ////

    bool Fraction::operator <= (const Fraction& other) const{

        return *this < other || *this == other ;
    }
    
    bool Fraction::operator <= (float f) const{

        return *this <= this->convert(f);

    }

    bool operator <= (float f, const Fraction& other){

        return other.convert(f) <= other ;

    }

     ///// Operator != ////

    bool Fraction::operator != (const Fraction& other) const{

        return !(*this == other);
    }
    
    bool Fraction::operator != (float f) const{

        return *this != this->convert(f);

    }

    bool operator != (float f, const Fraction& other){

        return other.convert(f) != other ;

    }    

    int Fraction::get_numerator(){
        return this->numerator;
    }

    int Fraction::get_denominator(){
        return this->denominator;
    }
}