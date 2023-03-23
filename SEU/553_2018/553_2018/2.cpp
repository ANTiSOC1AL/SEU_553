/*
随机生成十个10到100000的数，转成字符串并输出至文件
*/
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;

//不能返回局部变量地址
void int2string(int num, string& str_num) {
	int single;
	
	while (num != 0) {
		single = num % 10;
		num /= 10;
		str_num.push_back(single + '0');
	}

	str_num.reserve();
}

int main() {
	srand((unsigned)time(nullptr)); //种子
	int random_num = 0;
	ofstream out;
	out.open("D:\\C++Programs\\SEU\\553_2018\\553_2018\\random_strings.txt");
	if (!out.is_open()) {
		cout << "Failed to open random_strings.txt. Program is to exit..." << endl;
		exit(0);
	}

	string str_num;
	//获取随机数
	for (int i = 0; i < 10; i++) {
		random_num = (rand() % 99990) + 10;
		int2string(random_num, str_num);
		out << str_num << " ";
		str_num.clear();
	}
	out << endl;
	cout << "Random string numbers has been written to random_strings.txt" << endl;

	return 0;
}