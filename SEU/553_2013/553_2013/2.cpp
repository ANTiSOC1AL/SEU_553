/*
��д�򵥵ļ��ܣ����ܳ��򡣣��޸ģ�
����ʱ������ĸ��ֵ��һ��Encrypt�����Ĳ���Ϊ�ַ�ָ�롣
����ʱ������ĸ��ֵ��һ��Decrypt�����Ĳ���Ϊ�ַ�ָ�롣
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