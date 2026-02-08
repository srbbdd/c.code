#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <assert.h>
typedef struct
{
	char name[7];
	int old;
	int call;
	char gender[5];
	char address[11];
} contacts;
contacts* increase_contacts(contacts* add, contacts* arr,int* count,int* zl);
void reveal_already_have_contacts(contacts*add, contacts*arr);
int compar(const void* a1, const void* a2);
void my_qsort(void* add, void* arr, int sz, int(*compar)(const void*, const void*));
contacts* delet_contacts(contacts* add, contacts* arr,int* count);
void locat_contacts(contacts* add, contacts* arr);
void modify_contacts(contacts* add, contacts* arr);