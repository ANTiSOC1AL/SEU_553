#pragma once

/*
дһ������Date��
���ݳ�Ա���ꡢ�¡��գ���Ա�������޲������캯�������������յĺ��� setDate������һ����ӡ����display��
*/
#include<iostream>
#include<string>
#include<ctime>
using namespace std;


class Date {
private:
	int year;
	int month;
	int day;

public:
	//�޲������캯��
	Date() {
		this->year = 0;
		this->month = 0;
		this->day = 0;
	}

	//���������յĺ���
	void setDate(int year, int month, int day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}

	//��ӡ����
	void display() {
		cout << year << "��" << month << "��" << day << "��" << endl;
	}

	int getYear() {
		return this->year;
	}
};
