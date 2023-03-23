#pragma once
#include"TwoDShape.h"

using namespace std;

class ThreeDShape :public TwoDShape {
private:
	double height;   //��

public:
	ThreeDShape(double length, double width, double height):TwoDShape(length, width) { //��ʼ���б��ڴ˴�����ʹ���ˣ�����ʽ���ø���Ĺ��캯��
		this->height = height;
	}

	double calculate() {
		return (this->getLength() * this->getWidth() * this->height);
	}
};