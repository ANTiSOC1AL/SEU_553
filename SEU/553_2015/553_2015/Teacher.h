#pragma once
/*
编写一个Teacher类，要求类含有教师编号、姓名、性别、出生年月、入职年月，以及以下的成员函数:</br>
（1）带有默认参数的构造函数（默认出生年月为1900-1-1），复制构造函数。</br>
（2）2016年进行新一轮聘用，男教师满55岁，女教师满60岁，则到退休年龄，编写函数输出应退休的教师姓名和编号。</br>
（3）如果满退休年龄的女教师入职时间未满35年，则继续聘用，编写函数输出应继续聘用的满退休年龄的女教师的姓名和编号。</br>
（4）编写main函数来测试你所设计的类。
*/
#include<string>
#include<iostream>
using namespace std;

class Teacher;
void printTeacher(Teacher& t);

class Teacher {
private:
	string no;
	string name;
	string sex;
	int birth_year; int birth_month; int birth_day;
	int work_year; int work_month; int work_day;

public:
	Teacher(string no = "2000101", string name = "li", string sex = "女", int birth_year = 1900, int birth_month = 1, int birth_day = 1, int work_year = 2000, int work_month = 1, int work_day = 1)
	:no(no), name(name), sex(sex), birth_year(birth_year), birth_month(birth_month), birth_day(birth_day), work_year(work_year), work_month(work_month), work_day(work_day) { }

	Teacher(const Teacher& t) {
		this->no = t.no;
		this->name = t.name;
		this->sex = t.sex;
		this->birth_year = t.birth_year;
		this->birth_month = t.birth_month;
		this->work_year = t.work_year;
		this->work_month = t.work_month;
		this->work_day = t.work_day;
	}

	string getName() {
		return this->name;
	}
	string getNo() {
		return this->no;
	}

	void printRetire() {
		if (!(sex.compare("男") && (2016 - birth_year >= 55)) || !(sex.compare("女") && (2016 - birth_year >= 60))) printTeacher(*this);
		else return;
	}

	void keepHire() {
		if (!sex.compare("女") && (2016 - birth_year >= 60) && (2016 - work_year < 35)) printTeacher(*this);
		else return;
	}

};

void printTeacher(Teacher& t) {
	cout << "姓名：" << t.getName() << "，编号：" << t.getNo()  << endl;
}