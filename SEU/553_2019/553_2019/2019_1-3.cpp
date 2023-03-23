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
	* ����Ϊ��2,3,3
	*		 4,3,4
	*
	* ��ȷ�𰸣�
	*		 3,3,3
	*		 5,3,6
	*
	* cout����У���ִ��func(2,3)��ִ����Ϻ�x+=1,x=3,���3,3,3����ʱx=4,y=3,d=4
	* �ٴ�ִ��func(4,3)��++d+c,d=4,c=1�������6��x=5,���5,3,6
	*/
}