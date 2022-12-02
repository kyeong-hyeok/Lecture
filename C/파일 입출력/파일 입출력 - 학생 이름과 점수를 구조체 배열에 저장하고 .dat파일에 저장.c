#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct student {
	char name[10]; int grade;
};

int main() {
	FILE* fp;
	struct student s[3];
	fp = fopen("data.dat", "wb");
	if (fp == NULL) {
		printf("Couldn't open file");
		return -1;
	}
	for (int i = 0; i < 3; i++)
		scanf("%s %d", s[i].name, &s[i].grade);
	fwrite(s, sizeof(struct student), 3, fp);
	fclose(fp);
	return 0;
}
