#include<iostream>
using namespace std;

void func(int a[]) {
	a[0] = a[-1] + a[1];
}

void main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 1; i < 9; i++)
		func(&a[i]);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;

	//½á¹ûÊÇ1 4 8 13 ... 10
}