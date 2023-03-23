/*
�ַ����Ľ������ļ��������Ƶ�һ�����ַ�����(010)(15012345678) | 123 | (430070)���������¸�ʽ���:
���� | �绰���� | ���б�� | �ʱ�
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX 50

void printChar(char* str) {
	if (str == nullptr) {
		cout << "This is null string!" << endl;
		return;
	}
	for (int i = 0; i < strlen(str); i++)
		cout << str[i];
	cout << endl;
}

void blockOutput(char* str, int start, int end) {
	for (int i = start; i < end; i++)
		cout << str[i];
}

void output(ifstream& in) {
	in.clear();
	char line[MAX] = { 0 };         //��Ҫ��char*����
	int len = 0;
	while (!in.eof()) {
		in.getline(line, MAX, '\n');
		cout << "Before analysing: ";
		printChar(line);

		cout << "After analysing: ";

		blockOutput(line, 1, 4);
		cout << " | ";
		blockOutput(line, 6, 17);
		cout << " | ";
		blockOutput(line, 19, 22);
		cout << " | ";
		blockOutput(line, 24, 29);
		cout << endl << endl;
	}
}

int main() {
	ifstream in;
	in.open("D:\\C++Programs\\553_2010\\553_2010\\info.txt", ios::in);
	if (!in.is_open()) {
		cout << "Failed to open info.txt" << endl;
		exit(0);
	}

	output(in);
	in.close();

	return 0;
}