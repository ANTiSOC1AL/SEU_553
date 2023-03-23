/*
建立一个 str 类，完成对字符串循环左移的功能。即从第二个字符开始，以后的每个字符都依次前移一个字符，而原来的第一个字符放在串中的最后一个字符。
当要平移 m 个字符时，则要进行 m 次的循环左移。例如：“ABCD”循环左移 2 个字符后为“CDAB”。
要求如下：
(1)私有数据成员
char * w;指向待左移字符串。
int m, len; 分别用于存储循环左移的次数及字符串的长度。
(2)公有成员函数
构造函数 str(char *p, int n, int k)：初始化各数据成员。
void move()：循环左移。
void show()：输出字符串数据成员
(3)编写一个程序测试该类，使用以下测试数据：a[]=”ABCD”，左移 3 个字符。要求输出字
符串。
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