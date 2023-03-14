/*
编写程序，读入几行文本，并打印一个表格，显示每个不同单词在文本中出现的次数。
*/
#include <iostream>
#include <map>
#include <string>
#include<fstream>

using namespace std;
constexpr int MAX = 100;

void to_lower(char* str);

//打印map容器
void printMap(const map<string, int>& m) {
    for (map<string, int>::const_iterator it = m.begin(); it != m.end(); it++)
        cout << it->first << ": " << it->second << endl;
}

//对同一行字符串中的单词进行计数
void countWords(char line[], map<string, int>& m) {
    map<string, int>::iterator it;
    char* str = line;
    char* word = strtok(str, " ");
    to_lower(word);                //全部转为小写，防止由于大小写导致键不同

    //处理读入的数据
    while (word != nullptr) {
        //此字符是标点符号而不是单词
        if (ispunct(word[0])) {    
            word = strtok(nullptr, " ");
            continue;
        }

        //是单词
        it = m.find(word);
        if (it != m.end()) { //找到元素
            it->second++;
        }
        else {               //没找到元素
            m.insert(make_pair(word, 1));
        }
        word = strtok(nullptr, " ");
        to_lower(word);
    }
}

void to_lower(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') { //是大写字母
            str[i] += 32;
        }
    }
}

int main() {
    map<string, int> m;
    ifstream in;
    char line[MAX] = { '\0' };

    //打开文件
    in.open("D:\\C++Programs\\553_2012\\553_2012\\text.txt");
    if (!in.is_open()) {
        cout << "Failed to open text.txt. Program is to exit" << endl;
        exit(0);
    }

    while (in.getline(line, MAX, '\n')) {
        countWords(line, m);
    }

    printMap(m);

    return 0;
}