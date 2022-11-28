#include<stdio.h>
#pragma warning(disable:4996)

int gcd(int a, int b);

int main() {
	int a, b,tmp;
	scanf("%d %d", &a, &b);
	if (a < b) {
		tmp = b;
		b = a;
		a = tmp;
	}
	printf("%d", gcd(a, b));
	return 0;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
