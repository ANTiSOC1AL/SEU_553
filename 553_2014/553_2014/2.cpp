/*
* 写一个char* intToStr(int a)函数，将一个整型数转换成字符串。
*/

#include<iostream>
using namespace std;

constexpr auto MAX = 10;

void printString(const char* str) {
	for (int i = 0; i < strlen(str); i++)
		cout << str[i];
	cout << endl;
}

char* intToStr(int a) {
	char strNum[MAX] = { '\0' };
	int num = 0;
	int i = 0;
	bool flag;
	a < 0 ? flag = 1 : flag = 0;  //用于对负数的处理

	//处理数字
	a = abs(a);
	while (a != 0) {
		num = a % 10;
		a /= 10;
		strNum[i] = num + '0';
		i++;
	}
	if (flag == 1) strNum[i] = '-';

	//return strNum; 错了！返回一个局部变量的地址是不允许的
	char* result = new char[strlen(strNum) + 1];
	for (int index = 0; index < strlen(strNum) + 1; index++)
		result[index] = '\0';
	
	//将strNum倒序插入result数组中
	i = strlen(strNum) - 1;
	int j = 0;
	while (j < strlen(strNum)) {
		result[j] = strNum[i];
		i--;
		j++;
	}

	return result;
}

int main() {
	int num;
	cout << "Please input a num: ";
	cin >> num;

	cout << "\nAfter transforming: ";
	char* strNum = intToStr(num);
	printString(strNum);

	delete[] strNum;
	return 0;
}