/*
下面的程序中定义了圆类 Circle、长方形类 Rect、圆角长方形类 RoundRect，其中RoudRect 共有继承于 Circle 和 Rect 类。试完成程序。
*/
#include<iostream>
using namespace std;

class Circle
{
	double radius;
public:
	Circle(double r): /*1*/ radius(r) {}
	double area() { return 3.14 * radius * radius; }
};
class Rect
{
	double width, height;
public:
	Rect(double w, double h) { width = w; height = h; }
	double area() { return height * width; }
};
class RoundRect : public Circle, /*2 好像别的继承方式也能跑通*/public Rect
{
	char color[5];
public:
	RoundRect(/*3 注意c是const char*或者是const char c[]*/double r, double w, double h, const char* c) :Circle(r), Rect(w, h)
	{
		strcpy(color, c);
	}
	char* getcolor() { return color; }
};
void main(void)
{
	RoundRect rr(0.8, 1, 0.25, "白色");
	cout << rr.getcolor() << endl;
}