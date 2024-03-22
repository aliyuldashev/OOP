#ifndef _BANK_H_
#define _BANK_H_

#include <iostream>
#include <cstring>

const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

class Account
{
private:
    int m_accID;
    int m_balance;
    char *m_cusName;

public:
    Account(int ID, int balance, const char *cname);
    Account(const Account *scopy);
    ~Account();

    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    void addBalance(int money);
    const char *getname() const;
    int getBalance() const;
};

class SavingAccount : public Account
{
private:
    double interestRate;

public:
    SavingAccount(int ID, int balance, const char *cname, double interest);

    void Deposit(int money) override;
};

class HighCreditAccount : public SavingAccount
{
private:
    double specialInterestRate;

public:
    HighCreditAccount(int ID, int balance, const char *cname, double interest, double specialInterest);

    void Deposit(int money) override;
};

class AccountHandler
{
private:
    Account *m_accArr[MAX_ACC_NUM];
    int m_AccNum;

public:
    AccountHandler();
    ~AccountHandler();

    void ShowMenu() const;
    void MakeAccount();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllAccInfo() const;
    int GetAccIdx(int id) const;
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
