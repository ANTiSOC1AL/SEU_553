#include<iostream>
using namespace std;

int func(int a, int b) {
	int c = 0;
	static int d = 3;

	if (a > b) c = 1;
	if (a < b) c = -1;
	return ++d + c;
}

int main(void) {
	int x = 2, y = 3;
	for (int i = 1; i <= 2; i++) {
		cout << x << ',' << y << ',' << func(x++, y) << endl;
		x = y + 1;
	}
	return 0;
	/*
	* 我认为：2,3,3
	*		 4,3,4
	*
	* 正确答案：
	*		 3,3,3
	*		 5,3,6
	*
	* cout语句中，先执行func(2,3)，执行完毕后x+=1,x=3,输出3,3,3，此时x=4,y=3,d=4
	* 再次执行func(4,3)，++d+c,d=4,c=1，结果是6，x=5,输出5,3,6
	*/
}