/*
先用随机函数（rand）按列优先初始化一个3行4列的数组（数组中元素的范围是[1, 9])
然后判断该数组中是否有鞍点（即是否存在既是行上最大又是列上最小的元素）。
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

//寻找A的第row行的最大值
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

//寻找B的第col列的最小值
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

	//按列优先初始化
	for (int j = 0; j < 4; j++)
		for (int i = 0; i < 3; i++)
			A[i][j] = rand() % 9 + 1;
	print_matrix(A);

	is_saddle_point(A) ? cout << "存在马鞍点" << endl : cout << "不存在马鞍点" << endl;
	return 0;
}