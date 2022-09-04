#include<stdio.h>
#pragma warning(disable:4996)

void ABC(int* x, int k);

int main() {
	int a[10], * p;
	for (p = a; p < a + 10; p++)
		scanf("%d", p);
	for (int i = 10, j=0; i >= 2; i--, j++)
		ABC(a+j, i);
	for (p = a; p < a + 10; p++)
		printf(" %d", *p);
	return 0;
}

void ABC(int* x, int k) {
	int* p, max = *x, i = 0, maxi = 0, tmp;
	for (p = x; p < x + k; p++) {
		if (*p > max) {
			max = *p;
			maxi = i;
		}
		i++;
	}
	tmp = *x;
	*x = *(x + maxi);
	*(x + maxi) = tmp;
}
