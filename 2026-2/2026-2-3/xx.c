#include "test.h"
int main()
{
	contacts add[100] = { 0 };
	contacts* arr = add;
	int a = 0;
	do
	{
		printf("输入0: 退出\n输入1: 增加联系人\n输入2: 删除联系人\n输入3: 查找联系人\n输入4: 修改联系人\n输入5: 显示已有联系人\n");
		scanf("%d", &a);
		switch (a)
		{
		    case 0:
			break;
			case 1:
			{
				system("cls");
				arr = increase_contacts(arr);
				my_qsort(add,arr,sizeof (add[0]),compar);
				break;
			}
			case 2:
			{
				system("cls");
				arr = delet_contacts(add,arr);
				break;
			}
			case 3:
			{
				system("cls");
				locat_contacts(add,arr);
				break;
			}
			case 4:
			{
				system("cls");
				reveal_already_have_contacts(add, arr);
				modify_contacts(add,arr);
				break;
			}
			case 5:
			{
				system("cls");
				reveal_already_have_contacts(add,arr);
				break;
			}
		}
	} while (a);
	return 0;
}