#pragma once
/*
����һ�����ж�̬�ԵĻ���Shape�������������ࣺ
Բ Circle ��(Բ������Ͱ뾶)������ Rec ��(�Խ������㲻ͬ����)�������� Tri ��(������ͬ����)��ÿ������������һ����������ĺ�����
��д���򣬴��ļ� [file.txt](6/file.txt) �ж�ȡ��������������Ķ��󣬲����� Shape ָ�������У����ѭ������ÿ��������������
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;

constexpr double PI = 3.14;
constexpr int MAX = 20;

class Shape {
public:
	virtual double calArea() = 0;
};