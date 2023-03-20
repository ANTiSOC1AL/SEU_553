/*
�������������rand���������ȳ�ʼ��һ��3��4�е����飨������Ԫ�صķ�Χ��[1, 9])
Ȼ���жϸ��������Ƿ��а��㣨���Ƿ���ڼ��������������������С��Ԫ�أ���
*/
#include<iostream>
#include<ctime>
using namespace std;

void print_matrix(int A[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			cout << A[i][j] << '\t';
		cout << endl;
	}
}

//Ѱ��A�ĵ�row�е����ֵ
int find_max(int A[3][4], const int row, int& col) {
	int j = 0, max = A[row][j];
	for (; j < 4; j++) {
		if (A[row][j] > max) {
			max = A[row][j];
			col = j;
		}
	}
	return max;
}

//Ѱ��B�ĵ�col�е���Сֵ
int find_min(int A[3][4], const int& col) {
	int min = A[0][col];
	for(int i = 0; i < 3; i++) 
		if (A[i][col] < min) {
			min = A[i][col];
		}
	return min;
}
bool is_saddle_point(int A[3][4]) {
	bool res = false;
	int col = -1;
	for (int i = 0; i < 3; i++) {
		int max_in_row = find_max(A, i, col);
		int min_in_col = find_min(A, col);
		if (max_in_row == min_in_col) {
			res = true;
			break;
		}
	}
	return res;
}

int main() {
	srand((unsigned)time(nullptr));
	int A[3][4];

	//�������ȳ�ʼ��
	for (int j = 0; j < 4; j++)
		for (int i = 0; i < 3; i++)
			A[i][j] = rand() % 9 + 1;
	print_matrix(A);

	is_saddle_point(A) ? cout << "��������" << endl : cout << "����������" << endl;
	return 0;
}