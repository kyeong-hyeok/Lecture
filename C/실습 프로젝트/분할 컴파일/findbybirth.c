#include "my_func.h"

void find_by_birth() {
	int n, b, m;
	printf("Birth:");
	scanf("%d", &n);
	for (int i = 0; i < count; i++) {
		b = atoi(tel_list[i]->birth);
		m = (b / 100) % 100;
		if (m == n)
			printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
	}
}
