#pragma once
#include<string>
using namespace std;
class Shape {  //������
private:
	string color;
public:
	virtual double calculate() = 0;
};