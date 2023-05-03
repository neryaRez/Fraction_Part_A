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

    CHECK_NOTHROW(Fraction(0,8));
    CHECK_NOTHROW(Fraction(-1,2));
    CHECK_NOTHROW(Fraction(2,-1));
    CHECK_NOTHROW(Fraction(-1,-2));

    Fraction a(-4,-10);
    Fraction b(5,10);
    Fraction c(1,-1);

    CHECK((a.get_numerator() == 2  && a.get_denominator() == 5));
    CHECK((b.get_numerator() == 1  && b.get_denominator() == 2));
    CHECK((c.get_numerator() == -1 && c.get_denominator() ==1));

    CHECK_EQ(Fraction(-3,4), Fraction(3,-4));
    CHECK_EQ(Fraction(9,12), Fraction(6,8));

}

TEST_SUITE("Aritmetic Operators"){

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
        CHECK_EQ( a + c, c + a);


    }

    TEST_CASE("Fraction - Operator"){

        Fraction a(1,3);
        Fraction b(1,-3);
        Fraction c(8,72);
        Fraction d(4,-36);
        Fraction e = c - d - 0.5;
        Fraction f = -0.75 - e;
        Fraction h = c-d;


        CHECK_EQ( a -b , Fraction(2,3));
        CHECK_EQ(   e,   Fraction(-5, 18));
        CHECK_EQ(   f,   Fraction(-17,36));
        CHECK_EQ(   h ,  Fraction(2,9));
    }

    TEST_CASE("Fraction * Operator"){

        Fraction a(1,3);
        Fraction b = 0.25 * a ;
        Fraction c = -0.5 * a * b * 0.8;
        Fraction g = a * 0;

        CHECK_EQ(b, Fraction(1,12));
        CHECK_EQ(c, Fraction(-1,90));
        CHECK_EQ(g, Fraction(0,9));
        CHECK_EQ(Fraction(1,1), a * 3);
        CHECK_EQ( a * b, b * a);


    }

    TEST_CASE("Fraction / Operator"){

        Fraction a1(1,3);
        Fraction a2(0,1);
        Fraction a3(6,7);
        Fraction a4(2,4);

        CHECK_THROWS( a1 / a2 );
        CHECK_EQ( a1 / a4 , Fraction(2,3));
        CHECK_EQ( 1 / a4 , Fraction(2,1));
        CHECK_EQ( a3 / 0.25 , Fraction(48,14));

    } 

}

TEST_SUITE("Comparison Operators"){

    TEST_CASE("Fraction > comparison operator"){

        Fraction a(2,3), a1(3,4), a2(4,5);

        CHECK(a1 > a);
        CHECK(a2 > a1);
        CHECK_FALSE(a > a1);
        CHECK_FALSE(a1 > a2);

        Fraction b(-2,3), b1(1,3), b2(-4,3);

        CHECK(b1 > b);
        CHECK(b1 > b2);
        CHECK(b > b2);
        CHECK_FALSE(b2 > b1);
        CHECK_FALSE( b >  b1);
        CHECK_FALSE(b2 > b);

        CHECK( 2.54 > a1);
        CHECK( a1 > 0.05678);

        }

        TEST_CASE("Fraction < comparison operator"){

            Fraction a(5,6), a1(6,7), a2(7,8);

            CHECK(a < a1);
            CHECK(a1 < a2);
            CHECK_FALSE(a1 < a);
            CHECK_FALSE(a2 < a1);

            Fraction b(-2,4), b1(1,4), b2(-4,4);

            CHECK(b < b1);
            CHECK(b2 < b1);
            CHECK(b2 < b);
            CHECK_FALSE(b1 < b2);
            CHECK_FALSE( b1 <  b2);
            CHECK_FALSE(b < b2);

            CHECK(b1 < 0.34);
            CHECK(0.15126 < b1);

        }

        TEST_CASE("Fraction <= comparison operator"){

            Fraction a(5,6), a1(5,6), a2(7,8);

            CHECK(a <= a1);
            CHECK(a <= a2);
            CHECK_FALSE(a2 <= a1);

            Fraction b(-2,4), b1(1,5), b2(-3,4), b3(3,-4);

            CHECK(b <= b1);
            CHECK(b2 <= b1);
            CHECK(b2 <= b);
            CHECK(b2 <= b3);
            CHECK_FALSE(b1 <= b2);
            CHECK_FALSE( b1 <=  b3);
            CHECK_FALSE(b <= b2);

            CHECK(b1 <= 0.25);
            CHECK(b3 <= -0.75);
            CHECK(-0.6 <= b);

        }    

        TEST_CASE("Fraction >= comparison operator"){

            Fraction a(5,6), a1(5,6), a2(7,8);

            CHECK(a1 >= a);
            CHECK(a2 >= a1);
            CHECK_FALSE(a1 >= a2);

            Fraction b(-2,4), b1(1,5), b2(-3,4), b3(3,-4);

            CHECK(b1 >= b);
            CHECK(b1 >= b2);
            CHECK(b >= b2);
            CHECK(b3 >= b2);
            CHECK_FALSE(b2 >= b1);
            CHECK_FALSE( b3 >=  b1);
            CHECK_FALSE(b2 >= b);

            CHECK(b1 >= 0.2);
            CHECK(b3 >= -0.75);
            CHECK(-0.005 >= b3);

        }

        TEST_CASE("Fraction == comparison operator"){

            Fraction a(2,3), a1(4,6), a2(6,9);

            CHECK(a == a1);
            CHECK(a1 == a2);

            Fraction b(1,8), b1(2,16);

            CHECK(0.125 == b);
            CHECK(b1 == 0.125);

            CHECK( b + b1 == 0.25);

            float f = 0.1005;
            Fraction g(1,80);

            float f1 = 1.3756, f2 = 0.0201, f3 = 2.1256;
            Fraction m1(11,8), m2(1,50), m3(17,8);

            CHECK(b * f == g);
            CHECK(f1 == m1);
            CHECK(f2 == m2);
            CHECK(m3 == f3);

        }

}

TEST_SUITE(" ++ and -- Operators "){

    TEST_CASE("Post-Fix"){

        Fraction c(3,4);

        CHECK( c++ == 0.75);

        CHECK( c == 1.75);

        CHECK( c-- == 1.75);

        CHECK( c == 0.75);

    }

    TEST_CASE("pre fix"){

        Fraction c(5,4);

        CHECK ( --c == 0.25);

        CHECK ( ++c == 1.25);
        
    }

}

TEST_SUITE("IO Operators"){

    TEST_CASE("Fraction << Operator"){

        Fraction a(16,64);
        ostringstream os;
        CHECK_NOTHROW(os << a);
        CHECK_EQ(os.str(), "1/4");
        
    }

    TEST_CASE("Fraction >> Operator"){

        istringstream in("4 8");
        Fraction a2(4,8);
        CHECK_NOTHROW(in >> a2);
        CHECK( a2 == 0.5);

    }

}







