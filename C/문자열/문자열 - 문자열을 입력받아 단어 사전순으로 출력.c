#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>


int main() {
	char x[101] = { 0 }, y[50][101] = { 0 }, tmp[101] = { 0 }, * p, * q;
	int inx = 0;
	gets(x);
	q = x;
	for (p = x; ; p++) {
		if (*p == ' ') {
			*p = '\0';
			strcpy(y[inx], q);
			inx++;
			q = p + 1;
		}
		else if (*p == '\0') {
			strcpy(y[inx], q);
			inx++;
			break;
		}
	}
	for (int i = 0; i < inx - 1; i++) {
		for (int j = 0; j < inx - 1; j++) {
			if (strcmp(y[j], y[j + 1]) > 0) {
				strcpy(tmp, y[j]);
				strcpy(y[j], y[j + 1]);
				strcpy(y[j + 1], tmp);
			}
		}
	}
	for (int i=0; i<inx; i++)
		printf("%s\n", y[i]);
	return 0;
}
