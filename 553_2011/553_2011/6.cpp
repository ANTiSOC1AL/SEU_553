/*
����һ�����ж�̬�ԵĻ���Shape�������������ࣺ
Բ Circle ��(Բ������Ͱ뾶)������ Rec ��(�Խ������㲻ͬ����)�������� Tri ��(������ͬ����)��ÿ������������һ����������ĺ�����
��д���򣬴��ļ� [file.txt](6/file.txt) �ж�ȡ��������������Ķ��󣬲����� Shape ָ�������У����ѭ������ÿ��������������
*/

#include"Circle.h"
#include"Rec.h"
#include"Tri.h"
using namespace std;

int main() {
	//��ʼ��shape*����
	vector<Shape*>shape;
	
	//��ȡ�ļ�
	ifstream in;
	in.open("D:\\C++Programs\\553_2011\\553_2011\\file.txt");
	if (!in.is_open()) {
		cout << "Failed to open file.txt. Program is to exit..." << endl;
		exit(0);
	}
	char line[MAX] = { '\0' };
	int flag = 1;
	while (!in.eof()) {
		switch (flag) {
			case 1: {
				shape.push_back(new Circle(in));
				break;
			}
			case 2: {
				shape.push_back(new Rec(in));
				break;
			}
			case 3: {
				Tri tri = Tri(in);
				shape.push_back(&tri);
				break;
			}
		};
		flag++;
	}
	
	//��������
	for (int i = 0; i < shape.size(); i++)
		cout << "Area = " << setprecision(15) << shape[i]->calArea() << endl;

	return 0;
}