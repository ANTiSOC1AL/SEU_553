/*
����ĳ���Ĺ����ǱȽ������ַ����Ƿ���ȣ�����ȷ��� 1�����򷵻� 0������ɳ���
*/
#include<iostream>
using namespace std;

//��ChatGPT�����Ĵ������һ����2����ֱ���Ż���*p == *q
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