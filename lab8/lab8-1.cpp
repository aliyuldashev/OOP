#include <iostream>
using namespace std;
class Calculate
{
    double value;

public:
    Calculate();
    double getValue();
    double substract(double);
    double multiply(double);
    double divide(double);
    double add(double);
};

int main(void)
{
    Calculate cc;
    int i;
    char op;
    double value;
    for (i = 0; i < 10; ++i)
    {
        cout << "Select math operator(+,-,*,/): ";
        cin >> op;
        cout << "Enter a real number for the math: ";
        cin >> value;

        switch (op)
        {
        case '+':
            cout << cc.getValue() << " + " << value;
            cout << " = " << cc.add(value) << endl;
            break;
        case '-':
            cout << cc.getValue() << " - " << value;
            cout << " = " << cc.substract(value) << endl;
            break;
        case '*':
            cout << cc.getValue() << " * " << value;
            cout << " = " << cc.multiply(value) << endl;
            break;
        case '/':
            cout << cc.getValue() << " / " << value;
            cout << " = " << cc.divide(value) << endl;
            break;
        }
    }
    return 0;
}

Calculate::Calculate() : value{0}
{
}

double Calculate::getValue()
{
    return value;
}
double Calculate::add(double v)
{
    value += v;
    return value;
}
double Calculate::substract(double v)
{
    value -= v;
    return value;
}
double Calculate::multiply(double v)
{
    value *= v;
    return value;
}
double Calculate::divide(double v)
{
    value /= v;
    return value;
}
