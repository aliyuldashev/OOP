#include <iostream>
#include "bank.h"
using namespace std;

int main(void)
{
    int choice;
    AccountHandler newbank;
    while (1)
    {
        newbank.ShowMenu();
        cout << "Select menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice))
        {
        case bank::MAKE:
            newbank.MakeAccount();
            break;
        case bank::DEPOSIT:
            newbank.DepositMoney();
            break;
        case bank::WITHDRAW:
            newbank.WithdrawMoney();
            break;
        case bank::INQUIRE:
            newbank.ShowAllAccInfo();
            break;
        case bank::EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}
