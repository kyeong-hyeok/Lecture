#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct player {
	char name[10]; int at; int st;
}pl;

int main() {
	int n, cnt=0, p1, p2;
	char s1[10], s2[10];
	pl p[10], tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s %d %d", p[i].name, &p[i].at, &p[i].st);
	while (cnt != 5) {
		scanf("%s %s", s1, s2);
		for (int i = 0; i < n; i++) {
			if (strcmp(p[i].name, s1) == 0)
				p1 = i;
			else if (strcmp(p[i].name, s2) == 0)
				p2 = i;
		}
		p[p1].st -= p[p2].at;
		p[p2].st -= p[p1].at;
		if (p[p1].st < 0) p[p1].st = 0;
		if (p[p2].st < 0) p[p2].st = 0;
		if (p[p2].st == 0 || p[p1].st == 0) break;
		cnt++;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (p[j].st < p[j + 1].st) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%s %d\n", p[i].name, p[i].st);
	return 0;
}
