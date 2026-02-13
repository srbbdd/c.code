#include "test.h"
int main()
{
	contacts* add =(contacts*)calloc(1,sizeof(contacts));
	int count = 1;
	/*contacts* ret = (contacts*)calloc(add, sizeof(contacts));
	assert(ret);
	add = ret;*/
	contacts* arr = add;
	int zl = 1;
	int a = 0;
	add = du_archive(add,arr,&count,&zl);//读取数据
	arr = add + (zl - count);
	do
	{
		printf("输入0: 退出\n输入1: 增加联系人\n输入2: 删除联系人\n输入3: 查找联系人\n输入4: 修改联系人\n输入5: 显示已有联系人\n");
		scanf("%d", &a);
		switch (a)
		{
		case 0:
			archive(add,zl-count);//保存
			free(add);
			break;
		case 1:
		{
			system("cls");
			add=increase_contacts(add,arr,&count,&zl);
			arr = add + (zl-count);
			my_qsort(add, arr, sizeof(add[0]), compar);
			break;
		}
		case 2:
		{
			system("cls");
			arr = delet_contacts(add, arr,&count);
			break;
		}
		case 3:
		{
			system("cls");
			locat_contacts(add, arr);
			break;
		}
		case 4:
		{
			system("cls");
			reveal_already_have_contacts(add, arr);
			modify_contacts(add, arr);
			break;
		}
		case 5:
		{
			system("cls");
			reveal_already_have_contacts(add, arr);
			break;
		}
		}
	} while (a);
	return 0;
}