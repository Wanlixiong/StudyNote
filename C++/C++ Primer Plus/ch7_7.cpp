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

	cout << "����������Ԫ��,q��ǰ����\n";
	double *end = fill_array(array, Max);		//����ָ���������һ��Ԫ�ص�ָ��

	cout << "���������Ϊ��";
	show_array(array, end);

	cout << "�����뱶����";
	cin >> r;
	revalue(r, array, end);
	cout << "������˺�";
	show_array(array, end);
}

double *fill_array(double array[], int n)
{
	double temp;
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Ԫ��" << (i + 1) << "#: ";
		if (cin >> temp && temp >= 0)		//�ų�����ֵ����͸�ֵ����
		{
			array[i] = temp;
		}
		else
		{
			break;
		}
	}

	return &array[i - 1];		//����ע�⣬����ѭ������һ��ʱi=5�ˣ�����Ҫ��ȷ�������һ������Ԫ�ص�ַ�������ȥ1�������¼��ʱԽ��ĵ�ַ
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