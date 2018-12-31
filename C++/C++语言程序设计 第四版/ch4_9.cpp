#include<iostream>
#include<cmath>
using namespace std;

class Point		//�������
{
private:
	double x, y;
public:
	Point(double xx = 0, double yy = 0)		//�������캯��
	{
		x = xx;
		y = yy;
	}

	double getX() { return x; }		//�ó�Ա�������ڻ�ȡһ��x��
	double getY() { return y; }		//�ó�Ա�������ڻ�ȡһ��y��
};

class Rectangle		//������
{
private:
	Point p1, p2;		//������Point������Ϊ˽�г�Ա
	double area;
public:
	Rectangle(Point pp1, Point pp2); 	//���캯��
	double getArea() { return area; }
};

Rectangle::Rectangle(Point pp1, Point pp2) :p1(pp1), p2(pp2)
{
	double h = abs(p1.getY() - p2.getY());		//�����
	double w = abs(p1.getX() - p2.getX());		//�����
	area = h * w;
}

int main()
{
	Point Ldown(1, 1), Rtop(4, 4);
	Rectangle rec(Ldown, Rtop);
	cout << "���������" << rec.getArea() << endl;

	return 0;
}