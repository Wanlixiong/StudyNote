#include<iostream>
#include"ch10_1.h"
#pragma warning(disable : 4996)
BankAccount::BankAccount(const char* client, const char* num, double bal)		//定义构造函数
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
	std::cout << "姓名：" << name << std::endl
		<< "账号：" << acctnum << std::endl
		<< "存款：" << balance << std::endl;
}