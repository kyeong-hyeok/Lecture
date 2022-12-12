#include "my_func.h"

void insert() {
	struct tel* tmp;
	char temp[100];
	int l;
	if (count >= max_num) {
		printf("OVERFLOW\n");
		return;
	}
	tel_list[count] = (TEL*)malloc(1 * sizeof(TEL));
	printf("Name:");
	scanf("%s", temp);
	l = strlen(temp);
	tel_list[count]->name = (char*)malloc((l + 1) * sizeof(char));
	strcpy(tel_list[count]->name, temp);
	printf("Phone_number:");
	scanf("%s", temp);
	l = strlen(temp);
	tel_list[count]->tel_no = (char*)malloc((l + 1) * sizeof(char));
	strcpy(tel_list[count]->tel_no, temp);
	printf("Birth:");
	scanf("%s", temp);
	l = strlen(temp);
	tel_list[count]->birth = (char*)malloc((l + 1) * sizeof(char));
	strcpy(tel_list[count]->birth, temp);
	for (int i = count; i > 0; i--) {
		if (strcmp(tel_list[i]->name, tel_list[i - 1]->name) < 0) {
			tmp = tel_list[i];
			tel_list[i] = tel_list[i - 1];
			tel_list[i - 1] = tmp;
		}
	}
	count++;
	printf("<<%d>>\n", count);
}
