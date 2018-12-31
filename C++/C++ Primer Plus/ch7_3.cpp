#include<iostream>

using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void ShowFunction(box fun1);
double Volume(box * pfun);

int main()
{
	box function0;
	cout << "Enter a maker name:";
	cin >> function0.maker;
	cout << "Enter height:";
	cin >> function0.height;
	cout << "Enter width:";
	cin >> function0.width;
	cout << "Enter length:";
	cin >> function0.length;
	ShowFunction(function0);
	cout << "volume:" << Volume(&function0) << endl;

	return 0;
}

void ShowFunction(box fun1)
{
	cout << "maker name:" << fun1.maker
		<< " height:" << fun1.height
		<< " width:" << fun1.width
		<< " length:" << fun1.length << endl;
}

double Volume(box * pfun)
{
	return pfun->volume = (pfun->height*pfun->length*pfun->width);
}