/*
��дһ��CPU�࣬����������Ϣ��
ʱ��Ƶ�ʣ���󲻻ᳬ��3000MHZ
�ֳ���32λ��64λ
���������ˡ�˫�˻��ĺ�
�Ƿ�֧�ֳ��߳�
Ҫ��ʹ��λ���ʾ������Ϣ
*/
#include<iostream>
using namespace std;

class CPU {
private:
	int clock : 13;
	int byte : 7;
	int cores : 3;
	bool hyper_thread : 1;

public:
	CPU() {
		clock = 3000;
		byte = 64;
		cores = 4;
		hyper_thread = 1;
	}
};

int main() {
	cout << sizeof(CPU) << endl; 
	//���8 ��Ȼʵ������5�����Ǳ�����8�ı���
	return 0;
}