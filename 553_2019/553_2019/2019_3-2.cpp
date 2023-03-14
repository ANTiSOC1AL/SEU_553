/*
用函数模板求数组元素最小值的下标，若找不到返回-1， 要求使用递归
*/
#include<iostream>
using namespace std;

template<typename ElemType, typename SubType>
void findMinSub(ElemType arr[], SubType& i, ElemType& min, SubType& minSub, SubType& len) {
	if (i >= len) return;
	if (arr[i] <= min) {
		minSub = i;
		min = arr[i];
		findMinSub(arr, ++i, min, minSub, len);
	}
	else findMinSub(arr, ++i, min, minSub, len);
}

int main() {
	char arr[] = { '9', '2', '3', '3' };
	int len = sizeof(arr) / sizeof(arr[0]);
	int minSub = -1;
	int i = 0;
	findMinSub<char, int>(arr, i, arr[0], minSub, len);
	cout << "最小元素的下标是" << minSub << endl;
}