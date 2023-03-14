#include<iostream>
using namespace std;

int len = 0;

int* splitNum(int num) {
	int i = 8;
	int* nums = new int[9]; //最大的数是10000, 10000*10000 = 100000000，是9位数字
	memset(nums, 0, 9);

	while (num != 0) {
		nums[i] = num % 10;
		num /= 10;
		i--;
		len++;
	}

	return nums;
}
bool isIsoNum(int num) {
	int square = num * num;
	bool result = true;

	int* nums1 = splitNum(num);
	int* nums2 = splitNum(square);
	for (int i = 9; len != 0; i--) {
		if (nums1[i] != nums2[i]) {
			result = false;
			break;
		}
		len--;
	}

	return result;
}

int main() {
	int num;
	cout << "Please input a number which is in [1, 10000]: ";
	cin >> num;

	if (isIsoNum(num))
		cout << "It is a iso num" << endl;
	else
		cout << "It is not a iso num" << endl;

	return 0;
}