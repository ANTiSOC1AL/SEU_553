#pragma once
/*
��дһ��Teacher�࣬Ҫ���ຬ�н�ʦ��š��������Ա𡢳������¡���ְ���£��Լ����µĳ�Ա����:</br>
��1������Ĭ�ϲ����Ĺ��캯����Ĭ�ϳ�������Ϊ1900-1-1�������ƹ��캯����</br>
��2��2016�������һ��Ƹ�ã��н�ʦ��55�꣬Ů��ʦ��60�꣬���������䣬��д�������Ӧ���ݵĽ�ʦ�����ͱ�š�</br>
��3����������������Ů��ʦ��ְʱ��δ��35�꣬�����Ƹ�ã���д�������Ӧ����Ƹ�õ������������Ů��ʦ�������ͱ�š�</br>
��4����дmain����������������Ƶ��ࡣ
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
	Teacher(string no = "2000101", string name = "li", string sex = "Ů", int birth_year = 1900, int birth_month = 1, int birth_day = 1, int work_year = 2000, int work_month = 1, int work_day = 1)
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
		if (!(sex.compare("��") && (2016 - birth_year >= 55)) || !(sex.compare("Ů") && (2016 - birth_year >= 60))) printTeacher(*this);
		else return;
	}

	void keepHire() {
		if (!sex.compare("Ů") && (2016 - birth_year >= 60) && (2016 - work_year < 35)) printTeacher(*this);
		else return;
	}

};

void printTeacher(Teacher& t) {
	cout << "������" << t.getName() << "����ţ�" << t.getNo()  << endl;
}