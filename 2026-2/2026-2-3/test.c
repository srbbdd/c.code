#include "test.h"
contacts* increase_contacts(contacts* add)
{
	printf("请输入联系人的姓名，年龄，性别，电话，地址\n");
	while (scanf("%s %d %s %d %s", add->name, &add->old, add->gender, &add->call, add->address) != EOF)
	{
		add++;
	}
	system("cls");
	return add;
}
void reveal_already_have_contacts(const contacts* add,const contacts* arr)
{
	int i = 1;
	while (add < arr)
	{
		printf("%d.姓名:%s\n  年龄:%d\n  性别:%s\n  电话:%d\n  地址:%s\n",i,add->name, add->old, add->gender, add->call, add->address);
		add++;
		i++;
		printf("\n");
	}
}
int compar(const void* a1, const void* a2)
{
	return ((*(contacts*)a1).old - (*(contacts*)a2).old);
}
void reverse(void* a1,void* a2,int sz)
{
	int i = 0;
	char* p1 = (char*)a1;
	char* p2 = (char*)a2;

	for (i = 0; i < sz; i++)
	{
		char emp = *p1;
		*p1 = *p2;
		*p2 = emp;
		p1++;
		p2++;
	}
}
void my_qsort(void* add, void* arr, int sz, int(*compar)(const void*, const void*))
{
	int i = 0;
	char* j = add;
	char* p = add;
	char* p2 = arr;
    
	for (j;j<p2-sz-(i*sz);i++)
	{
		int k = 0;
		for (p ; p < (p2 - sz -(k*sz) ); k++)
		{
			if (compar(p + (k * sz), p + ((k + 1) * sz)) > 0)
			{
				reverse(p + (k * sz), p + ((k + 1) * sz), sz);
			}
		}
	}
}
void onward(contacts* add, contacts* arr, int sz)
{
	while (add < arr)
	{
		*add = *(add+1);
		add++;
	}
}
contacts* delet_contacts(contacts* add, contacts* arr)
{
	int i = 0;
	printf("请输入需要删除的联系人\n");
	reveal_already_have_contacts(add, arr);
	while (scanf("%d", &i) != 0&&i!=EOF)
	{
		i -= 1;
		if (add[i].old != 0)
		{
			onward(add + i, arr, sizeof(add[i]));
			system("cls");
			arr--;
			reveal_already_have_contacts(add, arr);
		}
		else if (i!=EOF)
		{
			printf("编号不合法\n");
		}
		else
		{
			break;
		}
	}
	return arr;
}
void locat_contacts(contacts* add,contacts* arr)
{
	printf("请输入需要查找的姓名\n");
	char name1[7];
	scanf("%s", name1);
	int i = 0;
	int j = 1;
	while (add < arr)
	{
		if ((*add).name[i] == name1[i])
		{
			i++;
			if (name1[i] == '\0')
			{
				printf("%d.姓名:%s\n  年龄:%d\n  性别:%s\n  电话:%d\n  地址:%s\n", j, add->name, add->old, add->gender, add->call, add->address);
				j++;
				add++;
				i = 0;
			}
		}
		else
		{
			add++;
		}
	}
}
void modify_contacts(contacts* add,contacts* arr)
{
	int i = 0;
	int a = 0;
	contacts* p = add;
	do {
		printf("请输入要修改的联系人\n");
		scanf("%d", &i);
		printf("请输入需要修改的内容\n1:姓名\n2:年龄\n3:性别\n4:电话\n5:地址\n6:全都要\n输入0退出");
		scanf("%d", &a);
		p += i-1;
		switch (a)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			printf("请输入修改后的内容\n");
			scanf("%s", p->name);
			break;
		}
		case 2:
		{
			printf("请输入修改后的内容\n");
			scanf("%d", &p->old);
			my_qsort(add, arr, sizeof(add[0]), compar);
			break;
		}
		case 3:
		{
			printf("请输入修改后的内容\n");
			scanf("%s", p->gender);
			break;
		}
		case 4:
		{
			printf("请输入修改后的内容\n");
			scanf("%d", &p->call);
			break;
		}
		case 5:
		{
			printf("请输入修改后的内容\n");
			scanf("%s", p->address);
			break;
		}
		case 6:
		{
			printf("请输入修改后的内容\n");
			scanf("%s %d %s %d %s", p->name, &p->old, p->gender, &p->call, p->address);
			break;
		}
		}
		system("cls");
		reveal_already_have_contacts(add, arr);
	} while (a);
}