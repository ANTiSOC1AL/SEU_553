#pragma once
#include"Shape.h"
#include<iostream>
using namespace std;

class TwoDShape :public Shape {
private:
	double length;  //³¤
	double width;   //¿í

public:
	TwoDShape(double length, double width) {
		this->length = length;
		this->width = width;
	}

	double getLength() {
		return this->length;
	}
	void setLength(double length) {
		this->length = length;
	}

	double getWidth() {
		return this->width;
	}
	void setWidth(double width) {
		this->width = width;
	}

	virtual double calculate() {
		return this->length * this->width;
	}
};