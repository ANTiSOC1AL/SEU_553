/*
编写选择排序算法和桶排序算法。
*/
#include<iostream>
using namespace std;

void print_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//选择排序
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
桶排序，有局限，只能对偶数个元素的数组进行排序且桶只有两个
我这个的思想是把arr分成两个桶，每个桶都用上面的选择排序进行排序，然后归并起来。
比较复杂，完全没必要。chatGPT给出了一种更简单的实现方式，或者上网查询都有简单得多的算法。
*/
void bucket_sort(int* arr, int n) {
	int cnt = n / 2;   //每个桶中存放的数据个数
	
	//申请二维数组2*cnt
	int** pails = new int* [2];
	for (int i = 0; i < 2; i++) {
		pails[i] = new int[cnt];
	}

	//初始化二维数组
	int k = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < cnt; j++){
			pails[i][j] = arr[k];
			k++;
		}
	}

	//对每个子序列选择排序
	for (int i = 0; i < 2; i++)
		select_sort(pails[i], cnt);

	//合并
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

	//重新赋值
	memcpy(arr, new_arr, n * sizeof(int));

	//释放二维数组
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