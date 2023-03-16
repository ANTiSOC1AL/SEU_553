/*
����һ���ı������ı��е�ÿ�����ʵĳ��ȡ�</br>
�������룺This is a test string
���������This:  4
		 is:  2
		 a:  1
		 test:  4
		 string:  6
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

constexpr int MAX = 50;

void printMap(const map<string, int>& m) {
	for (map<string, int>::const_iterator it = m.begin(); it != m.end(); it++)
		cout << it->first << ":  " << it->second << endl;
}

int main() {
	char str[MAX] = { '\0' };
	map<string, int> m;
	cin.getline(str, MAX, '\n');

	char* word = strtok(str, " ");
	while (word != nullptr) {
		string strWord(word);
		map<string, int>::iterator it = m.find(strWord);
		if (it == m.end()) { //map��û�д�Ԫ��
			m.insert(make_pair(strWord, strWord.length()));
		}
		word = strtok(nullptr, " ");
	}

	printMap(m);
	return 0;
}