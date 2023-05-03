/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5,3), b(14,21);

    Fraction v(-1,-2);

    cout<<v<<endl;

    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a+b << endl; 
    cout << "a-b" << a-b << endl; 
    cout << "a/b" << a/b << endl; 
    cout << "a*b" << a*b << endl; 
    cout << "2.3*b" << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 
    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;

    Fraction g(1,-1);
    Fraction g2(2,-4);
    Fraction g3(4,-4);

    cout <<"g.num== "<<g.get_numerator()<<endl;
    cout <<"g.den== "<<g.get_denominator()<<endl;
    cout <<"g2.num== "<<g2.get_numerator()<<endl;
    cout <<"g2.den== "<<g2.get_denominator()<<endl;
    cout <<"g3.num== "<<g3.get_numerator()<<endl;
    cout <<"g3.den== "<<g3.get_denominator()<<endl;


}
