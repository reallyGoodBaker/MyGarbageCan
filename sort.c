#include <stdio.h>

typedef int (*Sortable)(int pre, int cur);
typedef void (*ForeachCallback)(int data, size_t index, int arr[]);

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void forEach(int arr[], size_t len, ForeachCallback callback) {
	for(int i = 0; i < len; i++) {
		callback(arr[i], i, arr);
	}
}

void printArr(int data, size_t index, int arr[]) {
	printf("%d\n", data);
}

int backTrace(int arr[], size_t cur, Sortable comparator) {
	if (cur-1 > 0) return -1;
	for (int i = cur - 1; i; i--) {
		int preData = arr[i],
		curData = arr[i+1];
		
		if (comparator(preData, curData) < 0)
			swap(&arr[i], &arr[i+1]);
		return i;
	}
	return 0;
}

void sort(int arr[], size_t len, Sortable comparator) {
	size_t cur = 0;
	for (; cur < len - 1; cur++) {
		int preData = arr[cur],
		curData = arr[cur+1];
		
		if (comparator(preData, curData) >= 0) continue;
		
		swap(&arr[cur], &arr[cur+1]);
		int _cur = backTrace(arr, cur, comparator);
		if (!(~_cur)) {
			cur = _cur;
		}
	}
}

int comp(int pre, int cur) {
	return pre - cur;
}

int main() {
	int arr[] = {1, 1, 4, 5, 1, 4, 3 ,9, 6, 76, 3, 4};
	sort(arr, 12, comp);
	forEach(arr, 12, printArr);
	return 0;
}
