#include<iostream>

using namespace std;
const int MAX = 10;

int inputScore(double ScoreArray[], int n);		//输入成绩
void showScore(double ScoreArray[], int n);		//显示成绩
double average(double ScoreArray[], int n);		//返回平均成绩

int main()
{
	double SA[MAX];
	int count;

	cout << "请输入个高尔夫成绩以数字以外的任何输入可提前结束！" << endl;
	count = inputScore(SA, MAX);
	cout << "这是你输入的成绩：" << endl;
	showScore(SA, count);
	cout << "平均值：" << average(SA, count) << endl;

	return 0;
}

int inputScore(double ScoreArray[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个高尔夫成绩：";
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