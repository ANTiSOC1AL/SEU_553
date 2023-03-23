#include<iostream>
using namespace std;

int main() {
    int *p;
    *p = 9;  //会引发错误，因为p没被初始化
    // int* p = new int(9);
    cout << "The value at p: " << p << endl;
    // delete p;
    return 0;
}