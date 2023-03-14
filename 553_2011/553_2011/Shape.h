#pragma once
/*
定义一个具有多态性的基类Shape，派生出三个类：
圆 Circle 类(圆心坐标和半径)，矩形 Rec 类(对角线两点不同坐标)，三角形 Tri 类(三个不同坐标)，每个类中至少有一个计算面积的函数。
编写程序，从文件 [file.txt](6/file.txt) 中读取数据来创建各类的对象，并放在 Shape 指针向量中，最后循环处理每个对象并输出面积。
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