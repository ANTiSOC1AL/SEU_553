/*
��д���򣬼���1~20000֮������������ʱҪ��ÿ��10������
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
	int line_count = 0;  //��¼һ���Ѿ��������������
	int num = 1;         //��¼1~20000����

	//�������
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