#include<iostream>
using namespace std;

class Abstract{
private:
    int a;
};
class Derived:public Abstract {
public:
    Derived() {
        
    }
};

int main() {
    Derived d;
    Abstract *a = &d;
}