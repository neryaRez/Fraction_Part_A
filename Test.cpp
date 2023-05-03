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

    Fraction a(-4,-10);
    Fraction b(5,10);
    Fraction c(1,-1);

    CHECK((a.get_numerator() == 2  && a.get_denominator() == 5));
    CHECK((b.get_numerator() == 1  && b.get_denominator() == 2));
    CHECK((c.get_numerator() == -1  && c.get_denominator() ==1));

}

TEST_CASE("Fraction + Operator"){

    Fraction a(1,4);
    Fraction b(9,36);

    Fraction c = a + b;
    Fraction d = c + 0.25;
    Fraction e = -0.25 + d;
    Fraction g = -0.5 + c ;
    Fraction k(-16,64), k2(49,7), k3(7,-49);
    Fraction h = -3.25 + e + k + k2 + k3;  

    CHECK_EQ(c, Fraction(1,2));
    CHECK_EQ(d, Fraction(3,4));
    CHECK_EQ(e, Fraction(1,2));
    CHECK_EQ(g, Fraction(0,8));
    CHECK_EQ(h, Fraction(27,7));


}