#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct student {
	char *studentName;
	char id[5];
	char *subjectName;
	double subjectScore;
};
int main() {
	int n, l, inx=0, s=0, k;
	struct student *st, temp;
	char tmp[100], w[4][100];
	scanf("%d", &n);
	getchar();
	st = (struct student*)malloc(n * sizeof(struct student));
	if (st == NULL) { return -1; }
	for (int i = 0; i < n; i++) {
		gets(tmp);
		l = strlen(tmp);
		inx = 0;
		s = 0;
		for (int j = 0; j <= l; j++) {
			if (tmp[j] == ' ' || j == l) {
				for (int k = s; k < j; k++)
					w[inx][k - s] = tmp[k];
				w[inx][j - s] = '\0';
				inx++;
				s = j + 1;
			}
		}
		l = strlen(w[0]);
		st[i].studentName = (char*)malloc((l + 1) * sizeof(char));
		if (st[i].studentName == NULL) { return -1; }
		strcpy(st[i].studentName, w[0]);
		strcpy(st[i].id, w[1]);
		l = strlen(w[2]);
		st[i].subjectName = (char*)malloc((l + 1) * sizeof(char));
		if (st[i].subjectName == NULL) { return -1; }
		strcpy(st[i].subjectName, w[2]);
		st[i].subjectScore = atof(w[3]);
		
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (st[j].subjectScore < st[j + 1].subjectScore) {
				temp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = temp;
			}
		}
	}
	scanf("%d", &k);
	printf("%s %s %s %.2f", st[k - 1].studentName, st[k - 1].id, st[k - 1].subjectName, st[k - 1].subjectScore);
	for (int i = 0; i < n; i++) {
		free(st[i].studentName);
		free(st[i].subjectName);
	}
	free(st);
	return 0;
}
