/*
编写一个程序，利用下面的公式计算pi的值，要求小数点后的位数为计算机可表达的最大范围。
PI = 4 - 4/3 + 4/5 - 4/7 +...
*/
#include<iostream>
#include<iomanip>
#include<limits>
#include<string>
using namespace std;

double calPI() {
	double res = 0;
	double temp = 1;
	int k = 1;      
	int sign = 1;
	int dividend;    //用于当做分母
	cout << "Calculating..." << endl;

	do {
		dividend = sign * (2 * k - 1);
		temp = 4.0 / dividend;
		res += temp;
		k++;
		sign *= -1;
		cout << "res = " << setprecision(numeric_limits<double>::digits10) << res << endl;
	} while (abs(temp) > pow(10, -(numeric_limits<double>::digits10)));    //numeric_limits<double>::digits10为此计算机double的最大位数

	cout << "Finished!" << endl;
	return res;
}

int main() {
	cout.setf(ios::fixed);
	cout << "PI = " << setprecision(15) << calPI() << endl;
	return 0;
}