/*
一个基类 Shape，在基类的基础上继承写一个二维图形类，再继承写一个三维图形类，设计与实现相关函数，并实践多态性。
*/
#include"ThreeDShape.h"
#include<iostream>
using namespace std;

int main() {
	double length = 10, width = 20, height = 30;
	cout << "length = " << length << ", width = " << width << ", height = " << height << endl;

	TwoDShape twoDShape(length, width);
	ThreeDShape threeDShape(length, width, height);

	cout << "---------多态性---------" << endl;
	Shape* shape;
	shape = &twoDShape;
	cout << "shape->calculate() = " << shape->calculate() << endl;
	
	shape = &threeDShape;
	cout << "shape->calculate() = " << shape->calculate() << endl;

	shape = nullptr;

	return 0;
}