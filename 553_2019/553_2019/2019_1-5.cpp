#include<iostream>
using namespace std;

class A {
public:
	virtual void print() = 0;
};
class B :public A {
public:
	void print() {
		cout << "B::print" << endl;
	}
};
class D :public B {
public:
	void print() {
		cout << "D::print" << endl;
	}
};

int main() {
	A* p;
	B b;
	D d;
	p = &d; p->print();
	p = &b; p->print();

	return 0;
}
//Êä³ö£º D::print B::print