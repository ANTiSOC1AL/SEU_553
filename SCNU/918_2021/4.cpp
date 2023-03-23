/*
从键盘连续输入多行字符保存到a.txt中，并从文件中读取显示出来
*/

#include<iostream>
#include<fstream>
using namespace std;

constexpr int MAX = 100;

int main() {
    char line[MAX] = {'\0'};
    int count;
    cout << "Please input a number which represents how many lines you will input: " << endl;
    cin.getline(line, MAX, '\n');
    count = line[0] - '0';

    // 写入
    ofstream out;
    out.open("a.txt", ios::out | ios::trunc);
    if(!out.is_open()) {
        cout << "Failed to write a.txt. Program is exitting..." << endl;
        exit(0);
    }
    for (int i = 0; i < count; i++) {
        cin.getline(line, MAX, '\n');
        out << line << endl;
    }
    out.close();

    // 读取
    ifstream in;
    in.open("a.txt", ios::in);
    if(!in.is_open()) {
        cout << "Failed to read a.txt. Program is exitting..." << endl;
        exit(1);
    }
    cout << "Read from a.txt:" << endl;
    while(in.getline(line, MAX, '\n')) {
        cout << line << endl;
    }
    in.close();

    return 0;
}