#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	int n, * a, d;
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	if (a == NULL) { printf("Not Enough Memory"); return -1; }
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &d);
	a = (int*)realloc(a, (n - d) * sizeof(int));
	if (a == NULL) { printf("Not Enough Memory"); return -1; }
	for (int i = 0; i < n - d; i++)
		printf("%d\n", a[i]);
	free(a);
	return 0;
}
