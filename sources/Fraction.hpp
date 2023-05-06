#pragma once
#include <iostream>
#include "Fraction.hpp"
using namespace std;

namespace ariel
{
    class Fraction
    {
        int Numerator;
        int Denominator;

    public:
        //constructors
        Fraction(int num1, int num2);
        Fraction(float num);
        Fraction();
        //-----------------------------
        //setters and getters
        int getNumerator();
        int getDenominator();
        void Set_Numerator(int num);
        void Set_Denominator(int num);
        //-----------------------------
        void Reduce_fraction();//reduce the franction

        Fraction operator+(const Fraction &num)const;
        Fraction operator+(float num)const;
        friend Fraction operator+(float num1, const Fraction &num2);

        Fraction operator-(const Fraction &num)const;
        Fraction operator-(float num)const;
        friend Fraction operator-(float num1, const Fraction &num2);
        
        Fraction operator*(const Fraction &num)const;
        Fraction operator*(float num)const;
        friend Fraction operator*(float num1, const Fraction &num2);
        
        Fraction operator/(const Fraction &num)const;
        Fraction operator/(float num)const;
        friend Fraction operator/(float num1, const Fraction &num2);
        
        bool operator==(const Fraction &num)const; 
        bool operator==(float num)const;
        friend bool operator==(float num1, const Fraction &num2);
        
        bool operator>(const Fraction &num)const;
        bool operator>(float num)const;
        friend bool operator>(float num1, const Fraction &num2);
        
        bool operator<(const Fraction &num)const;
        bool operator<(float num)const;
        friend bool operator<(float num1, const Fraction &num2);
        
        bool operator>=(const Fraction &num)const;
        bool operator>=(float num)const;
        friend bool operator>=(float num1, const Fraction &num2);
        
        bool operator<=(const Fraction &num)const;
        bool operator<=(float num)const;
        friend bool operator<=(float num1, const Fraction &num2);
        
        const Fraction operator++(int flag); //num++
        Fraction& operator++();//++num

        const Fraction operator--(int flag);//num--
        Fraction& operator--();//--num

        friend istream& operator>> (istream& input, Fraction& num);
        friend ostream& operator<< (ostream& output, const Fraction& num);

    };
};
