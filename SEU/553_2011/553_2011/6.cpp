/*
定义一个具有多态性的基类Shape，派生出三个类：
圆 Circle 类(圆心坐标和半径)，矩形 Rec 类(对角线两点不同坐标)，三角形 Tri 类(三个不同坐标)，每个类中至少有一个计算面积的函数。
编写程序，从文件 [file.txt](6/file.txt) 中读取数据来创建各类的对象，并放在 Shape 指针向量中，最后循环处理每个对象并输出面积。
*/

#include"Circle.h"
#include"Rec.h"
#include"Tri.h"
using namespace std;

int main() {
	//初始化shape*向量
	vector<Shape*>shape;
	
	//读取文件
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
	
	//处理数据
	for (int i = 0; i < shape.size(); i++)
		cout << "Area = " << setprecision(15) << shape[i]->calArea() << endl;

	return 0;
}