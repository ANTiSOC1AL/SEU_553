/*
дһ������ģ�������һ�����������н��ж��ֲ��ҵĹ��ܣ�����ʹ�õݹ�ʵ�֡�
*/
#include<iostream>
using namespace std;

template<typename T>
int binary_search(T* arr, int& low, int& high, const T& elem) {
	if (low > high) return -1;

	int mid = (low + high) / 2;
	if (arr[mid] == elem) return mid;
	else if (arr[mid] < elem) {
		low = mid + 1;
		binary_search(arr, low, high, elem);
	}
	else {
		high = mid - 1;
		binary_search(arr, low, high, elem);
	}
}

int main() {
	int a[] = { 1,3,5,6,7,8,10 };
	int low = 0, high = 6;

	cout << binary_search(a, low, high, 4) << endl;
	return 0;
}