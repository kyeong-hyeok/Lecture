int main() {
	char str[100], a[3][100];
	int l, s=0, inx=0, b, c, result=0;
	gets(str);
	l = strlen(str);
	for (int i = 0; i <= l; i++) {
		if (str[i] == ' ' || i == l) {
			for (int j = s; j < i; j++)
				a[inx][j - s] = str[j];
			a[inx][i - s] = '\0';
			inx++;
			s = i + 1;
		}
	}
	b = atoi(a[1]);
	c = atoi(a[2]);
	if (strcmp(a[0], "add") == 0)
		result = b + c;
	else if (strcmp(a[0], "sub") == 0)
		result = b - c;
	else if (strcmp(a[0], "mul") == 0)
		result = b * c;
	else if (strcmp(a[0], "div") == 0)
		result = b / c;
	printf("%s %d", a[0], result);

	return 0;
}
