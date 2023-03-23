/*
void reverse(string& s),用递归算法使字符串s倒序
*/
#include<iostream>
#include<string>
using namespace std;

void reverse(string& s) {
    if(s.size() == 0 || s.size() == 1)
        return;

    // 递归调用reverse()函数来翻转除去第一个字符以外的子串
    string sub = s.substr(1);
    reverse(sub);

    // 将第一个字符移到字符串末尾
    s = sub + s[0];
}

int main() {
    string s = "hello";
    reverse(s);
    cout << s << endl;

    return 0;
}