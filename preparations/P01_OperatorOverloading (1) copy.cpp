#include <iostream>
#include <cstring> // for strlen
using namespace std;

class MyString
{
private:
    char *m_sen;

public:
    MyString(const char *sen)
    {
        m_sen = new char[strlen(sen) + 1];
        strcpy(m_sen, sen);
    }

    // Copy constructor
    MyString(const MyString &other)
    {
        m_sen = new char[strlen(other.m_sen) + 1];
        strcpy(m_sen, other.m_sen);
    }

    // Destructor
    ~MyString()
    {
        delete[] m_sen;
    }

    // Overloaded << operator for output
    friend ostream &operator<<(ostream &out, const MyString &sen);

    // Overloaded + operator for concatenation
    MyString operator+(const MyString &other) const;

    // Overloaded += operator for concatenation and assignment
    MyString &operator+=(const MyString &other);

    // Overloaded == operator for comparison
    bool operator==(const MyString &other) const;

    // Overloaded >> operator for input
    friend istream &operator>>(istream &in, MyString &sen);
};

// Overloaded << operator for output
ostream &operator<<(ostream &out, const MyString &sen)
{
    out << sen.m_sen;
    return out;
}

// Overloaded + operator for concatenation
MyString MyString::operator+(const MyString &other) const
{
    MyString result(m_sen);
    result += other;
    return result;
}

// Overloaded += operator for concatenation and assignment
MyString &MyString::operator+=(const MyString &other)
{
    char *temp = new char[strlen(m_sen) + strlen(other.m_sen) + 1];
    strcpy(temp, m_sen);
    strcat(temp, other.m_sen);

    delete[] m_sen;
    m_sen = temp;

    return *this;
}

// Overloaded == operator for comparison
bool MyString::operator==(const MyString &other) const
{
    return strcmp(m_sen, other.m_sen) == 0;
}

// Overloaded >> operator for input
istream &operator>>(istream &in, MyString &sen)
{
    char buffer[4096];
    in >> buffer;

    // Release the old memory
    delete[] sen.m_sen;

    // Allocate new memory
    sen.m_sen = new char[strlen(buffer) + 1];

    // Copy the content
    strcpy(sen.m_sen, buffer);

    return in;
}

int main()
{
    MyString str1 = "I like ";
    MyString str2 = "MyString class";
    MyString str3 = str1 + str2;
    MyString str4{str3};
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "The two strings are identical." << endl;
    else
        cout << "The two strings are different." << endl;

    cout << "Enter a string: ";
    cin >> str4;
    cout << "You entered: " << str4 << endl;

    return 0;
}
