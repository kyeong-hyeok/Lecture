#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	FILE* fp1,* fp2;
	char a[21], b[21], ch;
	fscanf(stdin, "%s", a);
	fscanf(stdin, "%s", b);
	fp1 = fopen(a, "ab");
	if (fp1 == NULL) {
		printf("Couldn't open file");
		return -1;
	}	
	fp2 = fopen(b, "r");
	if (fp2 == NULL) {
		printf("Couldn't open file");
		return -1;
	}
	while (!feof(fp2)) {
		ch = fgetc(fp2);
		if(!feof(fp2))
			fputc(ch, fp1);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
