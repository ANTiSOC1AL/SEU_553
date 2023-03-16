/*
�������A�д���������һ��Ԫ��A[i, j]������������A[i, j]�ǵ�i������С��Ԫ�أ������ǵ�j��������Ԫ�أ����֮Ϊ�þ����һ�����㣬���̼����m*n����A���������㡣
�������룺				���������
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
	
	//�����ʼ��
	int** matrix = new int*[m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}
	cout << endl << endl;

	//Ѱ������
	for (int i = 0; i < m; i++) {
		int min_in_row = find_min_in_row(matrix[i], m, col); //col���ڻ�ȡ��СԪ�����ڵ���
		int max_in_col = find_max_in_col(matrix, m, col);
		if (min_in_row == max_in_col) {
			string coordinate = "(" + to_string(i + 1) + "," + to_string(col + 1) + ")";
			saddle_points.insert(make_pair(coordinate, min_in_row));
		}
	}
	print_saddle_points(saddle_points);

	//�ͷŶ����ռ�
	for (int i = 0; i < m; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}