/*
����ASCII�ַ���33~126֮����ַ�������ת��ΪASCII�롢ʮ���ơ��˽��ơ�ʮ�����ƣ����Ա�����ʽ������ļ��С�
*/
#include<iostream>
#include<fstream>
using namespace std;

constexpr auto MAX = 100;

//�������ASCII��ֵΪ33~126֮����ַ�
int main() {
	ofstream out;
	out.open("D:\\C++Programs\\SEU\\553_2013\\553_2013\\output.txt", ios::out | ios::trunc);
	if (!out.is_open()) {
		cout << "Failed to open output.txt. Program is to exit..." << endl;
		exit(1);
	}

	for (int i = 33; i <= 126; i++) {
		out << "ASCII�� " << char(i) << '\t';
		out << "Dec: " << dec << i << '\t';
		out << "Oct:" << oct << i << '\t';
		out << "Hex: " << hex << i << endl;
	}

	cout << "Results has been output into \"output.txt\"!";

	return 0;
}