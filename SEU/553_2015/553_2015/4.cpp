/*
��дFindRepStr()�������˺�������Ϊ�����ַ���str�в���Ŀ���ַ���findStr, ����replaceStr���滻���������滻����ַ���str������ԭ�����£�
void findRepStr(char str[], const char findStr[], const char replaceStr[]);
*/
#include<iostream>
using namespace std;

void printStr(const char* str) {
	for (int i = 0; i < strlen(str); i++)
		cout << str[i];
	cout << endl;
}

//Ҫ�����е�findStr���滻������Ѱ���Ӵ��ٷ�װ��һ���������ɣ�ѭ������ֱ��ȫ���Ӵ���������
void findRepStr(char str[], const char findStr[], const char replaceStr[]) {
	int pos = 0;
	bool is_found = false;
	int len = 0;

	//Ѱ�ҵ�һ���Ӵ�
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
	is_found == true ? cout << "�ɹ�Ѱ�ҵ��Ӵ�" << findStr << "����ʼλ��Ϊ" << pos << endl : cout << "�������Ӵ�" << findStr << endl;

	//�滻
	size_t min, max;
	size_t i, j;
	strlen(findStr) < strlen(replaceStr) ? min = strlen(findStr), max = strlen(replaceStr) : min = strlen(replaceStr), max = strlen(findStr);
	size_t newStrLen = strlen(str) + 3 - min + max;
	cout << "newStrLen = " << newStrLen << endl;
	char* newStr = new char[newStrLen]();

	//ǰ���
	for (i = 0; i < pos; i++)
		newStr[i] = str[i];

	//�м�Ҫ�滻�Ĵ�
	for (i = pos, j = 0; j < strlen(replaceStr); i++, j++)
		newStr[i] = replaceStr[j];

	//���һ����
	for (i, j = pos + strlen(findStr); j < strlen(str); i++, j++) {
		newStr[i] = str[j];
	}
	cout << "i = " << i << endl;
	newStr[i] = '\0';            //��ʾ�ڴ�����������Ҹо�û����

	printStr(newStr);
	delete[] newStr;  //�ͷŵ�
}

int main() {
	char str[] = "hello"; //pos = 8
	char findStr[] = "hello";
	char replaceStr[] = "nihaoa";

	findRepStr(str, findStr, replaceStr);

	return 0;
}