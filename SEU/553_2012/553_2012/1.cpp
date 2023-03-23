/*
编写程序，求最小公倍数。
*/
#include<iostream>
using namespace std;

//寻找最小公倍数
int findMinMultiple(int a, int b) {
	int minMulti = a > b ? a : b;
	while (minMulti % a != 0 || minMulti % b != 0) {
		minMulti++;
	}
	return minMulti;
}

//寻找最大公约数
int findMaxDiv(int a, int b) {
	int maxDiv = a < b ? a : b;
	while (a % maxDiv != 0 || b % maxDiv != 0) {
		maxDiv--;
	}
	return maxDiv;
}

int main() {
	cout << "Please input two numbers: ";
	int a, b;
	cin >> a >> b;

	cout << "Their least common multiple is " << findMinMultiple(a, b) << endl;
	cout << "Their greatest common divisor is " << findMaxDiv(a, b) << endl;
	
	return 0;
}
