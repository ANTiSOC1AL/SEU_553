/*
如果矩阵A中存在这样的一个元素A[i, j]，满足条件：A[i, j]是第i行中最小的元素，且又是第j列中最大的元素，则称之为该矩阵的一个马鞍点，请编程计算出m*n矩阵A的所有马鞍点。
样例输入：				样例输出：
3 3						(3,3) 9
1  7  3
5  4  6
17 18 9
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;

int find_min_in_row(int* arr, int len, int& col) {
	int min = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] < min) {
			min = arr[i];
			col = i;
		}
	}
	return min;
}
int find_max_in_col(int** arr, int m, const int& col) {
	int max = arr[0][col];

	for (int i = 0; i < m; i++)
		if (arr[i][col > arr[0][col]]) max = arr[i][col];

	return max;
}

void print_saddle_points(map<string,int>& saddle_points) {
	for (map<string, int>::iterator it = saddle_points.begin(); it != saddle_points.end(); it++)
		cout << it->first << " " << it->second << endl;
}

int main() {
	int m, n;
	int col = 0;
	map<string, int> saddle_points;
	cout << "Please input: " << endl;
	cin >> m >> n;
	
	//矩阵初始化
	int** matrix = new int*[m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}
	cout << endl << endl;

	//寻找马鞍点
	for (int i = 0; i < m; i++) {
		int min_in_row = find_min_in_row(matrix[i], m, col); //col用于获取最小元素所在的列
		int max_in_col = find_max_in_col(matrix, m, col);
		if (min_in_row == max_in_col) {
			string coordinate = "(" + to_string(i + 1) + "," + to_string(col + 1) + ")";
			saddle_points.insert(make_pair(coordinate, min_in_row));
		}
	}
	print_saddle_points(saddle_points);

	//释放堆区空间
	for (int i = 0; i < m; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}