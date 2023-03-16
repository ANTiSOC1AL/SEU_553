/*
���1000���ڵ���������ʽ�ǣ�����=����1+����2+...+����n������6=1+2+3
*/
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& factors) {
	for (int i = 0; i < factors.size(); i++)
		cout << factors[i] << " ";
	cout << endl;
}


//�ҳ�ĳ��������������
void cal_factors(int num, vector<int>& factors) {
	for (int i = 1; i < num; i++) 
		if (num % i == 0) factors.push_back(i);
}

//�ж�num�Ƿ�Ϊ����
bool is_complete(int num, vector<int>& factors) {
	int sum = 0;
	bool res = false;
	cal_factors(num, factors);

	for (int i = 0; i < factors.size(); i++)
		sum += factors[i];
	factors.clear();

	sum == num ? res = true : res = false;
	return res;
}

int main() {
	int line_cnt = 0;
	vector<int> factors;

	for (int num = 1; num <= 1000; num++) {
		if (is_complete(num, factors)) {
			cout << num << " ";
			line_cnt++;
		}
		if (line_cnt == 10) {
			cout << endl;
			line_cnt = 0;
		}
	}
	cout << endl;

	return 0;
}