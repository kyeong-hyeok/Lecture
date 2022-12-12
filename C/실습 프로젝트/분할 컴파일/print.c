#include "my_func.h"

void print_all() {
	if (count == 0) return;
	for (int i = 0; i < count; i++)
		printf("%s %s %s\n", tel_list[i]->name, tel_list[i]->tel_no, tel_list[i]->birth);
}
