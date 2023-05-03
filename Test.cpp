#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
#include <iostream>
// #include <algorithm> 
#include <typeinfo> 
#include <sstream>
using namespace ariel;
using namespace std;

TEST_CASE("Fraction Constructors & Getters"){
    
    CHECK_THROWS(Fraction(1,0));

    CHECK_NOTHROW(Fraction(4,8));
    CHECK_NOTHROW(Fraction(-1,2));
    CHECK_NOTHROW(Fraction(2,-1));
    CHECK_NOTHROW(Fraction(-1,-2));

    Fraction a(4,5);
    Fraction b(5,10);

    CHECK((a.get_numerator() == 4 && a.get_denominator() == 5));
    CHECK((b.get_numerator() == 1 && b.get_denominator() == 2));

}

TEST_CASE("Fraction + Operator"){

    Fraction a(1,4);
    Fraction b(9,36);

    Fraction c = a + b;

    CHECK_EQ(c, Fraction(1,2));

    Fraction d = c + 0.25;

    CHECK_EQ(d, Fraction(3,4));

    Fraction e = -0.25 + d;

    CHECK_EQ(e, Fraction(1,2));

}