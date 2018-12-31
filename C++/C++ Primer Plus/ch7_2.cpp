#include<iostream>

using namespace std;
const int MAX = 10;

int inputScore(double ScoreArray[], int n);		//����ɼ�
void showScore(double ScoreArray[], int n);		//��ʾ�ɼ�
double average(double ScoreArray[], int n);		//����ƽ���ɼ�

int main()
{
	double SA[MAX];
	int count;

	cout << "��������߶���ɼ�������������κ��������ǰ������" << endl;
	count = inputScore(SA, MAX);
	cout << "����������ĳɼ���" << endl;
	showScore(SA, count);
	cout << "ƽ��ֵ��" << average(SA, count) << endl;

	return 0;
}

int inputScore(double ScoreArray[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "��" << i + 1 << "���߶���ɼ���";
		if (!(cin >> ScoreArray[i]))	break;
		count++;
	}
	return count;
}

void showScore(double ScoreArray[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << ScoreArray[i] << " ";

	}
	cout << endl;
}

double average(double ScoreArray[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ScoreArray[i];
	}
	return sum / n;
}