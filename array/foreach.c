#include <stdio.h>

typedef void (*ForeachCallback)(int data, size_t index, int arr[]);

void forEach(int arr[], size_t len, ForeachCallback callback) {
	for(int i = 0; i < len; i++) {
		callback(arr[i], i, arr);
	}
}
