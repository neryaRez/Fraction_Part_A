#pragma once

#include <iostream>
#include <cstdbool>
#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;
// using namespace ariel;

namespace ariel{

    class Fraction
    {
    private:
        int numerator;
        int denominator;

        int gcd(int a, int b) const;
        int digits_after_point(float a) const;
        Fraction convert(float a) const;
    
    public:

        Fraction(int num, int denom);

        // Operator +///

        Fraction operator+(const Fraction& other) const;

        Fraction operator+(float f) const;
       
        friend Fraction operator+(float f, const Fraction& other);

        ///Operator -///
        
        Fraction operator-(const Fraction& other) const;

        Fraction operator-(float f) const;

        friend Fraction operator-(float f, const Fraction& other);

        ///Operator *    ///

        Fraction operator*(const Fraction& other) const;

        Fraction operator*(float f) const;

        friend Fraction operator*(float f, const Fraction& other);

        ///Operator /    ///

        Fraction operator/(const Fraction& other) const;

        Fraction operator/(float f) const;

        friend Fraction operator/(float f, const Fraction& other);

        /// Operators ++ && --///

        Fraction operator++ (int);

        Fraction& operator++();

        Fraction operator-- (int);

        Fraction& operator--();   

        /// IO Operators //////

        friend ostream& operator<<(ostream& os, const Fraction& frac); 

        friend istream& operator>>(istream& is, Fraction& frac);

        /// Comparison Operators ////

        /////Operator == /////

        bool operator == (const Fraction& other) const;
    
        bool operator == (float f) const;

        friend bool operator == (float f, const Fraction& other);        

        //// Operator > //////

        bool operator > (const Fraction& other) const;
    
        bool operator > (float f) const;

        friend bool operator > (float f, const Fraction& other);

        ///// Operator < ////////

        bool operator < (const Fraction& other) const;
    
        bool operator < (float f) const;

        friend bool operator < (float f, const Fraction& other); 

        ///// Operator >= ////

        bool operator >= (const Fraction& other) const;
    
        bool operator >= (float f) const;

        friend bool operator >= (float f, const Fraction& other); 

        ///// Operator <= ///////////

        bool operator <= (const Fraction& other) const;
    
        bool operator <= (float f) const;

        friend bool operator <= (float f, const Fraction& other); 

        int get_numerator();

        int get_denominator();

        
    };
    

}