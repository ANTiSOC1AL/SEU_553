/*
对于ASCII字符中33~126之间的字符，将其转换为ASCII码、十进制、八进制、十六进制，并以表格的形式输出到文件中。
*/
#include<iostream>
#include<fstream>
using namespace std;

constexpr auto MAX = 100;

//输出所有ASCII码值为33~126之间的字符
int main() {
	ofstream out;
	out.open("D:\\C++Programs\\SEU\\553_2013\\553_2013\\output.txt", ios::out | ios::trunc);
	if (!out.is_open()) {
		cout << "Failed to open output.txt. Program is to exit..." << endl;
		exit(1);
	}

	for (int i = 33; i <= 126; i++) {
		out << "ASCII： " << char(i) << '\t';
		out << "Dec: " << dec << i << '\t';
		out << "Oct:" << oct << i << '\t';
		out << "Hex: " << hex << i << endl;
	}

	cout << "Results has been output into \"output.txt\"!";

	return 0;
}