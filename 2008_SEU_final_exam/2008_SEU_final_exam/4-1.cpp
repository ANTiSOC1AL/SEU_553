/*
����ĳ����ж�����Բ�� Circle���������� Rect��Բ�ǳ������� RoundRect������RoudRect ���м̳��� Circle �� Rect �ࡣ����ɳ���
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
class RoundRect : public Circle, /*2 �����ļ̳з�ʽҲ����ͨ*/public Rect
{
	char color[5];
public:
	RoundRect(/*3 ע��c��const char*������const char c[]*/double r, double w, double h, const char* c) :Circle(r), Rect(w, h)
	{
		strcpy(color, c);
	}
	char* getcolor() { return color; }
};
void main(void)
{
	RoundRect rr(0.8, 1, 0.25, "��ɫ");
	cout << rr.getcolor() << endl;
}