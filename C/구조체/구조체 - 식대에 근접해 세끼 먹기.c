#include<stdio.h>
#pragma warning(disable:4996)

typedef struct rest {
	char name[100]; int breakfast; int lunch; int dinner;
}re;

int main() {
	int n, m, m1=0, best, dif;
	re r[10];
	char b1, b2, b3;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s %d %d %d", r[i].name, &r[i].breakfast, &r[i].lunch, &r[i].dinner);
	scanf("%d", &m);
	best = m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			for (int k = 0; k < n; k++) {
				if (k != i && k != j) m1 = r[i].breakfast + r[j].lunch+ r[k].dinner;
				else continue;
				dif = m - m1;
				if (dif>=0 && dif < best) {
					best = dif;
					b1 = i, b2 = j, b3 = k;
				}
			}
		}
	}
	printf("%s\n", r[b1].name);
	printf("%s\n", r[b2].name);
	printf("%s\n", r[b3].name);
	printf("%d", m - best);
	return 0;
}
