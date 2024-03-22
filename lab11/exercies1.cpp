#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator} {}

    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);
};

std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
{
    os << fraction.m_numerator << '/' << fraction.m_denominator;
    return os;
}

int main()
{
    Fraction f1{1, 2}, f2{3, 4};
    std::cout << f1 << "," << f2 << std::endl;
    return 0;
}
