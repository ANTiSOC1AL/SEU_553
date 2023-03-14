#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
//�������� n ��ʮ������ת���ɶ�����д���ļ���n ������õ��ģ����������������n��ʮ��������Ȼ���ٽ���ת����

int* transfer(int* arr, int n) {
	int* newArr = new int[n];
	for (int i = 0; i < n; i++)
		newArr[i] = 0;

	for (int i = 0; i < n; i++) { //����ÿһ����
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

	//��ʼ��
	srand(time(0));
	int n = rand() % 100 + 1;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 200 + 1;

	//���ת��ǰ������
	cout << "Before transfering:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	int* newArr = transfer(arr, n);

	//���ת���������
	cout << "After tranfering:\n";
	for (int i = 0; i < n; i++)
		cout << newArr[i] << " ";
	cout << endl;

	//������ļ�
	ofstream outFile;
	outFile.open("output.txt", ios::out | ios::trunc); //�ض�ģʽд�������Ķ���֮ǰ���ɵ�����
	for (int i = 0; i < n; i++)
		outFile << newArr[i] << endl;
	outFile << endl;

	return 0;
}