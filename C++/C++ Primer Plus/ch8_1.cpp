#include<iostream>

using namespace std;
const int Max = 20;
void show_str(const char *str, int n = 1);
int main()
{
	char str[Max] = "hello! C++";
	cout << "第一次调用函数：";
	show_str(str);
	cout << "第一次调用函数：\n";
	show_str(str, 5);

	return 0;
}

void show_str(const char *str, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << str << endl;
	}
}