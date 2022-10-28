#include<stdio.h>
#pragma warning(disable:4996)

typedef struct record {
	int month; int day; int sale[20];
}rc;
int main() {
	int n, m ,d, c, count=0, md;
	rc r[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &md);
		r[i].month = md / 100;
		r[i].day = md % 100;
		for (int j = 0; ; j++) {
			scanf("%d", &r[i].sale[j]);
			if (r[i].sale[j]==0) break;
		}
	}
	scanf("%d %d %d", &m, &d, &c);
	for (int i = 0; i < n; i++) {
		if (r[i].month == m && r[i].day == d) {
			for (int j = 0; ; j++) {
				if (r[i].sale[j] == c) count++;
				if (r[i].sale[j] == 0) break;
			}
		}
	}
	printf("%d", count);
	return 0;
}
