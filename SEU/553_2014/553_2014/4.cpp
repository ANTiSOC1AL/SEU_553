
#include<iostream>
#include"Employee.h"
using namespace std;


int main() {
	string worker_no = "123";
	string name = "�����";
	string id = "xxx";
	Date birthday, employed_day;
	birthday.setDate(1980, 2, 14); employed_day.setDate(2022, 1, 30);
	int years_limit = 10, salary = 10000;

	Employee employee(worker_no, name, id, birthday, employed_day, years_limit, salary);

	employee.display(); cout << endl << endl;

	cout << "�ı�������ں�" << endl;
	employee.change_birthday(2000, 2, 14);
	employee.display(); cout << endl << endl;

	cout << "�ı�Ƹ�����޺�" << endl;
	employee.change_limit(20);
	employee.display(); cout << endl << endl;

	cout << "�ı���н��" << endl;
	employee.change_salary(20);
	employee.display(); cout << endl << endl;

	cout << "������Ƹ��" << endl;
	employee.con_employ(10);


	return 0;
}
