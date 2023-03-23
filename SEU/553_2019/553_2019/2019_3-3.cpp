#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

#define MAX 100

class selfString;
char* findLongestCommon(selfString& s1, selfString& s2);
void printString(const char* str);

class selfString {
	friend char* findLongestCommon(selfString& s1, selfString& s2);
private:
	char* dataStr;
	int Length;
public:
	selfString() {
		dataStr = nullptr;
		Length = 0;
		//cout << "无参构造函数..." << endl;
	}
	selfString(ifstream &in) {
		//cout << "有参构造函数..." << endl;
		char str[MAX] = { 0 };
		int length = 0;
		while ((str[length] = in.get()) != EOF) {
			if (length < MAX && str[length] != '\n' && str[length] != '\0')
				length++;
		}
		str[length] = '\0';
		this->dataStr = new char[length + 1]();
		strcpy(this->dataStr, str);
		this->Length = length;
		/*cout << "this->dataStr: ";
		printString(this->dataStr);*/
	}

	~selfString() {
		//cout << "析构函数..." << endl;
	}
};

char* findLongestCommon(selfString &s1, selfString &s2) {
	char* words1[MAX] = { 0 }, *words2[MAX] = { 0 };
	int count1 = 0, count2 = 0;
	char* p = nullptr;
	char* commonWord = nullptr;
	int maxLen = 0;

	//将句子分割为多个单词
	p = strtok(s1.dataStr, " ");
	while (p != nullptr) {
		words1[count1++] = p;
		p = strtok(nullptr, " ");
	}

	p = strtok(s2.dataStr, " ");
	while (p != nullptr) {
		words2[count2++] = p;
		p = strtok(nullptr, " ");
	}

	//嵌套循环比较
	for (int i = 0; i < count1; i++) {
		for (int j = 0; j < count2; j++) {
			if (strcmp(words1[i], words2[j]) == 0 && strlen(words1[i]) > maxLen) {
				commonWord = words1[i];
				maxLen = strlen(words1[i]);
			}
		}
	}

	return commonWord;
}

void printString(const char* str) {
	for (int i = 0; i < strlen(str); i++)
		cout << str[i];
	cout << endl;
	return;
}

int main() {
	ifstream in1;
	in1.open("D:\\C++Programs\\553_2019\\553_2019\\sentence1.txt");
	if (!in1.is_open()) {
		cout << "failed to open sentence1.txt" << endl;
		exit(0);
	}
	selfString str1(in1);
	in1.close();

	ifstream in2;
	in2.open("D:\\C++Programs\\553_2019\\553_2019\\sentence2.txt");
	if (!in2.is_open()) {
		cout << "failed to open sentence2.txt" << endl;
		exit(0);
	}
	selfString str2(in2);
	in1.close();

	char* commonWord = findLongestCommon(str1, str2);
	if (commonWord == nullptr)
		cout << "There is no common word" << endl;
	else {
		cout << "Longest common word is ";
		printString(commonWord);
	}
		
	return 0;
}