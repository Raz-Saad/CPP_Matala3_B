#include "Fraction.hpp"
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <vector>
namespace ariel
{
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    Fraction::Fraction(int num1, int num2)
    {

        if (num1 > max_int || num2 > max_int || num1 < min_int || num2 < min_int)
            throw std::overflow_error("Input is greather than max_int or lower than min_int");

        if (num2 == 0)
            throw std::invalid_argument("Denominator can not be zero");

        if (num2 < 0)
        { // making sure the minus is in the Numerator
            num1 *= -1;
            num2 *= -1;
        }
        Numerator = num1;
        Denominator = num2;
        Reduce_fraction();
    }

    Fraction::Fraction(float num) : Numerator(num * 1000), Denominator(1000)
    {
        if (num > max_int || num < min_int)
            throw std::overflow_error("Input is greather than max_int or lower than min_int");

        Reduce_fraction();
    }

    Fraction::Fraction()
    {
        this->Numerator = 0;
        this->Denominator = 1;
    }

    int Fraction::getNumerator()
    {
        return Numerator;
    }
    int Fraction::getDenominator()
    {
        return Denominator;
    }
    void Fraction::Set_Numerator(int num)
    {
        Numerator = num;
        Reduce_fraction();
    }

    void Fraction::Set_Denominator(int num)
    {
        if (num == 0)
            throw std::runtime_error("Denominator can not be zero");
        else
            Denominator = num;
        Reduce_fraction();
    }
    void Fraction::Reduce_fraction()
    {
        int gcd = abs(__gcd(Numerator, Denominator));
        Numerator = Numerator / gcd;
        Denominator = Denominator / gcd;
    }

    Fraction Fraction::operator+(const Fraction &num) const
    {
        long int temp_this_numerator = this->Numerator * num.Denominator;
        long int temp_other_numerator = num.Numerator * this->Denominator;
        long int added_numerators = (temp_this_numerator + temp_other_numerator);
        long int temp_both_denominator = num.Denominator * this->Denominator;
        long int gcd = abs(__gcd(added_numerators, temp_both_denominator));

        // making sure that the numerator isnt greather than maxint or lower than minint after reduction
        if ((added_numerators / gcd > max_int) || (added_numerators / gcd < min_int))
            throw std::overflow_error("Numerator is greather than max_int or lower than min_int");

        // making sure that the denominator isnt greather than maxint or lower than minint after reduction
        if ((temp_both_denominator / gcd > max_int) || (temp_both_denominator / gcd < min_int))
            throw std::overflow_error("Denominator is greather than max_int or lower than min_int");

        int new_numerator = added_numerators / gcd;
        int new_denominator = temp_both_denominator / gcd;
        Fraction ans(new_numerator, new_denominator);
        return ans;
    }

    Fraction Fraction::operator+(float num) const
    {
        Fraction ans(num);
        return operator+(ans);
    }
    
    Fraction operator+(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator+(num2);
    }

    Fraction Fraction::operator-(const Fraction &num) const
    {
        long int temp_this_numerator = this->Numerator * num.Denominator;
        long int temp_other_numerator = num.Numerator * this->Denominator;
        long int added_numerators = (temp_this_numerator - temp_other_numerator);
        long int temp_both_denominator = num.Denominator * this->Denominator;
        long int gcd = abs(__gcd(added_numerators, temp_both_denominator));

        // making sure that the numerator isnt greather than maxint or lower than minint after reduction
        if ((added_numerators / gcd > max_int) || (added_numerators / gcd < min_int))
            throw std::overflow_error("Numerator is greather than max_int or lower than min_int");

        // making sure that the denominator isnt greather than maxint or lower than minint after reduction
        if ((temp_both_denominator / gcd > max_int) || (temp_both_denominator / gcd < min_int))
            throw std::overflow_error("Denominator is greather than max_int or lower than min_int");

        int new_numerator = added_numerators / gcd;
        int new_denominator = temp_both_denominator / gcd;
        Fraction ans(new_numerator, new_denominator);
        return ans;
    }

    Fraction Fraction::operator-(float num) const
    {
        Fraction ans(num);
        return operator-(ans);
    }

    Fraction operator-(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator-(num2);
    }

    Fraction Fraction::operator*(const Fraction &num) const
    {
        long int a = this->Numerator;
        long int b = num.Numerator;
        long int c = this->Denominator;
        long int d = num.Denominator;
        long int temp_numerator = a * b;
        long int temp_denominator = c * d;

        if (temp_numerator > max_int || temp_numerator < min_int)
            throw std::overflow_error("Numerator is greather than max_int or lower than min_int");

        if (temp_denominator > max_int || temp_denominator < min_int)
            throw std::overflow_error("Denominator is greather than max_int or lower than min_int");

        int new_numerator = temp_numerator;
        int new_denominator = temp_denominator;
        Fraction ans(new_numerator, new_denominator);
        return ans;
    }

    Fraction Fraction::operator*(float num) const
    {
        Fraction ans(num);
        return operator*(ans);
    }

    Fraction operator*(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator*(num2);
    }

    Fraction Fraction::operator/(const Fraction &num) const
    {
        if (num.Denominator == 0 || num.Numerator == 0)
        {
            throw std::runtime_error("can not divide by zero");
        }

        long int a = this->Numerator;
        long int b = num.Numerator;
        long int c = this->Denominator;
        long int d = num.Denominator;
        long int temp_numerator = a * d;
        long int temp_denominator = c * b;

        if (temp_numerator > max_int || temp_numerator < min_int)
            throw std::overflow_error("Numerator is greather than max_int or lower than min_int");

        if (temp_denominator > max_int || temp_denominator < min_int)
            throw std::overflow_error("Denominator is greather than max_int or lower than min_int");

        int new_numerator = temp_numerator;
        int new_denominator = temp_denominator;
        Fraction ans(new_numerator, new_denominator);
        return ans;
    }

    Fraction Fraction::operator/(float num) const
    {
        Fraction ans(num);
        return operator/(ans);
    }

    Fraction operator/(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator/(num2);
    }

    bool Fraction::operator==(const Fraction &num) const
    {
        int first = this->Numerator * num.Denominator;
        int second = num.Numerator * this->Denominator;
        if (first == second)
            return true;
        else
            return false;
    }

    bool Fraction::operator==(float num) const
    {
        Fraction ans(num);
        return operator==(ans);
    }

    bool operator==(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator==(num2);
    }

    bool Fraction::operator>(const Fraction &num) const
    {
        int first = this->Numerator * num.Denominator;
        int second = num.Numerator * this->Denominator;
        if (first > second)
            return true;
        else
            return false;
    }

    bool Fraction::operator>(float num) const
    {
        Fraction ans(num);
        return operator>(ans);
    }

    bool operator>(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator>(num2);
    }

    bool Fraction::operator<(const Fraction &num) const
    {
        int first = this->Numerator * num.Denominator;
        int second = num.Numerator * this->Denominator;
        if (!(first > second) && !(first==second))
            return true;
        else
            return false;
    }

    bool Fraction::operator<(float num) const
    {
        Fraction ans(num);
        return operator<(ans);
    }

    bool operator<(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator<(num2);
    }

    bool Fraction::operator>=(const Fraction &num) const
    {
        int first = this->Numerator * num.Denominator;
        int second = num.Numerator * this->Denominator;
        if (first > second || first == second)
            return true;
        else
            return false;
    }

    bool Fraction::operator>=(float num) const
    {
        Fraction ans(num);
        return operator>=(ans);
    }

    bool operator>=(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator>=(num2);
    }

    bool Fraction::operator<=(const Fraction &num) const
    {
        int first = this->Numerator * num.Denominator;
        int second = num.Numerator * this->Denominator;
        if (first < second || first == second)
            return true;
        else
            return false;
    }

    bool Fraction::operator<=(float num) const
    {
        Fraction ans(num);
        return operator<=(ans);
    }

    bool operator<=(float num1, const Fraction &num2)
    {
        Fraction ans(num1);
        return ans.operator<=(num2);
    }

    const Fraction Fraction::operator++(int flag) // num++
    {
        Fraction cpy(this->Numerator, this->Denominator);      // creating a copy of the fraction
        this->Numerator = this->Numerator + this->Denominator; // adding +1 to the current fraction
        Reduce_fraction();
        return cpy; // returning the "old" franction before adding 1 to it
    }

    Fraction &Fraction::operator++() //++num
    {
        this->Numerator = this->Numerator + this->Denominator;
        Reduce_fraction();
        return *this;
    }

    const Fraction Fraction::operator--(int flag) // num--
    {
        Fraction cpy(this->Numerator, this->Denominator);      // creating a copy of the fraction
        this->Numerator = this->Numerator - this->Denominator; // subtracting  1 from the current fraction
        Reduce_fraction();
        return cpy; // returning the "old" franction before subtracting 1 from it
    }

    Fraction &Fraction::operator--() //--num
    {
        this->Numerator = this->Numerator - this->Denominator;
        Reduce_fraction();
        return *this;
    }

    istream &operator>>(istream &input, Fraction &num)
    {
        long int temp_denominator = 0;
        long int temp_numerator = 0;
        input >> temp_numerator;
        input >> temp_denominator;

        // making sure that the input isnt greather than maxint or lower than minint after reduction
        if (temp_numerator > max_int || temp_numerator < min_int || temp_denominator > max_int || temp_denominator < min_int)
            throw std::overflow_error("Input is greather than max_int or lower than min_int");

        if (temp_denominator == 0)
        {
            throw std::runtime_error("Error");
        }

        if (temp_denominator < 0)
        { // making sure the minus is in the Numerator
            temp_numerator *= -1;
            temp_denominator *= -1;
        }

        int gcd = abs(__gcd(temp_numerator, temp_denominator));

        num.Numerator = temp_numerator / gcd;
        num.Denominator = temp_denominator / gcd;

        return input;
    }

    ostream &operator<<(ostream &output, const Fraction &num)
    {
        output << num.Numerator << "/" << num.Denominator;
        return output;
    }
};
