#include<iostream>
using namespace std;

int func() {
	int i, j, k, num;
	num = 0;
	for (int i = 1; i <= 9; i++) { //��λ��������0
		for (int j = 0; j <= 9; j++) {
			if (i == j) //ȷ����λ����ʮλ�������
				continue;
			for (int k = 0; k <= 9; k++) {
				if ((j != k) && (i != k)) { //��֤��λ����ʮλ���͸�λ���������
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