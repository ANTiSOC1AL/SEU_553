#pragma once
#include"TwoDShape.h"

using namespace std;

class ThreeDShape :public TwoDShape {
private:
	double height;   //高

public:
	ThreeDShape(double length, double width, double height):TwoDShape(length, width) { //显式地调用父类的构造函数
		this->setLength(length);
		this->setWidth(width);
		this->height = height;
	}

	double calculate() {
		return (this->getLength() * this->getWidth() * this->height);
	}
};