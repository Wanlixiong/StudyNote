#include<iostream>

using namespace std;
const int MAX = 10;		//���������޶�
int Fil_array(double array[]);		//��������Ԫ��
void Show_array(double array[], int n);		//��ʾ����
void Reverse_array(double array[], int n);		//��ת����

int main()
{
	double array[MAX];
	int n;

	n = Fil_array(array);

	cout << "����Ԫ��Ϊ:";
	Show_array(array, n);

	cout << "�����鷴ת��";
	Reverse_array(array, n);
	Show_array(array, n);

	return 0;
}

int Fil_array(double array[])
{
	double ar;
	cout << "��������Ԫ��,q����:\n";
	int i = 0;		//���������������
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