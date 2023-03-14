#include<iostream>
#include<string.h>
using namespace std;

int func(char* str) {
	int d, num = 0, len;
	while (*str != '\0') {
		d = (*str) - 48;   //将char数字转换为int数字
		len = strlen(str);
		for (int i = 0; i < len - 1; i++) {
			d = d * 10;  //乘以权重100/10/1
		}
		num += d;
		len--;     //这行似乎没必要
		str++;     //指针向后移动
	}

	return num;
}

int main(void) {
	char s[] = "199";
	cout << func(s) << endl;

	return 0;
}