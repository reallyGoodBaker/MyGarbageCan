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

void backTrace(int arr[], size_t cur, Sortable comparator) {
	for (int i = cur - 1; i > -1; i--) {
		int preData = arr[i],
		curData = arr[i+1];
		
		if (comparator(preData, curData) < 0)
			swap(&arr[i], &arr[i+1]);
	}
}

void sort(int arr[], size_t len, Sortable comparator) {
	size_t cur = 0;
	for (; cur < len - 1; cur++) {
		int preData = arr[cur],
		curData = arr[cur+1];
		
		if (comparator(preData, curData) >= 0) continue;
		
		swap(&arr[cur], &arr[cur+1]);
        	backTrace(arr, cur, comparator);
	}
}

int comp(int pre, int cur) {
	return pre - cur;
}

int main() {
	int arr[] = {4, 1, 4, 5, 1, 4, 3 ,9, 6, 76, 3, 4, 88};
	sort(arr, 13, comp);
	forEach(arr, 13, printArr);
	return 0;
}
