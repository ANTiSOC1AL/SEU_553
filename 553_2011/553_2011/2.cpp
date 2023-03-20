/*
��дһ��������������Ĺ�ʽ����pi��ֵ��Ҫ��С������λ��Ϊ������ɱ������Χ��
PI = 4 - 4/3 + 4/5 - 4/7 +...
*/
#include<iostream>
#include<iomanip>
#include<limits>
#include<string>
using namespace std;

double calPI() {
	double res = 0;
	double temp = 1;
	int k = 1;      
	int sign = 1;
	int dividend;    //���ڵ�����ĸ
	cout << "Calculating..." << endl;

	do {
		dividend = sign * (2 * k - 1);
		temp = 4.0 / dividend;
		res += temp;
		k++;
		sign *= -1;
		cout << "res = " << setprecision(numeric_limits<double>::digits10) << res << endl;
	} while (abs(temp) > pow(10, -(numeric_limits<double>::digits10)));    //numeric_limits<double>::digits10Ϊ�˼����double�����λ��

	cout << "Finished!" << endl;
	return res;
}

int main() {
	cout.setf(ios::fixed);
	cout << "PI = " << setprecision(15) << calPI() << endl;
	return 0;
}