#include<iostream>
#include"ch10_1.h"
#pragma warning(disable : 4996)
BankAccount::BankAccount(const char* client, const char* num, double bal)		//���幹�캯��
{
	std::strncpy(name, client, 10);
	std::strncpy(acctnum, num, 25);
	balance = bal;
}

void BankAccount::deposit(double cash)
{
	balance += cash;
}

void BankAccount::withdraw(double cash)
{
	balance -= cash;
}

void BankAccount::show()const
{
	std::cout << "������" << name << std::endl
		<< "�˺ţ�" << acctnum << std::endl
		<< "��" << balance << std::endl;
}