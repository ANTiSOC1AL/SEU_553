#include<iostream>
using namespace std;

class Shape{
public:
    virtual double getArea() = 0;
    virtual double getPerim() = 0;
};

class Rectangle:public Shape{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) {
        this->length = length;
        this->width = width;
    }

    double getArea() {
        return length * width;
    }
    double getPerim() {
        return 2 * (length + width);
    }
};

class Circle:public Shape{
private:
    double radius;

public:
    Circle(double radius) {
        this->radius = radius;
    }

    double getArea() {
        return 3.14 * radius * radius;
    }
    double getPerim() {
        return 2 * 3.14 * radius;
    }
};

int main() {
    Shape *shape;
    Rectangle rec(1, 4);
    Circle c(2);

    shape = &rec;
    cout << "Area of a rec is " << shape->getArea() << endl;
    cout << "Perim of a rec is " << shape->getPerim() << endl << endl;

    shape = &c;
    cout << "Area of a circle is " << shape->getArea() << endl;
    cout << "Perim of a circle is " << shape->getPerim() << endl;

    system("pause");
    return 0;
}