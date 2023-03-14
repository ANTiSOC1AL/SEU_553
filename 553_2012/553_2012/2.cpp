/*
编写程序，计算一系列整数之和。
假定:输入的第一个整数为继续输入整数的个数。（要求每条输入语句仅读取一个整数）
*/
#include<iostream>
#include<string>
using namespace std;

int string2int(string str) {
	int basic = 1;
	int res = 0;

	for (int i = str.length() - 1; i >= 0; i--) {
		res += (str[i] - '0') * basic;
		basic *= 10;
	}

	return res;
}

void add(int& sum, const int& num) {
	sum += num;
}

int main() {
	char ch;
	string nums;
	int i = 0, count;
	cin >> count;
	ch = cin.get();
	int sum = 0;

	while (i <= count && ch != '\n') {
		if (ch == ',' || ch == '\n') {
			ch = cin.get();
			i++;
			continue;
		}
		while (ch != ',' && ch != '\n') {
			nums.push_back(ch);
			ch = cin.get();
		}
		//处理数字
		int num = string2int(nums);
		add(sum, num);
		nums.clear();
	}

	std::cout << sum << endl;

	return 0;
}