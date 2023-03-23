/*
编写FindRepStr()函数，此函数功能为，在字符串str中查找目的字符串findStr, 并用replaceStr来替换，最后输出替换后的字符串str，函数原型如下：
void findRepStr(char str[], const char findStr[], const char replaceStr[]);
*/
#include<iostream>
using namespace std;

void printStr(const char* str) {
	for (int i = 0; i < strlen(str); i++)
		cout << str[i];
	cout << endl;
}

//要把所有的findStr都替换掉，把寻找子串再封装成一个函数即可，循环调用直到全部子串都不存在
void findRepStr(char str[], const char findStr[], const char replaceStr[]) {
	int pos = 0;
	bool is_found = false;
	int len = 0;

	//寻找第一个子串
	for (int i = 0, j = 0; i < strlen(str); i++) {
		if (str[i] == findStr[j]) {
			pos = i;
			while (len < strlen(findStr)) {
				if (str[i] == findStr[j]) {
					len++;
					i++;
					j++;
				}
				else {
					i = pos + 1;
					j = 0;
					len = 0;
					break;
				}
			}
			if (len == strlen(findStr)){
				is_found = true;
				break;
			}
		}
	}
	is_found == true ? cout << "成功寻找到子串" << findStr << "，起始位置为" << pos << endl : cout << "不存在子串" << findStr << endl;

	//替换
	size_t min, max;
	size_t i, j;
	strlen(findStr) < strlen(replaceStr) ? min = strlen(findStr), max = strlen(replaceStr) : min = strlen(replaceStr), max = strlen(findStr);
	size_t newStrLen = strlen(str) + 3 - min + max;
	cout << "newStrLen = " << newStrLen << endl;
	char* newStr = new char[newStrLen]();

	//前半段
	for (i = 0; i < pos; i++)
		newStr[i] = str[i];

	//中间要替换的串
	for (i = pos, j = 0; j < strlen(replaceStr); i++, j++)
		newStr[i] = replaceStr[j];

	//最后一部分
	for (i, j = pos + strlen(findStr); j < strlen(str); i++, j++) {
		newStr[i] = str[j];
	}
	cout << "i = " << i << endl;
	newStr[i] = '\0';            //提示内存溢出，但是我感觉没问题

	printStr(newStr);
	delete[] newStr;  //释放掉
}

int main() {
	char str[] = "hello"; //pos = 8
	char findStr[] = "hello";
	char replaceStr[] = "nihaoa";

	findRepStr(str, findStr, replaceStr);

	return 0;
}