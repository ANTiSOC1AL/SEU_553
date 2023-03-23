/*
编写一个CPU类，描述以下信息：
时钟频率，最大不会超过3000MHZ
字长：32位或64位
核数：单核、双核或四核
是否支持超线程
要求使用位域表示各项信息
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
	//输出8 虽然实际上是5，但是必须是8的倍数
	return 0;
}