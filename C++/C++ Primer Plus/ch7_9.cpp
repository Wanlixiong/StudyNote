#include<iostream>
using namespace std;

double calculate(double x, double y, double(*pf)(double, double));
double add(double x, double y);
double chen(double x, double y);

int main()
{
	double a, b;
	double(*pf[2])(double, double);
	pf[0] = add;		//������ָ��ָ���Ӧ����
	pf[1] = chen;
	cout << "��������������";
	int i = 0;
	while (cin >> a >> b)
	{
		cout << "add:" << pf[0](a, b) << endl;

		cout << "chen:" << pf[1](a, b) << endl;

		cout << "���������������,�粻���ٽ������룬q�˳���";
	}

	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double chen(double x, double y)
{
	return x * y;
}

double calculate(double x, double y, double(*pf)(double, double))
{
	return (*pf)(x, y);
}