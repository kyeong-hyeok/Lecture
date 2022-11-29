#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	int cnt = 0, sum = 0, n, k;
	double avg;
	FILE* fp;
	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("Couldn't open file");
		return -1;
	}	
	while (1) {
		scanf("%d", &n);
		if (feof(stdin)) break;
		fprintf(fp, "%d\n", n);
	}
	fclose(fp);
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("Couldn't open file");
		return -1;
	}	
	while (1) {
		if (fscanf(fp, "%d\n", &k) == EOF) break;
		sum += k;
		cnt++;
	}
	fclose(fp);
	printf("%d\n", cnt);
	printf("%d\n", sum);
	printf("%.2f\n", sum * 1.0 / cnt);
	return 0;
}
