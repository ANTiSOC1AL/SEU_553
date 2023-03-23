/*
��ŵ������
*/
#include<iostream>
using namespace std;

void move(char src, char dest) {
	cout << src << "->" << dest << endl;
}

//��n��Բ�̴�src��mediumΪ�н�ת�Ƶ�dest��
void hanoi(int n, char src, char medium, char dest) {
	if (n == 1)
		move(src, dest);
	else {
		//�Ƚ�n-1��Բ�̴�src����medium��
		hanoi(n - 1, src, dest, medium);
		//�ٽ�1��Բ�̴�src����dest��
		move(src, dest);
		//���n-1��Բ�̴�medium����dest��
		hanoi(n - 1, medium, src, dest);
	}
}

int main() {
	hanoi(3, 'A', 'B', 'C');
	return 0;
}