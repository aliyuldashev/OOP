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
    friend Fraction operator-(const Fraction &fraction);
};

ostream &operator<<(ostream &os, const Fraction &fraction)
{
    os << fraction.m_numerator << '/' << fraction.m_denominator;
    return os;
}

Fraction operator-(const Fraction &fraction)
{
    return Fraction(-fraction.m_numerator, fraction.m_denominator);
}

int main()
{
    Fraction f1(1, 2), f2(3, 4);

    cout << f1 << "," << f2 << endl;
    cout << -f1 << "," << -f2 << endl;
    cout << -(-f1) << endl;

    return 0;
}
