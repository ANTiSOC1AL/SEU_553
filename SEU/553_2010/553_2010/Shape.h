#pragma once
#include<string>
using namespace std;
class Shape {  //³éÏóÀà
private:
	string color;
public:
	virtual double calculate() = 0;
};