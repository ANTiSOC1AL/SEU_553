/*
Person�����3�����ݳ�Ա����֪:
1. Person ����� 3 �����ݳ�Ա��name��nationality �� sex����������Ա���������캯����printName ������ printNationality ������;
2. ����name����������ΪName�ࡣName ������������ݳ�Ա��first��middle��last����������Ա���������캯����printName������;
3. ����Person���Name �࣬����д�������������������нӿڡ�
*/
#include<iostream>
#include<string>
using namespace std;

class Name {
private:
	string first;
	string middle;
	string last;

public:
	Name(string first, string middle, string last) {
		this->first = first;
		this->middle = middle;
		this->last = last;
	}

	void printName() {
		cout << this->first << " " << this->middle << " " << this->last << endl;
	}
};

class Person {
private:
	Name name;
	string nationality;
	string sex;

public:
	/*Person(const Name &name, string nationality, string sex) {
		this->name = name;                  //����this->name��û�б���ʼ������˱�����������޲ι��캯����ʼ��this->name����˱���
		this->nationality = nationality;
		this->sex = sex;
	}*/
	//ʹ�ó�Ա��ʼ���б�ķ�ʽ���й��죬���������ʹ���޲ι��캯��
	Person(const Name& name, string nationality, string sex)
		:name(name), nationality(nationality), sex(sex) {}

	void printName() {
		cout << "Person::printName():";
		name.printName();
	}

	void printNationality() {
		cout << "Nationality: " << this->nationality << endl;
	}
};

int main() {
	Name name("Niko", "Coa", "James");
	Person p(name, "USA", "Male");

	name.printName();
	p.printName();
	p.printNationality();
}