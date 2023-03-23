/*
��дѡ�������㷨��Ͱ�����㷨��
*/
#include<iostream>
using namespace std;

void print_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//ѡ������
void select_sort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

/*
Ͱ�����о��ޣ�ֻ�ܶ�ż����Ԫ�ص��������������Ͱֻ������
�������˼���ǰ�arr�ֳ�����Ͱ��ÿ��Ͱ���������ѡ�������������Ȼ��鲢������
�Ƚϸ��ӣ���ȫû��Ҫ��chatGPT������һ�ָ��򵥵�ʵ�ַ�ʽ������������ѯ���м򵥵ö���㷨��
*/
void bucket_sort(int* arr, int n) {
	int cnt = n / 2;   //ÿ��Ͱ�д�ŵ����ݸ���
	
	//�����ά����2*cnt
	int** pails = new int* [2];
	for (int i = 0; i < 2; i++) {
		pails[i] = new int[cnt];
	}

	//��ʼ����ά����
	int k = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < cnt; j++){
			pails[i][j] = arr[k];
			k++;
		}
	}

	//��ÿ��������ѡ������
	for (int i = 0; i < 2; i++)
		select_sort(pails[i], cnt);

	//�ϲ�
	int* new_arr = new int[n];
	k = 0;
	memset(new_arr, 0, n);
	int i = 0, j = 0;
	while (i < cnt && j < cnt) {
		if (pails[0][i] < pails[1][j]) {
			new_arr[k] = pails[0][i];
			i++;
		}
		else {
			new_arr[k] = pails[1][j];
			j++;
		}
		k++;
	}
	if (i == cnt) {
		while (j < cnt && k < n) {
			new_arr[k] = pails[1][j];
			j++;
			k++;
		}
	}
	else 
		while (i < cnt && k < n) {
			new_arr[k] = pails[0][i];
			i++;
			k++;
		}

	//���¸�ֵ
	memcpy(arr, new_arr, n * sizeof(int));

	//�ͷŶ�ά����
	for (int i = 0; i < 2; i++)
		delete[] pails[i];
	delete[] pails;
	delete[] new_arr;
}

int main() {
	int arr1[] = { 2,1,3,4,5,9,10,3,12,11 };
	int arr2[] = { 2,1,3,4,5,9,10,3,12,11 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	cout << "Before select_sort(): "; print_arr(arr1, n);

	select_sort(arr1, n);
	cout << "After select_sort(): "; print_arr(arr1, n);

	bucket_sort(arr2, n);
	cout << "After select_sort(): "; print_arr(arr2, n);

	return 0;
}