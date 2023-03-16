/*
��e^x��ֵ��Ҫ�� |(x^n / n) - (x^(n - 1) / (n - 1)!)| < 10^-7
��֪��e^x = 1 + x / 1! + x^2 / 2! + ...
*/
#include<iostream>
#include<iomanip>
using namespace std;

//��x�Ľ׳�
double fac(int x) {
	double res = 1;

	for (int i = abs(x); i >= 1; i--)
		res *= i;

	return res;
}

//�����������ĵ��ǽ�����ǳ����Ҳ�����bug
double e(double x) {
	double res = 1;
	double temp2 = 1;
	double temp1 = 1;
	int count = 1;

	while(true) {
		temp2 = pow(x, count) / fac(count);
		res += temp2;
		if (fabs(temp2 - temp1) < 10e-7) break;
		count++;
		temp1 = temp2;
	}        

	return res;
}

int main() {
	cout << "Please input a number: ";
	double x;
	cin >> x;

	cout.fixed;
	cout << setprecision(15) << e(x) << endl;

	return 0;
}