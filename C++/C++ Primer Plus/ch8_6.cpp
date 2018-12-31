#include<iostream>
#include<string>
using namespace std;

template<class T>
T maxn(T array[], int n);
const char * maxstr_address(const char *str[], int n);

int main()
{
	int arr0[6] = { 1,2,3,4,5,6 };
	double arr1[4] = { 1.4,1.3,1.2,1.2 };
	const char * str[5] = { "abc", "abcd","abcde","abcdf","abcdefg" };

	cout << "Tnt max:" << maxn(arr0, 4) << endl;
	cout << "double max:" << maxn(arr1, 6) << endl;

	const char * maxstr_l;
	maxstr_l = maxstr_address(str, 5);		//获取最大字符串
	cout << "Max lenght address: " << maxstr_l << endl;
	cout << " address=";
	for (int i = 0; i < 5; i++)
	{
		if (str[i] == maxstr_l)
			cout << &str[i];
	}
	cout << endl;
	return 0;
}

template<class T>
T maxn(T array[], int n)
{
	T temp;
	temp = array[0];
	for (int i = 1; i < 5; i++)
	{
		if (array[i] > temp)
			temp = array[i];
	}
	return temp;
}
const char * maxstr_address(const char *str[], int n)
{
	const char *max_address = str[0];		//指针max_address记录指向指针数组中指向最大字符串的指针地址
	int temp = strlen(str[0]);
	for (int i = 1; i < n; i++)
	{
		if (strlen(str[i]) > temp)
			max_address = str[i];
	}

	return max_address;		//返回指向指针数组中指向最大字符串的指针地址，不是最大字符串地址
}
