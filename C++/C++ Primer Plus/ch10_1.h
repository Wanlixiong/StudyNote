#ifndef ch10_1_H_
#define ch10_1_H_
#include<cstring>

class BankAccount
{
public:
	BankAccount(const char* client, const char* num, double bal = 0.0);

	void show()const;
	void deposit(double cash);
	void withdraw(double cash);

private:
	char name[10];
	char acctnum[25];
	double balance;
};

#endif