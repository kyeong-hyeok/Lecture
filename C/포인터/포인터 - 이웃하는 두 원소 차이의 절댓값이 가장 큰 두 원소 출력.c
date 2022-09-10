#include<stdio.h>
#pragma warning(disable:4996)

void input(int* ar, int N);
int* diff(int* ar, int N);

int main() {
	int N, ar[100], *max=NULL;
	scanf("%d", &N);
	input(ar, N);
	max = diff(ar, N);
	printf("%d %d\n", *max, *(max + 1));
	return 0;
}

void input(int* ar, int N) {
	int* p;
	for (p = ar; p < ar + N; p++)
		scanf("%d", p);
}

int* diff(int* ar, int N) {
	int max = 0, * p, d, * maxi = NULL;
	for (p = ar; p < ar + N - 1; p++) {
		d = *(p + 1) > *p ? *(p + 1) - *p : *p - *(p + 1);
		if (d > max) {
			maxi = p;
			max = d;
		}
	}
	return maxi;
}
