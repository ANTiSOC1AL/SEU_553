/*
�ַ����Ľ������ļ��������Ƶ�һ�����ַ�����(010)(15012345678)|123|(430070)���������¸�ʽ���:
����|�绰����|���б��|�ʱ�
*/
#include<iostream>
#include<fstream>
#define MAX 50
using namespace std;

void display(char* str, const int start, const int end) {
	for (int i = start; i < end; i++)
		cout << str[i];
}

int main() {
	ifstream in;
	in.open("D:\\C++Programs\\553_2010\\553_2010\\info.txt");
	if (!in.is_open()) {
		cout << "Failed to open info.txt. The program is to exit" << endl;
		exit(0);
	}

	char line[MAX] = { '\0' };
	while (!in.eof()) {
		in.getline(line, MAX, '\n');
		display(line, 1, 4);
		cout << " | ";
		display(line, 6, 17);
		cout << " | ";
		display(line, 19, 22);
		cout << " | ";
		display(line, 24, 30);
		cout << endl;
	}

	return 0;
}