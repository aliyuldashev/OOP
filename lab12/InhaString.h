// InhaString.h

#ifndef INHA_STRING_H
#define INHA_STRING_H

#include <iostream>
#include <cstring>

class InhaString
{
private:
    char *m_msg;
    int m_len;

public:

    InhaString();                        
    InhaString(const char *str);         
    InhaString(const InhaString &other); 


    ~InhaString();


    InhaString operator+(const InhaString &other) const;
    InhaString &operator=(const InhaString &other);
    bool operator==(const InhaString &other) const;
    InhaString &operator+=(const InhaString &other);


    friend std::ostream &operator<<(std::ostream &os, const InhaString &str);


    friend std::istream &operator>>(std::istream &is, InhaString &str);


    const char *getData() const;
};

#endif // INHA_STRING_H
