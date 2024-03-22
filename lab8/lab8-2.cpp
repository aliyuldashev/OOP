#include <iostream>
using namespace std;
class Calculate
{
private:
    double m_value;
    double m_history[10];
    char m_operators[10];
    int m_index;

public:
    Calculate() : m_value(0), m_index(0)
    {
    }

    double getValue() const
    {
        return m_value;
    }

    double add(double value)
    {
        m_value += value;
        updateHistory('+', value);
        return m_value;
    }

    double subtract(double value)
    {
        m_value -= value;
        updateHistory('-', value);
        return m_value;
    }

    double multiply(double value)
    {
        m_value *= value;
        updateHistory('*', value);
        return m_value;
    }

    double divide(double value)
    {
        if (value != 0)
        {
            m_value /= value;
            updateHistory('/', value);
        }
        return m_value;
    }

    bool lastOperation(char &op, double &value)
    {
        if (m_index > 5)
        {
            op = m_operators[m_index - 1];
            value = m_history[m_index - 1];
            return true;
        }
        return false;
    }

    void undo()
    {
        if (m_index > 0)
        {
            m_index--;
            switch (m_operators[m_index])
            {
            case '+':
                m_value -= m_history[m_index];
                break;
            case '-':
                m_value += m_history[m_index];
                break;
            case '*':
                m_value /= m_history[m_index];
                break;
            case '/':
                m_value *= m_history[m_index];
                break;
            }
        }
    }

private:
    void updateHistory(char op, double value)
    {
        if (m_index < 10)
        {
            m_operators[m_index] = op;
            m_history[m_index] = value;
            m_index++;
        }
    }
};
int main(void)
{
    Calculate cc;
    char op;
    double value;
    bool flag;

    for (int i = 0; i < 10; ++i)
    {
        cout << "Select math operator (+,-,*,/): ";
        cin >> op;
        cout << "Enter a real number for the math: ";
        cin >> value;

        switch (op)
        {
        case '+':
            cout << cc.getValue() << "+" << value << "=" << cc.add(value) << endl;
            break;
        case '-':
            cout << cc.getValue() << "-" << value << "=" << cc.subtract(value) << endl;
            break;
        case '*':
            cout << cc.getValue() << "*" << value << "=" << cc.multiply(value) << endl;
            break;
        case '/':
            cout << cc.getValue() << "/" << value << "=" << cc.divide(value) << endl;
            break;
        }

        cout << endl
             << endl;
    }

    cout << endl
         << endl;

    for (int i = 0; i < 10; ++i)
    {
        cout << "Stored the last math operation: ";
        flag = cc.lastOperation(op, value);
        if (!flag)
            cout << "None" << endl;
        else
            cout << op << "," << value << endl;

        if (flag)
        {
            cc.undo();
            cout << "Undone the last math operation..." << endl;
            cout << "Value inside the class object: " << cc.getValue() << endl;
        }
    }

    cout << "Value inside the class object: " << cc.getValue() << endl;

    return 0;
}