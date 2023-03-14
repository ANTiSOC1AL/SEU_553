#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
//需求：输入 n 个十进制数转换成二进制写到文件，n 是随机得到的，用随机数进行输入n个十进制数，然后再进行转换。

int* transfer(int* arr, int n) {
	int* newArr = new int[n];
	for (int i = 0; i < n; i++)
		newArr[i] = 0;

	for (int i = 0; i < n; i++) { //对于每一个数
		int basic = 1;
		int bin = 0;
		while (arr[i] != 0) {
			bin = arr[i] % 2;
			arr[i] /= 2;
			newArr[i] = newArr[i] + bin * basic;
			basic *= 10;
		}
	}

	return newArr;
}

int main() {

	//初始化
	srand(time(0));
	int n = rand() % 100 + 1;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 200 + 1;

	//输出转换前的数据
	cout << "Before transfering:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	int* newArr = transfer(arr, n);

	//输出转换后的数据
	cout << "After tranfering:\n";
	for (int i = 0; i < n; i++)
		cout << newArr[i] << " ";
	cout << endl;

	//输出到文件
	ofstream outFile;
	outFile.open("output.txt", ios::out | ios::trunc); //截断模式写，避免阅读到之前生成的数据
	for (int i = 0; i < n; i++)
		outFile << newArr[i] << endl;
	outFile << endl;

	return 0;
}