#include "my_func.h"

void delete_tel() {
	char a[21];
	int inx = -1;
	if (count == 0) {
		printf("NO MEMBER\n");
		return;
	}
	printf("Name:");
	scanf("%s", a);
	for (int i = 0; i < count; i++) {
		if (strcmp(a, tel_list[i]->name) == 0) {
			inx = i;
			break;
		}
	}
	free(tel_list[inx]->name);
	free(tel_list[inx]->tel_no);
	free(tel_list[inx]->birth);
	free(tel_list[inx]);
	if (inx != -1) {
		for (int i = inx; i < count - 1; i++)
			tel_list[i] = tel_list[i + 1];
		count--;
	}
	return;
}
