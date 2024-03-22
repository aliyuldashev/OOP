#include "SecuString.h"
#include <iostream>
using namespace std;

int main()
{
    SecuString msg{"InhaUniv.", "password1"};

    cout << "==GetMessage()==" << endl;
    cout << "1. " << msg.GetMessage("wrongpassword") << endl;
    cout << "2. " << msg.GetMessage("password1") << endl;

    cout << "==SetMessage()==" << endl;
    cout << "3. " << msg.SetMessage("INHAUNIV.", "wrongpassword") << endl;
    cout << "4. " << msg.GetMessage("password1") << endl;
    cout << "5. " << msg.SetMessage("INHAUNIV.", "password1") << endl;
    cout << "6. " << msg.GetMessage("password1") << endl;

    cout << "==ChangePW()==" << endl;
    cout << "7. " << msg.ChangePW("password1", "newpassword") << endl;
    cout << "8. " << msg.GetMessage("newpassword") << endl;

    return 0;
}
