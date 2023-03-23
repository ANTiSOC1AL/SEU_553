#pragma once

/*
写一个日期Date类
数据成员有年、月、日，成员函数有无参数构造函数、设置年月日的函数 setDate，还有一个打印函数display。
*/
#include<iostream>
#include<string>
#include<ctime>
using namespace std;


class Date {
private:
	int year;
	int month;
	int day;

public:
	//无参数构造函数
	Date() {
		this->year = 0;
		this->month = 0;
		this->day = 0;
	}

	//设置年月日的函数
	void setDate(int year, int month, int day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}

	//打印函数
	void display() {
		cout << year << "年" << month << "月" << day << "日" << endl;
	}

	int getYear() {
		return this->year;
	}
};
