// #pragma once

#include "Fraction.hpp"

using namespace std;
using namespace ariel;

namespace ariel{

    Fraction::Fraction(int num, int denom)
    // numerator(num), denominator(denom)
    {
        numerator = num;
        denominator = denom;
        int gc = gcd(numerator, denominator);
        numerator /= gc;
        denominator /= gc;
    }

    //private - support functions:

    int Fraction::gcd(int a, int b) const{

    if(b==0) return a;

    return gcd(b, a%b);

    }

    int Fraction::digits_after_points(float a) const{ 
    
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

    int decimal = digits_after_points(a); 
    if (decimal > 3) a = floor(a*1000)/1000;

    float new_numerator = a * pow(10, decimal);
    int new_denominator = pow(10, decimal);

    return Fraction(int(new_numerator), new_denominator);
    }


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

    

    int Fraction::get_numerator(){
        return this->numerator;
    }

    int Fraction::get_denominator(){
        return this->denominator;
    }

        // Fraction operator-(const Fraction& other) const;

        // friend Fraction operator+(float f, const Fraction& other);

}