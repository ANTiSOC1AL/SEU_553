/*
下面的程序的功能是比较两个字符串是否相等，若相等返回 1，否则返回 0。请完成程序。
*/
#include<iostream>
using namespace std;

//与ChatGPT给出的代码基本一样。2可以直接优化成*p == *q
int f(char* s1, char* s2)
{
	char* p = s1, * q = s2;
	while (/*1*/ *p == *q && *p != '\0' && *q != '\0')
	{
		q++;
		p++;
	}
	return (/*2*/ *p == *q ? 1 : 0);
}
void main(void)
{
	char s1[100], s2[100];
	cin.getline(s1, 100);
	cin.getline(s2, 100);
	cout << f(s1, s2);
}