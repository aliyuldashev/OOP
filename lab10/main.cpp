#include <iostream>
#include "bank.h"
using namespace std;

int main(void)
{
    int choice;
    AccountHandler manager;
    while (1)
    {
        manager.ShowMenu();
        cout << "Select menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice))
        {
        case bank::MAKE:
            manager.MakeAccount();
            break;
        case bank::DEPOSIT:
            manager.DepositMoney();
            break;
        case bank::WITHDRAW:
            manager.WithdrawMoney();
            break;
        case bank::INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case bank::EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}
