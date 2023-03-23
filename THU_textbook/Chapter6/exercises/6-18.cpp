#include<iostream>
using namespace std;

//没有释放堆区空间导致内存泄漏
int fun() {
    int *p = new int(5);
    return *p;
}

int main() {
    int a = fun();
    cout << "a = " << a << endl;
    return 0;
}