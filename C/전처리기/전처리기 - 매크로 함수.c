#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

#define ABS(a) ((a)>=0? (a): (-a))
#define MAX(a,b) ((a)>(b)? (a): (b))

int main() {
	int a[6], max=0, maxabs=0;
	for (int i = 0; i < 6; i++)
		scanf("%d", &a[i]);
	maxabs = ABS(a[0]);
	for (int i = 0; i < 6; i++) {
		maxabs = MAX(ABS(max), ABS(a[i]));
		max = MAX(maxabs, ABS(a[i])) == ABS(a[i]) ? a[i] : max;
	}
	printf("%d %d", max, maxabs);
	return 0;
}
