#include <stdlib.h>
#include <string.h>

typedef int (*Comparator)(int pre, int cur);

void swap(void* ap, void* bp, size_t size) {
    void *mem = malloc(size);
    memcpy(mem, ap, size);
    memcpy(ap, bp, size);
    memcpy(bp, mem, size);
    free(mem);
}

void backTrace(int arr[], size_t cur, Comparator comparator) {
	for (int i = cur - 1; i > -1; i--) {
		int preData = arr[i],
		curData = arr[i+1];
		
		if (comparator(preData, curData) < 0)
			swap(&arr[i], &arr[i+1], sizeof(int));
	}
}

void sort(int arr[], size_t len, Comparator comparator) {
	for (size_t cur = 0; cur < len - 1; cur++) {
		int preData = arr[cur],
		curData = arr[cur+1];
		
		if (comparator(preData, curData) >= 0) continue;
		
		swap(&arr[cur], &arr[cur+1], sizeof(int));
        backTrace(arr, cur, comparator);
	}
}
