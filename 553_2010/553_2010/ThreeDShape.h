#pragma once
#include"TwoDShape.h"

using namespace std;

class ThreeDShape :public TwoDShape {
private:
	double height;   //��

public:
	ThreeDShape(double length, double width, double height):TwoDShape(length, width) { //��ʽ�ص��ø���Ĺ��캯��
		this->setLength(length);
		this->setWidth(width);
		this->height = height;
	}

	double calculate() {
		return (this->getLength() * this->getWidth() * this->height);
	}
};