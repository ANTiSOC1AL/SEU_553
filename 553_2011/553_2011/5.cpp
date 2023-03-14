/*
自定义数组Array的operator()访问，对于一个数组 Array 类的 chess 对象通过调用运算符重载函数()，实现 chess(row,column)代替 chess[row][column]
请完成:
（1）Array 类的基本定义，包括构造函数、析构函数、拷贝构造函数和基本数据成员;
（2）运算符重载函数()的定义。
*/
#include"Array.h"

int main() {
	Array chess;
	chess.printChess();
	
	int row = 0, column = 0;
	cout << "chess(row, column) = " << chess(row, column) << endl;

	return 0;
}