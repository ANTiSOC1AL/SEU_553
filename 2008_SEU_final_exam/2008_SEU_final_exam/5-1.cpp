/*
����һ�� str �࣬��ɶ��ַ���ѭ�����ƵĹ��ܡ����ӵڶ����ַ���ʼ���Ժ��ÿ���ַ�������ǰ��һ���ַ�����ԭ���ĵ�һ���ַ����ڴ��е����һ���ַ���
��Ҫƽ�� m ���ַ�ʱ����Ҫ���� m �ε�ѭ�����ơ����磺��ABCD��ѭ������ 2 ���ַ���Ϊ��CDAB����
Ҫ�����£�
(1)˽�����ݳ�Ա
char * w;ָ��������ַ�����
int m, len; �ֱ����ڴ洢ѭ�����ƵĴ������ַ����ĳ��ȡ�
(2)���г�Ա����
���캯�� str(char *p, int n, int k)����ʼ�������ݳ�Ա��
void move()��ѭ�����ơ�
void show()������ַ������ݳ�Ա
(3)��дһ��������Ը��࣬ʹ�����²������ݣ�a[]=��ABCD�������� 3 ���ַ���Ҫ�������
������
*/
#include<iostream>
using namespace std;

class str {
private:
	char* w;
	int m, len;

public:
	str(char* p, int n, int k) {
		len = k;
		m = n;
		w = new char[len + 1];
		for (int i = 0; i < len; i++)
			w[i] = p[i];
		w[len] = '\0';
	}

	void move() {
		for (int i = 0; i < m; i++) {
			char temp = w[0];
			for (int j = 0; j < len - 1; j++)
				w[j] = w[j + 1];
			w[len - 1] = temp;
		}
	}
	void show() {
		for (int i = 0; i < len; i++)
			cout << w[i];
		cout << endl;
	}
};

int main() {
	char a[] = "ABCD";
	str s(a, 3, 4);
	cout << "Before move: "; s.show();
	s.move();
	cout << "After move: "; s.show();

	return 0;
}