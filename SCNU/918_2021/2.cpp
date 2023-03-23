/*
char* itos(int n); 实现整型转字符
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

constexpr int MAX = 100;

char* itos(int n) {
    char nums[MAX] = {'\0'};
    int i = 0, j = 0;
    int single = 0;
    bool neg;
    n < 0 ? neg = 1:neg = 0;

    n = std::abs(n);
    while(n != 0) {
        single = n % 10;
        n /= 10;
        nums[i] = single + '0';
        i++;
    }
    if(neg == 1)
        nums[i] = '-';

    char *str_num = new char[strlen(nums) + 1];
    i = strlen(nums) - 1;
    for (j = 0; i >= 0; i--,j++) {
        str_num[j] = nums[i];
    }
    str_num[j] = '\0';
    return str_num;
}

int main() {
    int n = -11012;

    char *str = itos(n);
    cout << str << endl;

    delete[] str;
    return 0;
}