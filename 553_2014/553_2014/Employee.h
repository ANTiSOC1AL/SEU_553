#pragma once
/*
写一个员工Employee类
数据成员有工号、姓名、身份证号、出生日期、受聘日期、 聘用年限、月薪，
成员函数有构造函数、改变出生日期函数、改变聘用年限函数、改变月薪函数、续聘函数 (要求当续聘后的年龄大于 60 时给提示不能续聘)。
*/

#include "Date.h"
using namespace std;

class Employee {
private:
	string worker_no;  //工号
	string name;
	string id;         //身份证号
	Date birthday;
	Date employed_day; //受聘日期
	int years_limit;   //聘用年限
	int salary;

public:
	//构造函数
	Employee(string worker_no, string name, string id, Date& birthday, Date& employed_day, int years_limit, int salary)
		:worker_no(worker_no), name(name), id(id), birthday(birthday), employed_day(employed_day), years_limit(years_limit), salary(salary) {}

	//改变出生日期函数
	void change_birthday(int year, int month, int day) {
		this->birthday.setDate(year, month, day);
	}

	//改变聘用年限函数
	void change_limit(int new_limit) {
		this->years_limit = new_limit;
	}

	//改变月薪函数
	void change_salary(int new_salary) {
		this->salary = new_salary;
	}

	//续聘函数(要求当续聘后的年龄大于 60 时给提示不能续聘)
	void con_employ(int new_limit) {
		//获取当前年份
		time_t t = time(nullptr);
		struct tm* now = localtime(&t);

		int now_age = now->tm_year + 1900 - birthday.getYear(); //现在的年龄
		if (now_age + new_limit + years_limit > 60) {
			cout << "当前年龄为" << now_age << ", 续聘后年龄大于60， 无法续聘！" << endl;
			return;
		}
		else {
			years_limit = new_limit;
			cout << "续聘成功！续聘了" << years_limit << "年。" << endl;
		}
		
	}

	void display() {
		cout << "姓名：" << name << endl;
		cout << "工号：" << worker_no << endl;
		cout << "身份证号：" << id << endl;
		cout << "生日："; birthday.display();
		cout << "受聘日期："; employed_day.display();
		cout << "聘用年限：" << years_limit << endl;
		cout << "月薪:" << salary << endl;
	}
};
