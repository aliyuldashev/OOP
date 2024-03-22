#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction()
    { // default constructor
        cout << "default constructor" << endl;
        m_numerator = 0;
        m_denominator = 1;
    }

    // Constructor with two parameters
    Fraction(int numerator, int denominator = 1)
    {
        assert(denominator != 0);
        cout << "constructor with two parameters" << endl;
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() const
    {
        return m_numerator;
    }

    int getDenominator() const
    {
        return m_denominator;
    }

    double getValue() const
    {
        return double(m_numerator) / double(m_denominator);
    }
};

void printFraction(const Fraction &arg)
{
    cout << arg.getNumerator() << "/" << arg.getDenominator();
    cout << " = " << arg.getValue() << endl;
}

int main()
{
    Fraction *pfrac1 = new Fraction;
    Fraction *pfrac2 = new Fraction{};
    Fraction *pfrac3 = new Fraction();
    Fraction *pfrac4 = new Fraction(1, 2);
    Fraction *pfrac5 = new Fraction{1, 2};
    Fraction *pfrac6 = new Fraction[2];

    Fraction *pfracA[3];
    pfracA[0] = new Fraction(2, 3);
    pfracA[1] = new Fraction(2, 4);
    pfracA[2] = new Fraction(2, 5);

    printFraction(*pfrac1);
    printFraction(*pfrac2);
    printFraction(*pfrac3);
    printFraction(*pfrac4);
    printFraction(*pfrac5);
    printFraction(*(pfrac6 + 1));
    printFraction(*pfracA[0]);
    printFraction(*pfracA[2]);

    delete pfrac1;
    delete pfrac2;
    delete pfrac3;
    delete pfrac4;
    delete pfrac5;
    delete[] pfrac6;

    delete pfracA[0];
    delete pfracA[1];
    delete pfracA[2];

    return 0;
}
