#pragma once
/*
дһ��Ա��Employee��
���ݳ�Ա�й��š����������֤�š��������ڡ���Ƹ���ڡ� Ƹ�����ޡ���н��
��Ա�����й��캯�����ı�������ں������ı�Ƹ�����޺������ı���н��������Ƹ���� (Ҫ����Ƹ���������� 60 ʱ����ʾ������Ƹ)��
*/

#include "Date.h"
using namespace std;

class Employee {
private:
	string worker_no;  //����
	string name;
	string id;         //���֤��
	Date birthday;
	Date employed_day; //��Ƹ����
	int years_limit;   //Ƹ������
	int salary;

public:
	//���캯��
	Employee(string worker_no, string name, string id, Date& birthday, Date& employed_day, int years_limit, int salary)
		:worker_no(worker_no), name(name), id(id), birthday(birthday), employed_day(employed_day), years_limit(years_limit), salary(salary) {}

	//�ı�������ں���
	void change_birthday(int year, int month, int day) {
		this->birthday.setDate(year, month, day);
	}

	//�ı�Ƹ�����޺���
	void change_limit(int new_limit) {
		this->years_limit = new_limit;
	}

	//�ı���н����
	void change_salary(int new_salary) {
		this->salary = new_salary;
	}

	//��Ƹ����(Ҫ����Ƹ���������� 60 ʱ����ʾ������Ƹ)
	void con_employ(int new_limit) {
		//��ȡ��ǰ���
		time_t t = time(nullptr);
		struct tm* now = localtime(&t);

		int now_age = now->tm_year + 1900 - birthday.getYear(); //���ڵ�����
		if (now_age + new_limit + years_limit > 60) {
			cout << "��ǰ����Ϊ" << now_age << ", ��Ƹ���������60�� �޷���Ƹ��" << endl;
			return;
		}
		else {
			years_limit = new_limit;
			cout << "��Ƹ�ɹ�����Ƹ��" << years_limit << "�ꡣ" << endl;
		}
		
	}

	void display() {
		cout << "������" << name << endl;
		cout << "���ţ�" << worker_no << endl;
		cout << "���֤�ţ�" << id << endl;
		cout << "���գ�"; birthday.display();
		cout << "��Ƹ���ڣ�"; employed_day.display();
		cout << "Ƹ�����ޣ�" << years_limit << endl;
		cout << "��н:" << salary << endl;
	}
};
