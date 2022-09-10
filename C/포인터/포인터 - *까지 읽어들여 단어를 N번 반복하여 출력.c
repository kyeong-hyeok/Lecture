#include<stdio.h>
#pragma warning(disable:4996)

void repeat(char ar[], int N);
int length = 0;

int main() {
	char ar[100] = { 0 }, * p;
	int N;
	for (p = ar; ; p++) {
		scanf("%c", p);
		length++;
		if (*p == '*') break;
	}
	scanf("%d", &N);
	repeat(ar, N);
	for (p = ar; p < ar + length; p++)
		printf("%c", *p);
	return 0;
}

void repeat(char ar[], int N) {
	int i = length - 1, j;
	while (i < (length - 1) * N) {
		for (j = 0; j < length - 1; j++) {
			*(ar + i) = *(ar + j);
			i++;
		}
	}
	*(ar + i) = '*';
	i++;
	length = i;
}
