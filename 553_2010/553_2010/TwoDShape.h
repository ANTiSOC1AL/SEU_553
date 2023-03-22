#pragma once
#include"Shape.h"
#include<iostream>
using namespace std;

class TwoDShape :public Shape {
private:
	double length;  //³¤
	double width;   //¿í

public:
	TwoDShape(double length, double width) :length(length), width(width) {}

	double getLength() {
		return this->length;
	}

	double getWidth() {
		return this->width;
	}

	virtual double calculate() {
		return this->length * this->width;
	}
};