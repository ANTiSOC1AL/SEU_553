/*
��д���򣬶��뼸���ı�������ӡһ�������ʾÿ����ͬ�������ı��г��ֵĴ�����
*/
#include <iostream>
#include <map>
#include <string>
#include<fstream>

using namespace std;
constexpr int MAX = 100;

void to_lower(char* str);

//��ӡmap����
void printMap(const map<string, int>& m) {
    for (map<string, int>::const_iterator it = m.begin(); it != m.end(); it++)
        cout << it->first << ": " << it->second << endl;
}

//��ͬһ���ַ����еĵ��ʽ��м���
void countWords(char line[], map<string, int>& m) {
    map<string, int>::iterator it;
    char* str = line;
    char* word = strtok(str, " ");
    to_lower(word);                //ȫ��תΪСд����ֹ���ڴ�Сд���¼���ͬ

    //������������
    while (word != nullptr) {
        //���ַ��Ǳ����Ŷ����ǵ���
        if (ispunct(word[0])) {    
            word = strtok(nullptr, " ");
            continue;
        }

        //�ǵ���
        it = m.find(word);
        if (it != m.end()) { //�ҵ�Ԫ��
            it->second++;
        }
        else {               //û�ҵ�Ԫ��
            m.insert(make_pair(word, 1));
        }
        word = strtok(nullptr, " ");
        to_lower(word);
    }
}

void to_lower(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') { //�Ǵ�д��ĸ
            str[i] += 32;
        }
    }
}

int main() {
    map<string, int> m;
    ifstream in;
    char line[MAX] = { '\0' };

    //���ļ�
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