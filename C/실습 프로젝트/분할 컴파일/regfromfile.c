#include "my_func.h"

void RegFromFile() {
	FILE* fp;
	char temp[100];
	struct tel* tmp;
	int l, s = 0, c = 0, ll;
	fp = fopen("PHONE_BOOK.txt", "r");
	while (1) {
		if (count >= max_num) {
			printf("OVERFLOW\n");
			return;
		}
		tel_list[count] = (TEL*)malloc(1 * sizeof(TEL));
		fscanf(fp, "%s", temp);
		if (feof(fp)) break;
		l = strlen(temp);
		tel_list[count]->name = (char*)malloc((l + 1) * sizeof(char));
		strcpy(tel_list[count]->name, temp);

		fscanf(fp, "%s", temp);
		l = strlen(temp);
		tel_list[count]->tel_no = (char*)malloc((l + 1) * sizeof(char));
		strcpy(tel_list[count]->tel_no, temp);

		fscanf(fp, "%s", temp);
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
	}
	fclose(fp);
}
