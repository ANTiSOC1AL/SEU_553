/*
使用strtok函数处理类似如下的字符串，使其以“区号 电话 分机号”的格式输出。</br>
样例输入:(025)87234865-987
样例输出：025 87234865 987
*/
#include<iostream>
#include<string>
using namespace std;

constexpr auto MAX = 100;

int main() {
    char str[] = "(025)87234865-987";

    // 切割出区号
    char* p1 = strtok(str, "()");
    // 切割出电话号码
    char* p2 = strtok(NULL, "-");

    // 格式化输出
    cout << p1 << " " << p2 << " ";

    // 切割出分机号
    char* p3 = strtok(NULL, "");
    if (p3 != NULL) {
        cout << p3 << endl;
    }

    return 0;
}