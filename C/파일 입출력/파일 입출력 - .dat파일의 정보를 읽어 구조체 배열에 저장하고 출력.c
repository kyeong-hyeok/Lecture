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
	fp = fopen("data.dat", "rb");
	if (fp == NULL) {
		printf("Couldn't open file");
		return -1;
	}
	fread(s, sizeof(struct student), 3, fp);
	for (int i = 0; i < 3; i++)
		printf("%s %d\n", s[i].name, s[i].grade);
	fclose(fp);
	return 0;
}
