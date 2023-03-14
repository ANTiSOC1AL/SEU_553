/*
编写简单的加密，解密程序。（修改）
加密时，将字母的值加一，Encrypt函数的参数为字符指针。
解密时，将字母的值减一，Decrypt函数的参数为字符指针。
*/
#include<iostream>
using namespace std;

void Encrypt(char* str) {
	for (int i = 0; i < strlen(str); i++)
		str[i]++;
}

void Decrypt(char* str) {
	for (int i = 0; i < strlen(str); i++)
		str[i]--;
}

int main() {
	char s[10] = "abc";
	cout << "Before Encrypt(): " << s << endl;

	Encrypt(s);
	cout << "After Encrypt(): " << s << endl;

	Decrypt(s);
	cout << "After Decrypt(): " << s << endl;

	return 0;
}