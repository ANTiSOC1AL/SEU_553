#include<iostream>
using namespace std;

class BaseClass {
public:
    virtual void fn1() {
        cout << "BaseClass::fn1()" << endl;
    }
    void fn2() {
        cout << "BaseClass::fn2()" << endl;
    }
};

class DerivedClass :public BaseClass {
public:
    void fn1() {
        cout << "DerivedClass::fn1()" << endl;
    }
    void fn2() {
        cout << "DerivedClass::fn2()" << endl;
    }
};

int main() {
    DerivedClass d;
    BaseClass *pb = &d;
    DerivedClass *pd = &d;

    cout << "pb:" << endl;
    pb->fn1(); // 由于BaseClass::fn1()是虚函数且BaseClass* pb指向d，会触发多态
    pb->fn2();

    cout << "pd:" << endl;
    pd->fn1();
    pd->fn2();

    system("pause");
    return 0;
}