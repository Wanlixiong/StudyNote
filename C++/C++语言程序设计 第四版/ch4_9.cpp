#include<iostream>
#include<cmath>
using namespace std;

class Point		//坐标点类
{
private:
	double x, y;
public:
	Point(double xx = 0, double yy = 0)		//内联构造函数
	{
		x = xx;
		y = yy;
	}

	double getX() { return x; }		//该成员函数用于获取一个x点
	double getY() { return y; }		//该成员函数用于获取一个y点
};

class Rectangle		//矩形类
{
private:
	Point p1, p2;		//把两个Point对象作为私有成员
	double area;
public:
	Rectangle(Point pp1, Point pp2); 	//构造函数
	double getArea() { return area; }
};

Rectangle::Rectangle(Point pp1, Point pp2) :p1(pp1), p2(pp2)
{
	double h = abs(p1.getY() - p2.getY());		//计算高
	double w = abs(p1.getX() - p2.getX());		//计算宽
	area = h * w;
}

int main()
{
	Point Ldown(1, 1), Rtop(4, 4);
	Rectangle rec(Ldown, Rtop);
	cout << "矩形面积：" << rec.getArea() << endl;

	return 0;
}