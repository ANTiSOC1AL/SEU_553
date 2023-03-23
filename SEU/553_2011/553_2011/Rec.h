#pragma once
/*
����һ�����ж�̬�ԵĻ���Shape�������������ࣺ
Բ Circle ��(Բ������Ͱ뾶)������ Rec ��(�Խ������㲻ͬ����)�������� Tri ��(������ͬ����)��ÿ������������һ����������ĺ�����
��д���򣬴��ļ� [file.txt](6/file.txt) �ж�ȡ��������������Ķ��󣬲����� Shape ָ�������У����ѭ������ÿ��������������
*/

#include"Shape.h"
using namespace std;

class Rec :public Shape {
private:
	double point1[2];
	double point2[2];

public:
	Rec(ifstream &in) {
		in >> point1[0] >> point1[1] >> point2[0] >> point2[1];
	}
	~Rec() {
		memset(point1, 0, 2);
		memset(point2, 0, 2);
	}

	double calArea() {
		double len = abs(point1[0] - point2[0]);
		double width = abs(point1[1] - point2[1]);

		return (len * width);
	}
};