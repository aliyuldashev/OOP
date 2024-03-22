#ifndef SECUSTRING_H
#define SECUSTRING_H

#include <string>

class SecuString
{
private:
    std::string storedString;
    std::string password;

public:
    SecuString(const std::string &message, const std::string &newPassword);

    bool SetMessage(const std::string &newMessage, const std::string &oldPassword);

    std::string GetMessage(const std::string &enteredPassword) const;

    bool ChangePW(const std::string &oldPassword, const std::string &newPassword);
};

#endif // SECUSTRING_H
