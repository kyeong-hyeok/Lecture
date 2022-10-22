#include<stdio.h>
#pragma warning(disable:4996)

struct student {
	char name[10]; int q1; int q2; int q3; double avg;
};

void read_data(struct student a[]);
void cal_avg(struct student a[]);
void sort(struct student a[]);
void print_score(struct student a[]);

int main() {	
	struct student a[10];
	read_data(a);
	cal_avg(a);
	sort(a);
	print_score(a);
	return 0;
}

void read_data(struct student a[]) {
	struct student* b;
	for (b = a; b < a + 10; b++)
		scanf("%s %d %d %d", b->name, &b->q1, &b->q2, &b->q3);
}

void cal_avg(struct student a[]) {
	struct student* b;
	for (b = a; b < a + 10; b++)
		b->avg = (b->q1 + b->q2 + b->q3) / 3.0;
}

void sort(struct student a[]) {
	struct student* b, * c;
	struct student tmp;
	for (b = a; b < a + 9; b++) {
		for (c = a; c < a + 9; c++) {
			if (c->avg < (c + 1)->avg) {
				tmp = *c;
				*c = *(c + 1);
				*(c + 1) = tmp;
			}
		}
	}
}

void print_score(struct student a[]) {
	printf("%s %.2f\n", a[0].name, a[0].avg);
	printf("%s %.2f\n", a[9].name, a[9].avg);
	for (int i = 7; i < 10; i++)
		printf("%s %.2f\n", a[i].name, a[i].avg);
}
