/*
�뽫ѹ�����е��ı��ļ� in.dat �����ݶ��뵽���� A[3][3]�У�����ת�ú������A������д�뵽�ı��ļ� out.dat �С�����ɳ���
*/
#include<iostream>
#include<fstream>
using namespace std;

//һ������Ԫ�����Ӧλ�õ�Ԫ�ؽ���
void transposition(int A[][3]) {
	for(int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++) {
			int temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
}

int main() {
	int A[3][3];
	ifstream in;
	in.open("D:\\C++Programs\\SEU\\2008_SEU_final_exam\\2008_SEU_final_exam\\in.dat", ios::in);
	if (!in.is_open()) {
		cout << "Failed to open \"in.dat\". Program is to exit..." << endl;
		exit(1);
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			in >> A[i][j];

	transposition(A);

	ofstream out;
	out.open("D:\\C++Programs\\SEU\\2008_SEU_final_exam\\2008_SEU_final_exam\\out.txt", ios::out | ios::trunc);
	if (!out.is_open()) {
		cout << "Failed to open \"out.txt\". Program is to exit..." << endl;
		exit(1);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			out << A[i][j] << "\t";
		out << endl;
	}
	cout << "Finished!" << endl;
	return 0;
}