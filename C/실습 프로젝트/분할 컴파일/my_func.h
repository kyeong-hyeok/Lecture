#ifndef MY_FUNC_H
#define MY_FUNC_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "my_struct.h"
#include "my_define.h"
#pragma warning(disable:4996)
void insert();
void delete_tel();
void print_all();
void find_by_birth();
void menu();
void RegFromFile();
void ex();
#define MAX_NUM 100         // 상수 선언 
extern int count;
extern TEL** tel_list;
extern int max_num;
#endif
