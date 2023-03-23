#pragma once
#include"TwoDShape.h"

using namespace std;

class ThreeDShape :public TwoDShape {
private:
	double height;   //高

public:
	ThreeDShape(double length, double width, double height):TwoDShape(length, width) { //初始化列表在此处不能使用了，得显式调用父类的构造函数
		this->height = height;
	}

	double calculate() {
		return (this->getLength() * this->getWidth() * this->height);
	}
};