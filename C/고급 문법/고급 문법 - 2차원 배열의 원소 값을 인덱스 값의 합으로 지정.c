#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

void ABC(int(*p)[20], int k1, int k2);

int main() {
	int n, arr[20][20];
	scanf("%d", &n);
	ABC(arr, n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void ABC(int(*p)[20], int k1, int k2) {
	for (int i = 0; i < k1; i++) {
		for (int j = 0; j < k2; j++) {
			(*(p + i))[j] = i + j;
		}
	}
}
