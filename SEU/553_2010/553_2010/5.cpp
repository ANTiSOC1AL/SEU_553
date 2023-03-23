/*
几个类(Vehicle 类 Car 类 SteeringWheel 类 Brake 类)有着必然的联系，设计类与实现
Vehicle类中需要有速度的成员及相关操作，Car类、SteeringWheel类和Brake 类中需要有部分属性名字。
*/

#include<iostream>
#include<string>
using namespace std;

class Vehicle {
private:
	double speed;
public:
	void speedUp() {
		this->speed += 10;
		cout << "speed = " << speed << endl;
	}

	void slowDown() {
		this->speed -= 10;
		cout << "speed = " << speed << endl;
	}

	void stop() {
		this->speed = 0;
		cout << "speed = " << speed << endl;
	}

	Vehicle() {
		this->speed = 0;
		cout << "Vehicle constructor" << endl;
	}
	~Vehicle() {
		this->speed = 0;
		cout << "Vehicle destructor" << endl;
	}
};

class SteeringWheel {
private:
	double size;      //方向盘的大小
	string producer;  //方向盘的厂商

public:
	SteeringWheel(string producer = "Audi") {
		this->size = 10;
		this->producer = producer;

		cout << "This is a " << this->producer <<" steering wheel." << endl;
	}

	~SteeringWheel() {

	}
};

class Brake {
private:
	string producer;  //刹车的厂商

public:
	Brake(string producer = "BMW") {
		this->producer = producer;
		cout << "This is a BMW brake." << endl;
	}

	~Brake() {

	}
};

//继承Vehicle又包含SteeringWheel与Brake
class Car :public Vehicle {
private:
	string brand;     //汽车的品牌
	string color;     //汽车的颜色
	SteeringWheel steeringWheel;
	Brake brake;

public:
	Car() {
		cout << "Car constructor" << endl;
	}

	~Car() {
		cout << "Car destructor" << endl;
	}
};

int main() {
	Car car;

	car.speedUp();
	car.speedUp();
	car.slowDown();
	car.stop();

	return 0;
}