#include<iostream>
#include<string.h>
using namespace std;

int func(char* str) {
	int d, num = 0, len;
	while (*str != '\0') {
		d = (*str) - 48;   //��char����ת��Ϊint����
		len = strlen(str);
		for (int i = 0; i < len - 1; i++) {
			d = d * 10;  //����Ȩ��100/10/1
		}
		num += d;
		len--;     //�����ƺ�û��Ҫ
		str++;     //ָ������ƶ�
	}

	return num;
}

int main(void) {
	char s[] = "199";
	cout << func(s) << endl;

	return 0;
}