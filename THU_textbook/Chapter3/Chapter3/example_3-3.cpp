/*
求PI的值，PI = 16arctan(1/5) - 4arctan(1/239)
arctanx = x - x^3 / 3 + x^5 / 5 - x^7 / 7 + ...
*/
#include<iostream>
using namespace std;

double my_arctan(double x) {
	int sign = 1; //符号
	int k = 1;    //分母
	double sum = 0;
	double temp = x / k;

	do {
		sum += sign * temp;  //注意符号
		k++;
		temp = pow(x, 2 * k - 1) / (2 * k - 1);
		sign *= -1;

	} while (temp > 1e-15);

	return sum;
}

int main() {
	double PI = 16.0 * my_arctan(1.0 / 5) - 4.0 * my_arctan(1.0 / 239);
	cout << PI << endl;
}