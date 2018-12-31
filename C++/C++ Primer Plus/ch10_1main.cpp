#include<iostream>
#include"head.h"

int main()
{
	using std::cin;
	using std::cout;
	BankAccount a("default", "1000001", 0);		//提供默认值
	a.show();
	cout << "你要对账号进行什么操作？（1存入款项，2取出余额,q退出）：";
	char p;
	while (cin >> p && p != 'q')
	{
		switch (p)
		{
		case '1':
			cout << "请输入款项：";
			double k;
			cin >> k;
			a.deposit(k);
			break;
		case '2':
			cout << "请输入取款额度：";
			double g;
			cin >> g;
			a.withdraw(g);
			break;
		default:
			break;
		}
		a.show();
		cout << "你要对账号进行什么操作？（1存入款项，2取出余额,q退出）：";
	}


	return 0;
}