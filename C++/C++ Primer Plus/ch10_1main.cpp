#include<iostream>
#include"head.h"

int main()
{
	using std::cin;
	using std::cout;
	BankAccount a("default", "1000001", 0);		//�ṩĬ��ֵ
	a.show();
	cout << "��Ҫ���˺Ž���ʲô��������1������2ȡ�����,q�˳�����";
	char p;
	while (cin >> p && p != 'q')
	{
		switch (p)
		{
		case '1':
			cout << "��������";
			double k;
			cin >> k;
			a.deposit(k);
			break;
		case '2':
			cout << "������ȡ���ȣ�";
			double g;
			cin >> g;
			a.withdraw(g);
			break;
		default:
			break;
		}
		a.show();
		cout << "��Ҫ���˺Ž���ʲô��������1������2ȡ�����,q�˳�����";
	}


	return 0;
}