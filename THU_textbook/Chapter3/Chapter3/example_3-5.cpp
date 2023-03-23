/*
计算下列公式并输出结果：
k = sqrt((sinr)^2 + (sins)^2) (r^2 <= s^2)
	(1/2)sin(rs)			  (r^2 > s^2)
r,s由键盘输入，sinx = x / 1! - x^3/3! + x^5/5! - ...
当某项绝对值小于10^-10时结束
*/
#include<iostream>
using namespace std;

double fac(int x) {
	double res = 1;
	for (int i = x; i >= 1; i--)
		res *= i;
	return res;
}

double my_sin(double x) {
	int i = 1;
	int sign = 1;
	double sum = 0;
	double temp = x / i;
	do {
		sum += sign * temp;
		i += 2;
		temp = pow(x, i) / fac(i);
		sign *= -1;
	} while (temp > 1e-10);

	return sum;
}

int main() {
	cout << "Please input two numbers as r, s: " << endl;
	int r, s;
	double k;
	cin >> r >> s;

	if (r * r <= s * s)
		k = sqrt(my_sin(r) * my_sin(r) + my_sin(s) * my_sin(s));
	else
		k = (1.0 / 2) * my_sin(r * s);

	cout << "k = " << k << endl;

	return 0;
}