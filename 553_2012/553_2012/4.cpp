/*
Person类包含3个数据成员，已知:
1. Person 类包含 3 个数据成员（name，nationality 和 sex）和三个成员函数（构造函数，printName 函数和 printNationality 函数）;
2. 其中name的数据类型为Name类。Name 类包含三个数据成员（first，middle和last）和两个成员函数（构造函数和printName函数）;
3. 定义Person类和Name 类，并编写程序测试这两个类的所有接口。
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
		this->name = name;                  //由于this->name并没有被初始化，因此编译器会调用无参构造函数初始化this->name，因此报错
		this->nationality = nationality;
		this->sex = sex;
	}*/
	//使用成员初始化列表的方式进行构造，避免编译器使用无参构造函数
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