#include<iostream>

using namespace std;

struct CandyBar
{
	char ppname[20];
	double weight;
	int reliang;
};

const CandyBar &fun(CandyBar & bieming, char *pn, double w, int r);

int main()
{
	CandyBar mr =
	{
		"Millennium Munch",
		2.85,
		350
	};

	cout << "结构成员如下：\n";
	fun(mr, mr.ppname, mr.weight, mr.reliang);

	return 0;
}

const CandyBar &fun(CandyBar & bieming, char *pn, double w, int r)
{
	cout << "bieming.ppname=" << bieming.ppname << endl
		<< "bieming.weight=" << bieming.weight << endl
		<< "bieming.reliang=" << bieming.reliang << endl;
	return bieming;
}