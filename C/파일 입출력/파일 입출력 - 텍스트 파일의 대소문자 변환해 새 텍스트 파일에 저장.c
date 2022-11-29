#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	char s1[10], s2[10];
	FILE* fp;
	fp = fopen("test1.txt", "r");
	if (fp == NULL) {
		printf("Couldn't open file");
		return -1;
	}	
	while (!feof(fp)) {
		fgets(s1, 10, fp);
	}
	fclose(fp);
	for (int i = 0; i < 10; i++) {
		if (s1[i] >= 'a' && s1[i] <= 'z')
			s2[i] = s1[i] - 32;
		else if (s1[i] >= 'A' && s1[i] <= 'Z')
			s2[i] = s1[i] + 32;
	}
	s2[9] = '\0';
	fp = fopen("test2.txt", "w");
	if (fp == NULL) {
		printf("Couldn't open file");
		return -1;
	}	
	fputs(s2, fp);
	fclose(fp);
	return 0;
}
