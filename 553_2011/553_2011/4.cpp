/*
��д��������SortOne��SortTwo�ֱ���ַ�������ʵ�ֲ��������ѡ������
*/

#include<iostream>
#include<string>
using namespace std;

//���
void printString(const string &str) {
	for (int i = 0; i < str.length(); i++)
		cout << str[i];
	cout << endl;
}

//��������
void SortOne(string &str) {
	for (int i = 1; i < str.length(); i++) {
		char temp = str[i];
		int j = i - 1;
		while (j >= 0 && str[j] > temp) {
			str[j + 1] = str[j];          //����Ҫ�����λ�ã�����λ��Ԫ������ƶ�
			j--;
		}
		str[j + 1] = temp;
	}
}

//ѡ������
void SortTwo(string &str) {
	for (int i = 0; i < str.length(); i++) {
		int pos = i;
		for (int j = i; j < str.length(); j++) {
			if (str[j] < str[pos]) {
				pos = j;
			}
		}
		char temp = str[i];
		str[i] = str[pos];
		str[pos] = temp;
	}
}

int main() {
	string str = "helloworld";
	string debut = str;
	printString(str);

	cout << "------After SortOne()------" << endl;
	SortOne(str);
	printString(str);

	cout << "------After SortTwo()------" << endl;
	SortTwo(debut);
	printString(debut);

	return 0;
}