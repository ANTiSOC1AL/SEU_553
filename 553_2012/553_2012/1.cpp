/*
��д��������С��������
*/
#include<iostream>
using namespace std;

//Ѱ����С������
int findMinMultiple(int a, int b) {
	int minMulti = a > b ? a : b;
	while (minMulti % a != 0 || minMulti % b != 0) {
		minMulti++;
	}
	return minMulti;
}

//Ѱ�����Լ��
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
