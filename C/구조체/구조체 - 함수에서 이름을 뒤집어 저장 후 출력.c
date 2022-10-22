#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct student {
	char name[22]; char r_name[22];
}stu;

struct student* change(struct student* st);

int main() {
	int n;
	stu st[10] = { '\0' }, * p;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
		gets(st[i].name);
	p = change(st);
	for (int i = 0; i < n; i++)
		printf("%s\n", st[i].r_name);
	printf("longest=%s", p->r_name);
	return 0;
}

struct student* change(struct student* st) {
	char c1[22], c2[22];
	int inx = 0, i, j, k=0, b=0, l, bs;
	while (strlen((st + k)->name)!=0) {
		l = strlen((st + k)->name);
		for (i = 0; i<l; i++) {
			if ((st + k)->name[i] == ' ') {
				inx = i;
				break;
			}
		}
		for (i = inx+1; i < l; i++)
			(st + k)->r_name[i - inx-1] = (st + k)->name[i];
		(st + k)->r_name[l - inx-1] = ' ';
		for (i = 0; i < inx; i++)
			(st + k)->r_name[l - inx + i] = (st + k)->name[i];
		(st + k)->r_name[l] = '\0';
		if (l > b) {
			b = l;
			bs = k;
		}
		k++;
	}
	return st+bs;
}
