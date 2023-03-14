#pragma once
/*
����һ�����ж�̬�ԵĻ���Shape�������������ࣺ
Բ Circle ��(Բ������Ͱ뾶)������ Rec ��(�Խ������㲻ͬ����)�������� Tri ��(������ͬ����)��ÿ������������һ����������ĺ�����
��д���򣬴��ļ� [file.txt](6/file.txt) �ж�ȡ��������������Ķ��󣬲����� Shape ָ�������У����ѭ������ÿ��������������
*/
#include"Shape.h"
using namespace std;

class Circle :public Shape {
private:
	double crdnt[2];  //Բ������
	double radius;    //�뾶

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