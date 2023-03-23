#include<iostream>
using namespace std;

class Point{
    friend Point operator+(const Point &p1, const Point &p2);

private:
    int x;
    int y;

public:
    Point(int x, int y):x(x),y(y) {}
    Point() {}

    void print_point() {
        cout << this->x << ", " << this->y << endl;
    }
};

// 不要用Point&作为返回值
Point operator+(const Point& p1, const Point& p2) {
    Point p;
    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;
    return p;
}

int main() {
    Point p1(1, 3);
    Point p2(2, 1);

    Point p3 = p1 + p2;
    p3.print_point();

    system("pause");
    return 0;
}