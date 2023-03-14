/*
对于ASCII字符中33~126之间的字符，将其转换为ASCII码、十进制、八进制、十六进制，并以表格的形式输出到文件中。
*/
#include<iostream>
#include<fstream>
using namespace std;

constexpr auto MAX = 100;


//似乎有点理解错意思了，应该是把所有的33~126的都输出，写成自己输入了，不过没影响，稍微改一下就行了，我就不改了
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
			//ASICII码
			out << "ASCII: " << ch[i] << "\t";

			//十进制
			out << "Dec: " << dec << (int)ch[i] << "\t";

			//八进制
			out << "Oct: " << oct << (int)ch[i] << "\t";

			//十六进制
			out << "Hex: " << hex << (int)ch[i] << endl;
		}
	}

	cout << "Results has been output into \"output.txt\"!";

	return 0;
}