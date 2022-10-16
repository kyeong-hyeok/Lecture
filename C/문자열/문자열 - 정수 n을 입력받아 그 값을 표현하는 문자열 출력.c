#include<stdio.h>
#pragma warning(disable:4996)

int main() {
    int n, i = 0;
    char num[11][6] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" }, a[5] = { 0 };
    scanf("%d", &n);
    while (n != 0) {
        a[i] = n % 10;
        n /= 10;
        i++;
    }
    while (i >= 0) {
        if (a[i] != 0) {
            if (i == 3)
                printf("%s THO ", num[a[i]]);
            else if (i == 2)
                printf("%s HUN ", num[a[i]]);
            else if (i == 1)
                printf("%s TEN ", num[a[i]]);
            else if (i == 0)
                printf("%s", num[a[i]]);
        }
        i--;
    }
	return 0;
}
