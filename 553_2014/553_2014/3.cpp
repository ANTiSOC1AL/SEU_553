/*
* дһ��swap(int a[], int m, int n)�������ǰm�����n�����
*/
#include<iostream>
#include<vector>
using namespace std;

void printArray(int a[], int len) {
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void swap(int arr[], int m, int n) {
    // �Ƚ��������鷴ת
    reverseArray(arr, 0, m + n - 1);

    // �ٽ�ǰm��Ԫ�غͺ�n��Ԫ�طֱ�ת
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, n, m + n - 1);
}


int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int m = 3, n = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    swap(arr, m, n);

    cout << "Swapped array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
