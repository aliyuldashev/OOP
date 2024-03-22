#include "SecuString.h"

SecuString::SecuString(const std::string &message, const std::string &newPassword)
    : storedString(message), password(newPassword) {}

bool SecuString::SetMessage(const std::string &newMessage, const std::string &oldPassword)
{
    if (password == oldPassword)
    {
        storedString = newMessage;
        return true;
    }
    return false;
}

std::string SecuString::GetMessage(const std::string &enteredPassword) const
{
    return (password == enteredPassword) ? storedString : "Invalid password!";
}

bool SecuString::ChangePW(const std::string &oldPassword, const std::string &newPassword)
{
    if (password == oldPassword)
    {
        password = newPassword;
        return true;
    }
    return false;
}
