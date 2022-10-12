#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	char str1[40], str2[20];
	int inx1 = 0, inx2 = 0, c, n, i, j;
	scanf("%s", str1);
	getchar();
	scanf("%s", str2);
	scanf("%d", &c);
	scanf("%d", &n);
	while (str1[inx1])
		inx1++;
	while (str2[inx2])
		inx2++;
	for (int i = inx1-1; i >=c; i--)
		str1[i + inx2] = str1[i];
	if (n == 0) {
		for (i = 0; i < inx2; i++)
			str1[i + c] = str2[i];
	}
	else {
		for (i = 0, j = inx2 - 1; i < inx2; i++, j--)
			str1[i + c] = str2[j];
	}
	str1[inx1 + inx2] = '\0';
	printf("%s", str1);
	return 0;
}
