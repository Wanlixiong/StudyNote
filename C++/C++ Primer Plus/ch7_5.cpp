#include<iostream>
using namespace std;

long jc(unsigned int n);
int main()
{
	unsigned int a;
	cout << "������һ���������������������:";
	while (cin >> a)
	{
		cout << a << "�Ľ׳ˣ�" << jc(a) << endl;
		cout << "������һ���������������������:";
	}

	return 0;
}

long jc(unsigned int n)
{
	if (n == 0)
		return 1;
	else if (n > 0)
	{
		return n * jc(n - 1);
	}
}