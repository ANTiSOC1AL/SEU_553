#pragma once
/*
自定义数组Array的operator()访问，对于一个数组 Array 类的 chess 对象通过调用运算符重载函数()，实现 chess(row,column)代替 chess[row][column]。
请完成:
（1）Array 类的基本定义，包括构造函数、析构函数、拷贝构造函数和基本数据成员;
（2）运算符重载函数()的定义。
*/
#include<iostream>
#define MAX 10
using namespace std;


class Array {
private:
	int arr[MAX][MAX];
	int row;
	int column;

public:
	Array() {
		this->row = MAX;
		this->column = MAX;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				arr[i][j] = 0;
		cout << "Array constructor" << endl;
	}

	~Array() {
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				arr[i][j] = 0;
		this->row = 0;
		this->column = 0;
		cout << "Array destructor" << endl;
	}

	Array(const Array& arr) {
		this->row = arr.row;
		this->column = arr.column;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				this->arr[i][j] = arr.arr[i][j];
	}

	void printChess() {
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
				cout << this->arr[i][j] << " ";
			cout << endl;
		}
	}

	int operator()(int row, int column) {
		return this->arr[row][column];
	}
};