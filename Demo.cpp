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
#include <limits>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;

int main()
{

    cout << "===========================" << endl;
    cout << "      orginal demo:" << endl;
    cout << "===========================" << endl;
    Fraction a(-5, 3), b(14, 21);
    cout << "a:" << a << " b:" << b << endl;
    cout << "a+b: " << a + b << endl;
    cout << "a-b: " << a - b << endl;
    cout << "a/b: " << a / b << endl;
    cout << "a*b: " << a * b << endl;
    cout << "2.3*b: " << 2.3 * b << endl;
    cout << "a+2.421: " << a + 2.421 << endl;
    Fraction c = a + b - 1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1)
        cout << " a is bigger than 1.1" << endl;
    else
        cout << " a is smaller than 1.1" << endl;

    cout << "===========================" << endl;
    cout << "         my demo:" << endl;
    cout << "===========================" << endl;

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    // 3 constructors
    cout << "construcrots:" << endl;
    // int int
    Fraction d(-5, -3);
    cout << "(int,int) fraction: " << d << endl;
    float num2 = 0.8857;
    // float constructor
    Fraction e(num2);
    cout << "(float) fraction: " << e << endl; // will be only 3 after the point

    // float constructor
    Fraction f(num2);
    cout << "(float) fraction: " << f << endl; // will be only 3 after the point
    cout << "e == f ? " << (e == f) << endl
         << endl; // should return true (1)

    // get function
    cout << "checking get function (should print 177/200): " << endl;
    cout << f.getNumerator() << "/" << f.getDenominator() << endl
         << endl;

    // set function
    cout << "checking set function: " << endl;
    cout << "before set: " << e << endl;
    cout << "setting numerator to 37 and denominator to 578 " << endl;
    e.Set_Numerator(37);
    e.Set_Denominator(578);
    cout << "after set: " << e << endl
         << endl;

    // operators
    cout << "operators: \n"
         << endl;

    //+
    cout << "+ operation: " << endl;
    Fraction g1 = d + f;
    cout << "5/3 + 177/200: " << g1 << endl;
    cout << "0.8857 + 5/3: " << (0.8857 + d) << endl; // result should be the same as d+f
    cout << "5/3 + 0.8857: " << (d + 0.8857) << endl; // result should be the same as d+f
    cout << "1531/600  + 100: should be 61531/600" << endl;
    cout << (g1 + 100) << endl
         << endl;

    //-
    cout << "- operation: " << endl;
    Fraction g2 = d - f;
    cout << "5/3 - 177/200: " << g2 << endl;
    cout << "0.8857 - 5/3: " << (0.8857 - d) << endl; // result should be  -(d-f)
    cout << "5/3 - 0.8857: " << (d - 0.8857) << endl; // result should be the same as d-f
    cout << "469/600 - 55: should be -32531/600" << endl;
    cout << (g2 - 55) << endl
         << endl;

    //*
    cout << "* operation: " << endl;
    Fraction g3 = d * f;
    cout << "5/3 * 177/200: " << g3 << endl;
    cout << "0.8857 * 5/3: " << (0.8857 * d) << endl; // result should be the same as d*f
    cout << "5/3 * 0.8857: " << (d * 0.8857) << endl; // result should be the same as d*f
    cout << "59/40 * (-2): should be -59/20" << endl;
    cout << (g3 * (-2)) << endl
         << endl;

    // /
    cout << "/ operation: " << endl;
    Fraction g4 = d / f;
    cout << "5/3 / 177/200: " << g4 << endl;
    cout << "5/3 / 0.8857: " << (d / 0.8857 )<< endl;                 // result should be the same as d/f
    cout << "0.8857 / 5/3: " << (0.8857 / d) << endl; // result should be the same as f/d
    cout << "1000/531 / (-2): should be -500/531" << endl;
    cout << (g4 / (-2)) << endl << endl;
        

    // ==
    cout << "== operation: " << endl;
    Fraction g5 = 2 / 0.5;
    Fraction g6(4, 1);
    cout << g5 << " == " << g6 << " ? " << (g5 == g6) << endl;
    cout << "4 == " << g5 << " ? " << (4 == g5) << endl;
    cout << g5 << " == 4 ? " << (g5 == 4) << endl
         << endl; // sould be like line before

    // >
    cout << "> operation: " << endl;
    Fraction g7(3, 1);
    cout << g5 << " > " << g6 << " ? " << (g5 > g6) << endl;
    cout << g5 << " > " << g7 << " ? " << (g5 > g7) << endl;
    cout << "3.99999 > " << g5 << " ? " << (3.99999 > g5) << endl;
    cout << g5 << " > 3.99999 ? " << (g5 > 3.99999) << endl
         << endl;

    // <
    cout << "< operation: " << endl;
    Fraction g8(5, 1);
    cout << g5 << " < " << g6 << " ? " << (g5 < g6) << endl;
    cout << g5 << " < " << g8 << " ? " << (g5 < g8) << endl;
    cout << "4.01 < " << g5 << " ? " << (4.01 < g5) << endl;
    cout << g5 << " < 4.01 ? " << (g5 < 4.01) << endl
         << endl;

    // >=
    cout << ">= operation: " << endl;
    Fraction g9(3, 1);
    cout << g5 << " >= " << g6 << " ? " << (g5 >= g6) << endl;
    cout << g5 << " >= " << g7 << " ? " << (g5 >= g9) << endl;
    cout << g5 << " >= 7.9 ? " << (g5 >= 7.9) << endl;
    cout << "3.99999 >= " << g5 << " ? " << (3.99999 >= g5) << endl;
    cout << g5 << " >= 3.99999 ? " << (g5 >= 3.99999) << endl
         << endl;

    // <=
    cout << "<= operation: " << endl;
    Fraction g10(5, 1);
    cout << g5 << " <= " << g6 << " ? " << (g5 <= g6) << endl;
    cout << g5 << " <= " << g8 << " ? " << (g5 <= g10) << endl;
    cout << g5 << " <= 2.01 ? " << (g5 <= 2.01) << endl;
    cout << "4.01 <= " << g5 << " ? " << (4.01 <= g5) << endl;
    cout << g5 << " <= 4.01 ? " << (g5 <= 4.01) << endl
         << endl;

    // a++:
    Fraction a1(2, 5);
    Fraction b1(2, 5);
    cout << "a++ operation: " << endl;
    cout << "a before increment: " << a1 << endl;
    cout << b1 << " + (" << a1 << " ++) = ? " << (b1 + (a1++)) << endl;
    cout << "4.00003 + (" << a1 << " ++) - " << g5 << "= ? " << (4.00003 + (a1++) - g5) << endl;
    cout << "after we increase a by 2, it should be 12/5: " << a1 << endl
         << endl;

    // ++a:
    Fraction a2(2, 5);
    Fraction b2(2, 5);
    cout << "++a operation: " << endl;
    cout << "a before increment: " << a2 << endl;
    cout << b2 << " + (++ " << a2 << ") = ? " << (b2 + (++a2)) << endl;
    cout << "4.00003 + (++ " << a2 << ") - " << g5 << "= ? " << (4.00003 + (++a2) - g5) << endl;
    cout << "after we increase a by 2, it should be 12/5: " << a2 << endl
         << endl;

    // a--:
    Fraction a3(2, 5);
    Fraction b3(2, 5);
    cout << "a-- operation: " << endl;
    cout << "a before decrement: " << a3 << endl;
    cout << b3 << " + (" << a3 << " --) = ? " << (b3 + (a3--)) << endl;
    cout << "4.00003 + (" << a3 << " --) - " << g5 << "= ? " << (4.00003 + (a3--) - g5) << endl;
    cout << "after we decrement a by 2, it should be -8/5: " << a3 << endl
         << endl;

    // --a:
    Fraction a4(2, 5);
    Fraction b4(2, 5);
    cout << "--a operation: " << endl;
    cout << "a before decrement: " << a4 << endl;
    cout << b4 << " + (-- " << a4 << ") = ? " << (b4 + (--a4)) << endl;
    cout << "4.00003 + (-- " << a4 << ") - " << g5 << "= ? " << (4.00003 + (--a4) - g5) << endl;
    cout << "after we decrement a by 2, it should be -8/5: " << a4 << endl
         << endl;
}
