/*
һ������ Shape���ڻ���Ļ����ϼ̳�дһ����άͼ���࣬�ټ̳�дһ����άͼ���࣬�����ʵ����غ�������ʵ����̬�ԡ�
*/
#include"ThreeDShape.h"
#include<iostream>
using namespace std;

int main() {
	double length = 10, width = 20, height = 30;
	cout << "length = " << length << ", width = " << width << ", height = " << height << endl;

	TwoDShape twoDShape(length, width);
	ThreeDShape threeDShape(length, width, height);

	cout << "---------��̬��---------" << endl;
	Shape* shape;
	shape = &twoDShape;
	cout << "shape->calculate() = " << shape->calculate() << endl;
	
	shape = &threeDShape;
	cout << "shape->calculate() = " << shape->calculate() << endl;

	shape = nullptr;

	return 0;
}