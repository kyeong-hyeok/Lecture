#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct Car {
	char num[5]; int hour, min, payment;
}ca;

int main() {
	int n, d, cli, m, h, size=1;
	ca* c, *p, *q, *r=NULL, tmp[5], cl[5];
	scanf("%d", &n);
	c = (ca*)malloc(size * sizeof(ca));
	if (c == NULL) { printf("NEM"); return -1; }
	q = c;
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		d = 0;
		for (p = c; p < q; p++) {
			if (strcmp(p->num, tmp) == 0) {
				d = 1;
				r = p;
				break;
			}
		}
		if (d == 0) {
			strcpy(q->num, tmp);
			scanf("%s", cl);
			cli = atoi(cl);
			q->min = cli % 100;
			q->hour = cli / 100;
			q->payment = 0;
			size++;
			c = (ca*)realloc(c, size*sizeof(ca));
			if (c == NULL) { printf("NEM"); return -1; }
			q = c+size-1;
		}
		else if (d == 1) {
			scanf("%s", cl);
			cli = atoi(cl);
			m = cli % 100;
			h = cli / 100;
			if (m < r->min) {
				h--;
				r->min = m - r->min + 60;
			}
			else
				r->min = m - r->min;
			r->hour = h - r->hour;
			r->payment = r->hour * 6000 + r->min * 100;
		}
	}
	for (p = c; p < q; p++) {
		if (p->payment != 0)
			printf("%s %d\n", p->num, p->payment);
	}
	free(c);
	return 0;
}
