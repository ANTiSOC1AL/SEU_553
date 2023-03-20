/*
字符串的解析，文件中有类似的一行行字符串“(010)(15012345678)|123|(430070)”，按以下格式输出:
区号|电话号码|城市编号|邮编
*/
#include<iostream>
#include<fstream>
#define MAX 50
using namespace std;

//优化了一下，使用strtok()函数代替固定格式输出
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