/*
����ASCII�ַ���33~126֮����ַ�������ת��ΪASCII�롢ʮ���ơ��˽��ơ�ʮ�����ƣ����Ա�����ʽ������ļ��С�
*/
#include<iostream>
#include<fstream>
using namespace std;

constexpr auto MAX = 100;


//�ƺ��е�������˼�ˣ�Ӧ���ǰ����е�33~126�Ķ������д���Լ������ˣ�����ûӰ�죬��΢��һ�¾����ˣ��ҾͲ�����
int main() {
	char ch[MAX];
	cout << "Please input some chars: ";
	cin >> ch;
	ofstream out;
	out.open("D:\\C++Programs\\553_2013\\553_2013\\output.txt", ios::out | ios::trunc);
	if (!out.is_open()) {
		cout << "Failed to open output.txt. Program is to exit..." << endl;
		exit(1);
	}

	for (int i = 0; i < strlen(ch); i++) {
		if (ch[i] >= 33 && ch[i] <= 126) {
			//ASICII��
			out << "ASCII: " << ch[i] << "\t";

			//ʮ����
			out << "Dec: " << dec << (int)ch[i] << "\t";

			//�˽���
			out << "Oct: " << oct << (int)ch[i] << "\t";

			//ʮ������
			out << "Hex: " << hex << (int)ch[i] << endl;
		}
	}

	cout << "Results has been output into \"output.txt\"!";

	return 0;
}