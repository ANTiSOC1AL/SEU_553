#include<iostream>
using namespace std;

class Mammal{
public:
    // 虚函数必须有实现，类外实现不需要virtual关键字
    // 纯虚函数可以有实现，但必须在类外实现，类外实现不需要virtual关键字
    virtual void speak() {
        cout << "Mammal::speak();" << endl;
    }
};
class Dog:public Mammal {
public:
    void speak() {
        cout << "Dog::speak();" << endl;
    }
};

int main() {
    Dog d;
    d.speak();

    system("pause");
    return 0;
}