// #include <iostream>
// using namespace std;
// class Fraction
// {
// private:
//     int m_numerator;
//     int m_denominator;

// public:
//     Fraction(int numerator = 0, int denominator = 1)
//         : m_numerator{numerator}, m_denominator{denominator} {}

//     friend ostream &operator<<(ostream &os, const Fraction &fraction);
//     friend Fraction operator*(const Fraction &f1, const Fraction &f2);
//     friend Fraction operator*(const Fraction &fraction, int scalar);
//     friend Fraction operator*(int scalar, const Fraction &fraction);
//     friend Fraction operator+(const Fraction &f1, const Fraction &f2);
//     friend Fraction operator+(const Fraction &fraction, int scalar);
//     friend Fraction operator+(int scalar, const Fraction &fraction);
//     friend Fraction operator-(const Fraction &f1, const Fraction &f2);
//     friend Fraction operator-(const Fraction &fraction, int scalar);
//     friend Fraction operator-(int scalar, const Fraction &fraction);
// };

// ostream &operator<<(ostream &os, const Fraction &fraction)
// {
//     os << fraction.m_numerator << '/' << fraction.m_denominator;
//     return os;
// }

// Fraction operator*(const Fraction &f1, const Fraction &f2)
// {
//     int resultNumerator = f1.m_numerator * f2.m_numerator;
//     int resultDenominator = f1.m_denominator * f2.m_denominator;
//     return Fraction(resultNumerator, resultDenominator);
// }

// Fraction operator*(const Fraction &fraction, int scalar)
// {
//     int resultNumerator = fraction.m_numerator * scalar;
//     return Fraction(resultNumerator, fraction.m_denominator);
// }

// Fraction operator*(int scalar, const Fraction &fraction)
// {
//     return fraction * scalar;
// }

// // Plus minus
// Fraction operator+(const Fraction &f1, const Fraction &f2)
// {
//     int resultNumerator = f1.m_numerator + f2.m_numerator;
//     int resultDenominator = f1.m_denominator + f2.m_denominator;
//     return Fraction(resultNumerator, resultDenominator);
// }

// Fraction operator+(const Fraction &fraction, int scalar)
// {
//     int resultNumerator = fraction.m_numerator + scalar;
//     return Fraction(resultNumerator, fraction.m_denominator);
// }

// Fraction operator+(int scalar, const Fraction &fraction)
// {
//     return fraction + scalar;
// }
// Fraction operator-(const Fraction &f1, const Fraction &f2)
// {
//     int resultNumerator = f1.m_numerator - f2.m_numerator;
//     int resultDenominator = f1.m_denominator - f2.m_denominator;
//     return Fraction(resultNumerator, resultDenominator);
// }

// Fraction operator-(const Fraction &fraction, int scalar)
// {
//     int resultNumerator = fraction.m_numerator - scalar;
//     return Fraction(resultNumerator, fraction.m_denominator);
// }

// Fraction operator-(int scalar, const Fraction &fraction)
// {
//     return fraction - scalar;
// }
// int main()
// {
//     Fraction f1(1, 2), f2(3, 4);

//     cout << f1 << "," << f2 << endl;
//     cout << f1 << "*" << f2 << "=" << f1 * f2 << endl;
//     cout << f1 << "+" << f2 << "=" << f1 + f2 << endl;
//     cout << f1 << "-" << f2 << "=" << f1 - f2 << endl;
//     cout << 2 << "-" << f2 << "=" << 2 - f2 << endl;
//     cout << 2 << "+" << f1 << "=" << 2 + f1 << endl;

//     return 0;
// }
#include <iostream>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator(numerator), m_denominator(denominator) {}

    friend ostream &operator<<(ostream &os, const Fraction &fraction);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
};
ostream &operator<<(ostream &os, const Fraction &fraction)
{
    os << fraction.m_numerator << '/' << fraction.m_denominator;
    return os;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    int resultNumerator = f1.m_numerator * f2.m_numerator;
    int resultDenominator = f1.m_denominator * f2.m_denominator;
    return Fraction(resultNumerator, resultDenominator);
}

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    int resultNumerator = f1.m_numerator * f2.m_denominator + f2.m_numerator * f1.m_denominator;
    int resultDenominator = f1.m_denominator * f2.m_denominator;
    return Fraction(resultNumerator, resultDenominator);
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    int resultNumerator = f1.m_numerator * f2.m_denominator - f2.m_numerator * f1.m_denominator;
    int resultDenominator = f1.m_denominator * f2.m_denominator;
    return Fraction(resultNumerator, resultDenominator);
}

int main()
{
    Fraction f1(1, 2), f2(3, 4);

    cout << f1 << "," << f2 << endl;
    cout << f1 << "*" << f2 << "=" << f1 * f2 << endl;
    cout << f1 << "+" << f2 << "=" << f1 + f2 << endl;
    cout << f1 << "-" << f2 << "=" << f1 - f2 << endl;
    cout << 2 << "-" << f2 << "=" << 2 - f2 << endl;
    cout << 2 << "+" << f1 << "=" << 2 + f1 << endl;

    return 0;
}
