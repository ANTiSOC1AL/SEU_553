/*
��д���򣬼���һϵ������֮�͡�
�ٶ�:����ĵ�һ������Ϊ�������������ĸ�������Ҫ��ÿ������������ȡһ��������
�������룺5,101,213,325,437,549
���������1625
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

	while (i <= count && ch != '\n') { //���������С�ڹ涨������δ���У�δ���������
		if (ch == ',' || ch == '\n') {
			ch = cin.get();
			i++;
			continue;
		}
		while (ch != ',' && ch != '\n') {
			nums.push_back(ch);
			ch = cin.get();
		}

		//��������
		int num = string2int(nums);
		add(sum, num);
		nums.clear();
	}

	std::cout << sum << endl;

	return 0;
}