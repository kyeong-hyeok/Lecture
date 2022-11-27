#include<stdio.h>

int add(int a, int b);
int sub(int a, int b);
int multiply(int a, int b);
int main() {
	int x, y;
	int(*handle[3]) (int, int) = { add, sub, multiply };
	scanf("%d %d", &x, &y);
	printf("%d %d %d", (*handle[0])(x,y), (*handle[1])(x, y), (*handle[2])(x, y));
	return 0;
}


int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}
