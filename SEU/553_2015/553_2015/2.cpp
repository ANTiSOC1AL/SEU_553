/*
编写一个递归函数，其功能为：输入一个字符串，字符间都有空格，输出一个整型值。</br>
样例输入：1 x 2 y z 3 d h 4 g 5
样例输出：54321
*/
#include<iostream>
#include<string>
using namespace std;

#define MAX 100

void string2int(char* str, int len) {
	if (len < 0) return;
	if (str[len] >= '0' && str[len] <= '9')
		cout << str[len] - '0';
	len--;
	string2int(str, len);
	return;
}

int main() {
	char str[MAX] = { '\0' };
	cout << "Please input a string: ";
	cin.getline(str, 100, '\n');

	string2int(str, strlen(str) - 1);
	cout << endl;

	return 0;
}