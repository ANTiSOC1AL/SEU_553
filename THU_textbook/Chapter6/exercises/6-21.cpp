#include<iostream>
#include<map>
using namespace std;

void to_lower(char& s) {
    if(s >= 'A' && s <= 'Z')
        s += 32;
}

void print_map(map<char, int>& m) {
    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
        cout << it->first << ": " << it->second << endl;
}

int main() {
    map<char, int> m;
    cout << "Please input an English sentence:";
    char line[100] = {'\0'};
    cin.getline(line, 100, '\n');
    string sentence(line);

    for (int i = 0; i < sentence.size(); i++)
    {
        to_lower(sentence[i]);
        if(sentence[i] >= 'a' && sentence[i] <= 'z') {
            map<char, int>::iterator it = m.find(sentence[i]);
            if(it != m.end())
                it->second++;
            else
                m.insert(make_pair(sentence[i], 1));
        }
    }

    cout << endl;
    print_map(m);
    system("pause");
    return 0;
}