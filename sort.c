typedef int (*Comparator)(int pre, int cur);
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

void backTrace(int arr[], size_t cur, Comparator comparator) {
	for (int i = cur - 1; i > -1; i--) {
		int preData = arr[i],
		curData = arr[i+1];
		
		if (comparator(preData, curData) < 0)
			swap(&arr[i], &arr[i+1]);
	}
}

void sort(int arr[], size_t len, Comparator comparator) {
	for (size_t cur = 0; cur < len - 1; cur++) {
		int preData = arr[cur],
		curData = arr[cur+1];
		
		if (comparator(preData, curData) >= 0) continue;
		
		swap(&arr[cur], &arr[cur+1]);
        backTrace(arr, cur, comparator);
	}
}
