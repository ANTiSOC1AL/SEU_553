/*
假设ABCD * E = DCBA，其中A,B,C,D,E分别代表不同的数字，
编程找出A,B,C,D,E分别是多少
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

// 判断num是否每位数字都不相同。v存放倒序的每位数字
bool is_different(int num, map<int, int>&m, vector<int>& v) {
    int basic = 1;
    int single;
    bool res = true;

    while(num != 0) {
        single = num % 10;
        num /= 10;
        v.push_back(single);
    }

    for (int i = 0; i < v.size(); i++) {
        if(m.find(v[i]) == m.end()) {
            m.insert(make_pair(v[i], 1));
        }
        else {
            res = false;
            break;
        }
    }

    return res;
}

// 由于v中的数字正好是倒序存储的，可以用来生成DCBA
int assemble_DCBA(const vector<int>& v) {
    int DCBA = 0;
    int basic = 1000;

    for (int i = 0; i < v.size(); i++) {
        DCBA += basic * v[i];
        basic /= 10;
    }

    return DCBA;
}

int main() {
    map<int, int> m;
    vector<int> v;

    for (int num = 1000; num < 10000; num++) {
        if(is_different(num, m, v)) { //四位数字均不相同
            int E = 0;
            int DCBA = assemble_DCBA(v);
            for (E = 0; E < 10; E++) {
                if((m.find(E) == m.end()) && (num * E == DCBA)) {
                    cout << "A = " << v[3] << ", B = " << v[2] << ", C = " << v[1] << ", D = " << v[0] << ", E = " << E << endl;
                }
            }
        }
        m.clear();
        v.clear();
    }

    cout << endl;
    return 0;
}