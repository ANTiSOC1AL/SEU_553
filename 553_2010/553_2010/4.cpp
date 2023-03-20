/*
���һ������ʽ�� Polynomial(�������캯�������ƹ��캯����������������ֵ������ ʵ����������ʽ���)
����Ϊ�˼����⣬���ǽ����еĶ���ʽ��ͳһ���ɣ�
p = a0 + a1 * x + a2 * x ^ 2 + a3 * x ^ 3 + ������ + an * x ^ n
*/
#include<iostream>
#include<vector>
using namespace std;

class Polynomial {
private:
	int* factors;       //����ʽÿһ���ϵ������vectorӦ�ø�����Щ
	int n;              //����ʽ����������

public:
	Polynomial(int n) {
		this->n = n;
		this->factors = new int[n];
		memset(this->factors, 0, n);
	}
	Polynomial(int *facs, int n) {        //�вι��캯��
		this->n = n;
		this->factors = new int[this->n];
		memset(this->factors, 0, n);

		for (int i = 0; i < this->n; i++) 
			this->factors[i] = facs[i];
	}

	Polynomial(const Polynomial& p) {    //�������캯��
		this->n = p.n;
		this->factors = new int[this->n]; //���
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
		Polynomial result(p.n);         //ע�ⲻ��ʹ���޲ι��죬�������
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