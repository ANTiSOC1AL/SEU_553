#pragma once
/*
定义一个具有多态性的基类Shape，派生出三个类：
圆 Circle 类(圆心坐标和半径)，矩形 Rec 类(对角线两点不同坐标)，三角形 Tri 类(三个不同坐标)，每个类中至少有一个计算面积的函数。
编写程序，从文件 [file.txt](6/file.txt) 中读取数据来创建各类的对象，并放在 Shape 指针向量中，最后循环处理每个对象并输出面积。
*/
#include"Shape.h"
using namespace std;

class Circle :public Shape {
private:
	double crdnt[2];  //圆心坐标
	double radius;    //半径

public:
	Circle(ifstream& in) {
		in >> this->crdnt[0] >> this->crdnt[1] >> this->radius;
	}
	~Circle() {
		for (int i = 0; i < 2; i++)
			this->crdnt[i] = 0;
		this->radius = 0;;
	}

	void printCircle() {
		std::cout << "crdnt = (" << crdnt[0] << ", " << crdnt[1] << "). radius = " << this->radius << std::endl;
	}

	double calArea() {
		return PI * radius * radius;
	}
};