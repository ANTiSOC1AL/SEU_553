/*
��ʽת������һ���ļ��ж�ȡһ�����ڣ�ת������Ӧ��ʽ�����
�������룺07/21/2016
���������July 21,2016
*/
#include<iostream>
#include<fstream>
#include<map>
#include<string>
using namespace std;

constexpr int MAX = 50;

int main() {
	ifstream in;
	in.open("D:\\C++Programs\\SEU\\553_2017\\553_2017\\date.txt");
	if (!in.is_open()) {
		cout << "Failed to open date.txt. Program is to exit..." << endl;
		exit(1);
	}

	//��map��0xת����Ӣ��
	map<string, string> m;
	m.insert(make_pair("01", "Jan"));
	m.insert(make_pair("02", "Feb"));
	m.insert(make_pair("03", "Mar"));
	m.insert(make_pair("04", "Apr"));
	m.insert(make_pair("05", "May"));
	m.insert(make_pair("06", "Jun"));
	m.insert(make_pair("07", "July"));
	m.insert(make_pair("08", "Aug"));
	m.insert(make_pair("09", "Sep"));
	m.insert(make_pair("10", "Oct"));
	m.insert(make_pair("11", "Nov"));
	m.insert(make_pair("12", "Dec"));

	//��������
	char date[MAX] = { '\0' };
	while (in.getline(date, MAX, '\n')) {
		char* split = strtok(date, "/");
		map<string, string>::iterator it = m.find(string(split));
		cout << it->second << " ";
		split = strtok(nullptr, "/");
		cout << split << ",";
		split = strtok(nullptr, "/");
		cout << split << endl;
	}

	return 0;
}