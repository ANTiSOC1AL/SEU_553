/*
�ַ����Ľ������ļ��������Ƶ�һ�����ַ�����(010)(15012345678)|123|(430070)���������¸�ʽ���:
����|�绰����|���б��|�ʱ�
*/
#include<iostream>
#include<fstream>
#define MAX 50
using namespace std;

//�Ż���һ�£�ʹ��strtok()��������̶���ʽ���
void display(ifstream& in) {
	char* words;
	char line[MAX] = { '\0' };
	while (in.getline(line, MAX, '\n')) {
		words = strtok(line, "()");
		cout << words << " | ";
		words = strtok(nullptr, "()");
		cout << words << " | ";
		words = strtok(nullptr, "|");
		cout << words << " | ";
		words = strtok(nullptr, "()");
		cout << words << endl;
	}

	return;
}

int main() {
	ifstream in;
	in.open("D:\\C++Programs\\553_2010\\553_2010\\info.txt");
	if (!in.is_open()) {
		cout << "Failed to open info.txt. The program is to exit" << endl;
		exit(0);
	}

	display(in);
	return 0;
}