/*
ʹ��strtok���������������µ��ַ�����ʹ���ԡ����� �绰 �ֻ��š��ĸ�ʽ�����</br>
��������:(025)87234865-987
���������025 87234865 987
*/
#include<iostream>
#include<string>
using namespace std;

constexpr auto MAX = 100;

int main() {
    char str[] = "(025)87234865-987";

    // �и������
    char* p1 = strtok(str, "()");
    // �и���绰����
    char* p2 = strtok(NULL, "-");

    // ��ʽ�����
    cout << p1 << " " << p2 << " ";

    // �и���ֻ���
    char* p3 = strtok(NULL, "");
    if (p3 != NULL) {
        cout << p3 << endl;
    }

    return 0;
}