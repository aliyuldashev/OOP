#ifndef _BANK_H_
#define _BANK_H_
#include <iostream>
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;
class Account
{
private:
    char *name;
    int id, balance;

public:
    Account(const char *name, int id, int balance);
    Account();
    ~Account();
    int getId() const
    {
        return id;
    }
    const char *getname() const
    {
        return name;
    }
    int getBalance() const
    {
        return balance;
    }
    void addBalance(int money)
    {
        balance += money;
    }
};

class AccountHandler
{
private:
    Account *m_accArr[MAX_ACC_NUM];
    int m_AccNum{0};

public:
    AccountHandler(Account datas, int datal);
    AccountHandler();
    ~AccountHandler();
    void ShowMenu(void);
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void);
    int GetAccIdx(int);
};

enum class bank
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

#endif // _BANK_H_