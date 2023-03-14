/*
* 用递归编程，要求如下：
* ack(0, n) = n + 1
* ack(m, 0) = m + 1
* ack(m, n) = ack(m - 1, n - 1)
* 样例输入：			样例输出
* 1 2				2
* 9 3				7
* 6 4				3
* 1 49				49
* 34 41				8
*/
#include<iostream>
#include<fstream>
using namespace std;

constexpr auto MAX = 10;

//将char*字符串转换成int
int string2int(char* num) {
	int res = 0;
	int basic = 1;

	for (int i = strlen(num) - 1; i >= 0; i--) {
		res += (num[i] - '0') * basic;
		basic *= 10;
	}

	return res;
}

int ack(int m, int n) {
	if (m == 0) return n + 1;
	else if (n == 0) return m + 1;
	else return ack(m - 1, n - 1);
}

int main() {
	//样例输入的效果用控制台不太好搞，所以用一下文件输入
	ifstream in;
	in.open("D:\\C++Programs\\SEU\\553_2014\\553_2014\\input.txt");
	if (!in.is_open()) {
		cout << "Failed to open input.txt. Program is to exit..." << endl;
		exit(0);
	}

	char nums[MAX];
	char* num;       //存储分割出来的数字
	int num1, num2;
	while (in.getline(nums, MAX, '\n')) {
		//处理第一个数
		num = strtok(nums, " ");
		num1 = string2int(num);

		//处理第二个数
		num = strtok(nullptr, " ");
		num2 = string2int(num);

		cout << ack(num1, num2) << endl;
	}

	return 0;
}