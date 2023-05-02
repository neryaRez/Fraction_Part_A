#pragma once

#include <iostream>
#include <cstdbool>
#include <cmath>
#include <string>

using namespace std;
// using namespace ariel;

namespace ariel{

    class Fraction
    {
    private:
        int numerator;
        int denominator;

        int gcd(int a, int b) const;
        int digits_after_points(float a) const;
    
    public:

        Fraction(int num, int denom);

        Fraction operator+(const Fraction& other) const;

        Fraction operator+(float f) const;

        // Fraction operator-(const Fraction& other) const;

        // friend Fraction operator+(float f, const Fraction& other);

        int get_numerator();

        int get_denominator();

        Fraction convert(float a) const;
    };
    

}