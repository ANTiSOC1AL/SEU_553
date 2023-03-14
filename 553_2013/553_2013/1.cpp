/*
编写程序，计算1~20000之间的质数，输出时要求每行10个数。
*/
#include<iostream>
using namespace std;

bool is_prime_num(int num) {
	int div = 1;
	bool res = true;

	for (div; div < num; div++) {
		if (num % div == 0 && div != 1) {
			res = false;
			break;
		}
	}

	return res;
}

int main() {
	int line_count = 0;  //记录一行已经输出的质数个数
	int num = 1;         //记录1~20000的数

	//计算输出
	for (num; num <= 20000; num++) {
		if (is_prime_num(num)) {
			cout << num << " ";
			line_count++;
		}
		if (line_count == 10) {
			cout << endl;
			line_count = 0;
		}
	}

	return 0;
}