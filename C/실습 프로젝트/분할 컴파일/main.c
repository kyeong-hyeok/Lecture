#include "my_func.h"

TEL** tel_list;   // 최대 100개 가능
int max_num;
int count = 0;      // 현재 저장되어 있는 연락처 개수

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

void ex() {
	FILE* fp;
	fp = fopen("PHONE_BOOK.txt", "w");
	for (int i = 0; i < count; i++)
		fprintf(fp, "%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
	fclose(fp);
}
