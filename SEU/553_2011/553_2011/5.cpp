/*
�Զ�������Array��operator()���ʣ�����һ������ Array ��� chess ����ͨ��������������غ���()��ʵ�� chess(row,column)���� chess[row][column]
�����:
��1��Array ��Ļ������壬�������캯���������������������캯���ͻ������ݳ�Ա;
��2����������غ���()�Ķ��塣
*/
#include"Array.h"

int main() {
	Array chess;
	chess.printChess();
	
	int row = 0, column = 0;
	cout << "chess(row, column) = " << chess(row, column) << endl;

	return 0;
}