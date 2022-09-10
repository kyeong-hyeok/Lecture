#include<stdio.h>
#pragma warning(disable:4996)

void eliminate(char ar[]);
int N = 0;

int main() {
	char ar[100], * p;
	for (p = ar; ; p++) {
		scanf("%c", p);
		if (*p == '*') break;
	}
	eliminate(ar);
	for (p = ar; p < ar + N; p++)
		printf("%c", *p);
	return 0;
}

void eliminate(char ar[]) {
	char* p, * q;
	int d = 0;
	for (p = ar; ; p++) {
		d = 0;
		for (q = ar; q < p; q++) {
			if (*p == *q) d = 1;
		}
		if (d == 1) continue;
		*(ar + N) = *p;
		N++;
		if (*p == '*') break;
	}
}
