#include <iostream>
#include "InhaString.h"


InhaString::InhaString() : m_msg(nullptr), m_len(0) {}


InhaString::InhaString(const char *str) : m_msg(nullptr), m_len(0)
{
    m_len = static_cast<int>(strlen(str));
    m_msg = new char[m_len + 1];
    strcpy(m_msg, str);
}


InhaString::InhaString(const InhaString &other) : m_msg(nullptr), m_len(0)
{
    m_len = other.m_len;
    m_msg = new char[m_len + 1];
    strcpy(m_msg, other.m_msg);
}


InhaString::~InhaString()
{
    delete[] m_msg;
}


InhaString InhaString::operator+(const InhaString &other) const
{
    InhaString result;
    result.m_len = m_len + other.m_len;
    result.m_msg = new char[result.m_len + 1];
    strcpy(result.m_msg, m_msg);
    strcat(result.m_msg, other.m_msg);
    return result;
}


InhaString &InhaString::operator=(const InhaString &other)
{
    if (this != &other)
    {
        delete[] m_msg;
        m_len = other.m_len;
        m_msg = new char[m_len + 1];
        strcpy(m_msg, other.m_msg);
    }
    return *this;
}


bool InhaString::operator==(const InhaString &other) const
{
    return strcmp(m_msg, other.m_msg) == 0;
}


InhaString &InhaString::operator+=(const InhaString &other)
{
    char *new_msg = new char[m_len + other.m_len + 1];
    strcpy(new_msg, m_msg);
    strcat(new_msg, other.m_msg);

    delete[] m_msg;
    m_msg = new_msg;
    m_len += other.m_len;

    return *this;
}


std::ostream &operator<<(std::ostream &os, const InhaString &str)
{
    os << str.m_msg;
    return os;
}


std::istream &operator>>(std::istream &is, InhaString &str)
{

    char buffer[1024];
    is >> buffer;


    delete[] str.m_msg;
    str.m_len = static_cast<int>(strlen(buffer));
    str.m_msg = new char[str.m_len + 1];
    strcpy(str.m_msg, buffer);

    return is;
}

// Getter for data
const char *InhaString::getData() const
{
    return m_msg;
}

int main()
{
    InhaString str1 = "I like";
    InhaString str2 = "string class";
    InhaString str3 = str1 + str2;

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;

    InhaString st{str3};
    str1 += str2;

    if (str1 == str3)
        std::cout << "The two strings are identical." << std::endl;
    else
        std::cout << "The two strings are different." << std::endl;

    InhaString str4;
    std::cout << "Enter a string:";
    std::cin >> str4;
    std::cout << "You entered: " << str4 << std::endl;

    return 0;
}
