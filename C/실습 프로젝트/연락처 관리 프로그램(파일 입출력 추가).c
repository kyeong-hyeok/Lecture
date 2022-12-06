#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

#define MAX_NUM 100         // 상수 선언 
struct tel
{
	char* name;
	char* tel_no;
	char* birth;
};

typedef struct tel TEL;
TEL** tel_list;   // 최대 100개 가능

int max_num;
int count = 0;      // 현재 저장되어 있는 연락처 개수

void insert();
void delete_tel();
void print_all();
void find_by_birth();
void menu();
void RegFromFile();
void ex();

int main() {
	int n;
	printf("Max_num:");
	scanf("%d", &max_num);
	tel_list = (TEL**)malloc(sizeof(TEL*) * max_num);
	while (1)
	{
		menu();// 시작화면 출력
		scanf("%d", &n);// 번호 n 입력
		switch (n)
		{
		case 1: insert(); break;
		case 2: print_all(); break;
		case 3: delete_tel(); break;
		case 4: find_by_birth(); break;
		case 5: RegFromFile(); break;
		case 6: ex(); return 0;  // 종료
		}
	}

	return 0;
}

void menu() {
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
	printf("Enter_the_menu_number:");
}

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

void print_all() {
	if (count == 0) return;
	for (int i = 0; i < count; i++)
		printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
}

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


void ex() {
	FILE* fp;
	fp = fopen("PHONE_BOOK.txt", "w");
	for (int i = 0; i < count; i++)
		fprintf(fp, "%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
	fclose(fp);
}
