#pragma once
/*
����һ�����ж�̬�ԵĻ���Shape�������������ࣺ
Բ Circle ��(Բ������Ͱ뾶)������ Rec ��(�Խ������㲻ͬ����)�������� Tri ��(������ͬ����)��ÿ������������һ����������ĺ�����
��д���򣬴��ļ� [file.txt](6/file.txt) �ж�ȡ��������������Ķ��󣬲����� Shape ָ�������У����ѭ������ÿ��������������
*/
#include"Shape.h"
using namespace std;

class Tri :public Shape {
private:
	double point1[2];
	double point2[2];
	double point3[2];

public:
	Tri(ifstream &in) {
		in >> this->point1[0] >> this->point1[1] >> this->point2[0] >> this->point2[1] >> this->point3[0] >> this->point3[1];
	}
	~Tri() {
		memset(point1, 0, 2);
		memset(point2, 0, 2);
		memset(point3, 0, 2);
	}
	
	double dis(double point1[], double point2[]) {
		return sqrt((point1[0] - point2[0]) * (point1[0] - point2[0]) +
					(point1[1] - point2[1]) * (point1[1] - point2[1]));
	}

	double calArea() {
		double a = dis(point1, point2);
		double b = dis(point1, point3);
		double c = dis(point2, point3);
		double p = (a + b + c) / 2;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
		cout << "p = " << p << endl;
		cout << "sqrt(p * (p - a) * (p - b) * (p - c)) = " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	void printTri() {
		cout << point1[0] << ", " << point1[1] << endl;
		cout << point2[0] << ", " << point2[1] << endl;
		cout << point3[0] << ", " << point3[1] << endl;
	}
};