#include<iostream>
using namespace std;

void func(char str[]) {
	int count = 0;
	while (*str != 0) {
		if (*str >= '0' && *str <= '9')
			count++;
		str++;
	}
	cout << count << endl;
}
int main() {
	char str[] = "abc8d0e32fg\0hi1k3";
	func(str);
	
	return 0;
}
// ½á¹ûÊÇ4