#include<iostream>
using namespace std;

class Base1{
public:
        Base1(int i) { cout << "Constructing Base1 " << i << endl; }
};
class Base2{
public:
        Base2(int i) { cout << "Constructing Base2 " << i << endl; }
};
class Base3{
public:
    Base3() { cout << "Constructing Base3 *" << endl; }
};

/*
先调用基类的构造函数，然后再调用内嵌对象的构造函数
基类构造函数的调用顺序按照派生类定义时的顺序，因此为2->1->3
内嵌对象的构造函数调用顺序按照成员在类中的声明顺序，因此为1->2->3
*/ 
class Derived:public Base2, public Base1, public Base3 {
public:
    Derived(int a, int b, int c, int d)
    :Base1(a), member2(d), member1(c), Base2(b) {}
private:
    Base1 member1;
    Base2 member2;
    Base3 member3;
};

int main() {
    Derived obj(1, 2, 3, 4);

    system("pause");
    return 0;
}