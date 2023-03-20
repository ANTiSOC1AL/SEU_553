/*
������(Vehicle �� Car �� SteeringWheel �� Brake ��)���ű�Ȼ����ϵ���������ʵ��
Vehicle������Ҫ���ٶȵĳ�Ա����ز�����Car�ࡢSteeringWheel���Brake ������Ҫ�в����������֡�
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
	double size;      //�����̵Ĵ�С
	string producer;  //�����̵ĳ���

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
	string producer;  //ɲ���ĳ���

public:
	Brake(string producer = "BMW") {
		this->producer = producer;
		cout << "This is a BMW brake." << endl;
	}

	~Brake() {

	}
};

//�̳�Vehicle�ְ���SteeringWheel��Brake
class Car :public Vehicle {
private:
	string brand;     //������Ʒ��
	string color;     //��������ɫ
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