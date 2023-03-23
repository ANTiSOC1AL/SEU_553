#include<iostream>
using namespace std;

class BaseClass {
public:
    BaseClass() {
        cout << "BaseClass::BaseClass()" << endl;
    }
    virtual ~BaseClass() {
        cout << "BaseClass::virtual ~BaseClass()" << endl;
    }
};

class DerivedClass: public BaseClass {
public:
    DerivedClass() {
        cout << "DerivedClass::DerivedClass()" << endl;
    }
    ~DerivedClass() {
        cout << "DerivedClass::~DerivedClass()" << endl;
    }
};

int main() {
    BaseClass *pb = new DerivedClass;
    delete pb;

    system("pause");
    return 0;
}
/*
解析：输出是基类构造->派生类构造->派生类析构->基类析构
如果将BaseClass的虚析构函数改成非虚析构函数，那么DerivedClass的析构函数不会被调用
不允许声明虚构造函数
*/