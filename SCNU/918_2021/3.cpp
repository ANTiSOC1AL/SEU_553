/*
定义一个复数类CComplex
定义一个两个参数的构造函数（其中一个有默认值）
定义显示函数show()
使用成员函数重载+
*/

#include<iostream>
using namespace std;

class CComplex {
private:
    double real;       //实数部分
    double unreliable; //虚数部分

public:
    CComplex(double real, double unreliable = 0):real(real), unreliable(unreliable) {}
    CComplex() {}

    void show() {
        if(unreliable > 0)
            cout << real << "+" << unreliable << "i" << endl;
        else if(unreliable == 0)
            cout << real << endl;
        else
            cout << real << unreliable << "i" << endl;
    }

    CComplex operator+(const CComplex cc) {
        CComplex c;
        c.real = this->real + cc.real;
        c.unreliable = this->unreliable + cc.unreliable;
        return c;
    }
};

int main() {
    CComplex c1(1, 3);
    CComplex c2(2, -1);

    CComplex c3 = c1 + c2;
    c3.show();

    return 0;
}