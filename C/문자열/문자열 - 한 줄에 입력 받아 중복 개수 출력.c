#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	char str[100], w[20][100];
	int l, s=0, inx=0, cnt=0, d=0;
	gets(str);
	l = strlen(str);
	for (int i = 0; i <= l; i++) {
		if (str[i] == ' ' || i == l) {
			for (int j = s; j < i; j++)
				w[inx][j - s] = str[j];
			w[inx][i - s] = '\0';
			inx++;
			s = i + 1;
		}
	}
	for (int i = 0; i < inx; i++) {
		d = 0;
		for (int j = 0; j < i; j++) {
			if (strcmp(w[i], w[j]) == 0)
				d = 1;
		}
		cnt = 0;
		if (d == 0) {
			for (int j = 0; j < inx; j++) {
				if (strcmp(w[i], w[j]) == 0)
					cnt++;
			}
		}
		if (cnt >= 2) printf("%s %d\n", w[i], cnt);
	}
	return 0;
}
