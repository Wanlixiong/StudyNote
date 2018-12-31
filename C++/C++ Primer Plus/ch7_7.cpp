#include<iostream>
using namespace std;
const int Max = 5;

double *fill_array(double array[], int n);
void show_array(double array[], double *end);
void revalue(double r, double array[], double *end);

int main()
{
	double array[Max];
	double r;

	cout << "请输入数组元素,q提前结束\n";
	double *end = fill_array(array, Max);		//或许指向数组最后一个元素的指针

	cout << "输入的数组为：";
	show_array(array, end);

	cout << "请输入倍数：";
	cin >> r;
	revalue(r, array, end);
	cout << "倍数相乘后：";
	show_array(array, end);
}

double *fill_array(double array[], int n)
{
	double temp;
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "元素" << (i + 1) << "#: ";
		if (cin >> temp && temp >= 0)		//排除非数值输入和负值输入
		{
			array[i] = temp;
		}
		else
		{
			break;
		}
	}

	return &array[i - 1];		//这里注意，跳出循环后到这一步时i=5了，所以要正确传递最后一个数组元素地址，必须减去1，否则记录的时越界的地址
}

void show_array(double array[], double *end)
{
	int i;
	for (i = 0; array[i] != *end; i++)		//
	{
		cout << array[i] << " ";
	}
	cout << array[i] << " " << endl;
}

void revalue(double r, double array[], double *end)
{
	int i = 0;
	for (i = 0; array[i] != *end; i++)
	{
		array[i] *= r;
	}
	array[i] *= r;
}