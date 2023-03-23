/*
设计一个多项式类 Polynomial(包括构造函数、复制构造函数、析构函数、赋值函数、 实现两个多项式相加)
这里为了简化问题，我们将所有的多项式都统一看成：
p = a0 + a1 * x + a2 * x ^ 2 + a3 * x ^ 3 + ……… + an * x ^ n
*/
#include<iostream>
#include<vector>
using namespace std;

class Polynomial {
private:
	int* factors;       //多项式每一项的系数，用vector应该更方便些
	int n;              //多项式的最高项次数

public:
	Polynomial(int n) {
		this->n = n;
		this->factors = new int[n];
		memset(this->factors, 0, n);
	}
	Polynomial(int *facs, int n) {        //有参构造函数
		this->n = n;
		this->factors = new int[this->n];
		memset(this->factors, 0, n);

		for (int i = 0; i < this->n; i++) 
			this->factors[i] = facs[i];
	}

	Polynomial(const Polynomial& p) {    //拷贝构造函数
		this->n = p.n;
		this->factors = new int[this->n]; //深拷贝
		for (int i = 0; i < this->n; i++) {
			this->factors[i] = p.factors[i];
		}
	}

	~Polynomial() {
		this->n = 0;
		if (this->factors != nullptr) {
			memset(this->factors, 0, n);
			delete this->factors;
			this->factors = nullptr;
		}
	}

	Polynomial operator+(const Polynomial& p) {
		Polynomial result(p.n);         //注意不能使用无参构造，会出问题
		for (int i = 0; i < this->n; i++)
			result.factors[i] = this->factors[i] + p.factors[i];

		return result;
	}

	void printPolynomial() {
		for (int i = 0; i < this->n; i++)
			cout << this->factors[i] << " ";
		cout << endl;
	}
};

int main(void) {
	int facs1[] = { 1,2,3,4,0 };
	int facs2[] = { 1,3,4,5,7 };

	Polynomial p1(facs1, 5);
	Polynomial p2(facs2, 5);

	cout << "p1 = "; p1.printPolynomial();
	cout << "p2 = "; p2.printPolynomial();

	Polynomial newP = p1 + p2;
	cout << "p1 + p2 = "; newP.printPolynomial();
	
	return 0;
}