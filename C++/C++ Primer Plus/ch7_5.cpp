#include<iostream>
using namespace std;

long jc(unsigned int n);
int main()
{
	unsigned int a;
	cout << "请输入一个正整数，其他输入结束:";
	while (cin >> a)
	{
		cout << a << "的阶乘：" << jc(a) << endl;
		cout << "请输入一个正整数，其他输入结束:";
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