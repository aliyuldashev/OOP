#include <iostream>
#include "bank.h"
using namespace std;


Account::~Account()
{
	delete[] m_cusName;
}
AccountHandler::AccountHandler()
{
	for (int i = 0; i < MAX_ACC_NUM; ++i)
	{
		m_accArr[i] = nullptr;
	}
	m_AccNum = 0;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < m_AccNum; ++i)
	{
		delete m_accArr[i];
	}
	std::cout << "Bank destroyed" << std::endl;
}

void AccountHandler::ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. Make Accout" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Exit program" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int choice;
	double rat;

	if (m_AccNum >= MAX_ACC_NUM)
	{
		cout << "Sorry! cannot make an accout anymore." << endl;
		return;
	}
	cout << "[Make Account]" << endl;
	cout << "1.Saving Account  \n2. High Credit Account  \nSelect:";
	cin >> choice;
	if (choice == 1)
	{
		cout << "Account ID: ";
		cin >> id;
		cout << "Customer Name: ";
		cin >> name;
		cout << "Deposit amount: ";
		cin >> balance;
		cout << endl;
		cout << "interest rat: ";
		cin >> rat;
		cout << endl;
		SavingAccount(id, balance, name, rat);
	}
	if (choice == 2)
	{
		int adrat;
		cout << "Account ID: ";
		cin >> id;
		cout << "Customer Name: ";
		cin >> name;
		cout << "Deposit amount: ";
		cin >> balance;
		cout << endl;
		cout << "interest rat: ";
		cin >> rat;
		cout << endl;
		cout << "Cridit score: ";
		cin >> adrat;
		cout << endl;
		HighCreditAccount(id, balance, name, rat,adrat);
	}

	if (GetAccIdx(id) != -1)
	{
		cout << "Error: Existing account ID" << endl;
		return;
	}

	m_accArr[m_AccNum] = new SavingAccount(id, balance, name, rat);
	m_AccNum++;
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;

	for (int i = 0; i < m_AccNum; i++)
	{
		if (m_accArr[i]->GetAccID() == id)
		{
			m_accArr[i]->addBalance(money);
			cout << "Deposit completed" << endl
				 << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
		 << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;

	for (int i = 0; i < m_AccNum; i++)
	{
		if (m_accArr[i]->GetAccID() == id)
		{
			if (m_accArr[i]->getBalance() < money)
			{
				cout << "Not enough balance" << endl
					 << endl;
				return;
			}

			m_accArr[i]->addBalance(-money);
			cout << "Withdrawal completed" << endl
				 << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
		 << endl;
}

void AccountHandler::ShowAllAccInfo(void)
{
	for (int i = 0; i < m_AccNum; i++)
	{
		cout << "Account ID: " << m_accArr[i]->GetAccID() << endl;
		cout << "Name: " << m_accArr[i]->getname() << endl;
		cout << "Balance: " << m_accArr[i]->getBalance() << endl
			 << endl;
	}
}

int AccountHandler::GetAccIdx(int id)
{
	for (int i = 0; i < m_AccNum; i++)
	{
		if (m_accArr[i]->GetAccID() == id)
		{
			return i;
		}
	}
	return -1;
}