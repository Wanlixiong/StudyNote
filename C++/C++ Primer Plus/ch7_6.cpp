#include<iostream>

using namespace std;
const int MAX = 10;		//设置数组限度
int Fil_array(double array[]);		//输入数组元素
void Show_array(double array[], int n);		//显示数组
void Reverse_array(double array[], int n);		//反转数组

int main()
{
	double array[MAX];
	int n;

	n = Fil_array(array);

	cout << "数组元素为:";
	Show_array(array, n);

	cout << "将数组反转：";
	Reverse_array(array, n);
	Show_array(array, n);

	return 0;
}

int Fil_array(double array[])
{
	double ar;
	cout << "输入数组元素,q结束:\n";
	int i = 0;		//计算数组输入个数
	while (cin >> ar && i < MAX)
	{
		array[i] = ar;
		i++;

	}
	return i;
}

void Show_array(double array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void Reverse_array(double array[], int n)
{
	double temp;
	for (int i = 0; i < n / 2; i++)
	{
		temp = array[i];
		array[i] = array[n - 1 - i];
		array[n - 1 - i] = temp;
	}
}