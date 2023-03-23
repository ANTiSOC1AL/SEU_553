#include<iostream>
using namespace std;

int func() {
	int i, j, k, num;
	num = 0;
	for (int i = 1; i <= 9; i++) { //百位数不能是0
		for (int j = 0; j <= 9; j++) {
			if (i == j) //确保百位数和十位数不相等
				continue;
			for (int k = 0; k <= 9; k++) {
				if ((j != k) && (i != k)) { //保证百位数与十位数和个位数都不相等
					// cout << i << j << k << endl;
					num++;
				}

			}
		}
	}
	return num;
}

int main() {
	int num = func();
	cout << num << endl;
	return 0;
}