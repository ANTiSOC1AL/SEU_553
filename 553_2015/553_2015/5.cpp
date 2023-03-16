/*
编写一个Teacher类，要求类含有教师编号、姓名、性别、出生年月、入职年月，以及以下的成员函数:</br>
（1）带有默认参数的构造函数（默认出生年月为1900-1-1），复制构造函数。</br>
（2）2016年进行新一轮聘用，男教师满55岁，女教师满60岁，则到退休年龄，编写函数输出应退休的教师姓名和编号。</br>
（3）如果满退休年龄的女教师入职时间未满35年，则继续聘用，编写函数输出应继续聘用的满退休年龄的女教师的姓名和编号。</br>
（4）编写main函数来测试你所设计的类。
*/
#include"Teacher.h"
using namespace std;
int main() {
	Teacher teacher;
	//teacher.printRetire();
	teacher.keepHire();
	return 0;
}