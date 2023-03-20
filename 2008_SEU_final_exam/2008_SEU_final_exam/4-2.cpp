/*
下列程序通过重载运算符“*”，直接实现两个一维数组对应元素相乘运算。设数组 a，b 分别为：
int a[10]={1,2,3,4,5,6,7,8,910};
int b[10]={1,2,3,4,5,6,7,8,9,10};
相乘后的结果为{1,4,9,16,25,36,49,64,81,100}。同时通过重载运算符“=”，直接实现两个一维数组的赋值运算。试完善程序。
*/
#include<iostream>
using namespace std;

class A
{
	int x[10];
public:
	A() { for (int i = 0; i < 10; i++)x[i] = 0; }
	A(int* p)
	{
		for (int i = 0; i < 10; i++) /*1*/ this->x[i] = p[i];
	}
	A operator *(A a)
	{
		A t;
		for (int i = 0; i < 10; i++) /*2*/ t.x[i] = this->x[i] * a.x[i];
			return t;
	}
	A operator =(A a)
	{
		for (int i = 0; i < 10; i++) /*3*/ this->x[i] = a.x[i];
			return *this;
	}
	void show() { for (int i = 0; i < 10; i++)cout << x[i] << '\t'; }
};
void main(void)
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
	A a1(a), a2(b), a3;
	a3 = a1 * a2;
	a3.show();
}