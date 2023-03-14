/*
编写两个函数SortOne和SortTwo分别对字符串数组实现插入排序和选择排序。
*/

#include<iostream>
#include<string>
using namespace std;

//输出
void printString(const string &str) {
	for (int i = 0; i < str.length(); i++)
		cout << str[i];
	cout << endl;
}

//插入排序
void SortOne(string &str) {
	for (int i = 1; i < str.length(); i++) {
		char temp = str[i];
		int j = i - 1;
		while (j >= 0 && str[j] > temp) {
			str[j + 1] = str[j];          //不是要插入的位置，将该位置元素向后移动
			j--;
		}
		str[j + 1] = temp;
	}
}

//选择排序
void SortTwo(string &str) {
	for (int i = 0; i < str.length(); i++) {
		char min = str[i];
		int pos = i;
		for (int j = i; j < str.length(); j++) {
			if (str[j] < min) {
				min = str[j];
				pos = j;
			}
		}
		char temp = str[i];
		str[i] = min;
		str[pos] = temp;
	}
}

int main() {
	string str = "helloworld";
	string debut = str;
	printString(str);

	cout << "------After SortOne()------" << endl;
	SortOne(str);
	printString(str);

	cout << "------After SortTwo()------" << endl;
	SortTwo(debut);
	printString(debut);

	return 0;
}