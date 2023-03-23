/*
编写一个递归函数模板，从一个数组中找出最小值，并返回该值的数组下标元素。
*/
#include<iostream>
using namespace std;

template<typename T>
void find_min(T* arr, T& min, int& index, int& pos, const int& len) {
	if (index >= len) return;
	if (arr[index] < min) {
		min = arr[index];
		pos = index;
	}
	find_min(arr, min, ++index, pos, len);
}

int main() {
	int arr[] = { 4,2,1,4,5 };
	int min = arr[0], pos = 0, index = 0;
	int len = 5;

	find_min(arr, min, index, pos, len);
	cout << "min = " << min << ", index = " << index << endl;
	return 0;
}