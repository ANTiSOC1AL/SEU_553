/*
汉诺塔问题
*/
#include<iostream>
using namespace std;

void move(char src, char dest) {
	cout << src << "->" << dest << endl;
}

//将n个圆盘从src以medium为中介转移到dest上
void hanoi(int n, char src, char medium, char dest) {
	if (n == 1)
		move(src, dest);
	else {
		//先将n-1个圆盘从src放在medium上
		hanoi(n - 1, src, dest, medium);
		//再将1个圆盘从src放在dest上
		move(src, dest);
		//最后将n-1个圆盘从medium放在dest上
		hanoi(n - 1, medium, src, dest);
	}
}

int main() {
	hanoi(3, 'A', 'B', 'C');
	return 0;
}