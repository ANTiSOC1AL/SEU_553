/*
编写一个程序，利用下面的公式计算e^x的值，要求精确到10^-10。
e^x = 1 + (x/1!) + (x^2/2!) + (x^3/3!) + ...
*/

#include<iostream>
#include<iomanip>
using namespace std;

//计算阶乘
double fac(int x) {
	double res = 1;

	for (int i = abs(x); i >= 1; i--)
		res *= i;

	return res;
}

//计算e^x
double cal(int x) {
	double res = 1;
	double temp = 1;
	int count = 1;

	do {
		temp = pow(x, count) / fac(count);
		res += temp;
		count++;
	} while (abs(temp) >= 1e-10);            //注意精确度的表示 10^x === 10ex

	return res;
}

int main() {
	int x;
	cout << "Please input an integer: ";
	cin >> x;

	cout.setf(ios::fixed);
	

	cout << "e^" << x << " = " << fixed << setprecision(10) << cal(x) << endl;

	return 0;
}