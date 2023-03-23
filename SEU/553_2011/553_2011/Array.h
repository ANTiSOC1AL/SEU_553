#pragma once
/*
�Զ�������Array��operator()���ʣ�����һ������ Array ��� chess ����ͨ��������������غ���()��ʵ�� chess(row,column)���� chess[row][column]��
�����:
��1��Array ��Ļ������壬�������캯���������������������캯���ͻ������ݳ�Ա;
��2����������غ���()�Ķ��塣
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