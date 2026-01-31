#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct sru
{
	char name[20];
	int age;
}s1,s2;//s1，s2是struct sru 类型的全局变量
struct//匿名结构体只能用一次
{
	char name[20];
	int age;
}s1;
int main()
{

	return 0;
}
#include <stdio.h>
struct
{
	int a; 
	char b;
	float c;
}x;
struct
{
	int a;
	char b;
	float c;
}a[20],*p;
int main()
{
	p = &x;
	return 0;
}
#include <stdio.h>
struct node
{
	//数据域
	int adta;
	//指针域
	struct node* next;//链表，在这个节点存上下一个节点的地址
};
typedef struct//匿名结构体首先是存在的才能typedef//而这个类型存在是由typedef产生的
{
	int date;
	lode* next;
}lode;
typedef struct lode
{
	int date;
	lode* next;
}lode;
typedef struct node
{
	int date;
	struct node* next
}* linklist;// == typedef structt node* linklist
int main()
{

	return 0;
}
#include <stdio.h>
struct st
{
	int x;
	int y;
}p1 = { 1,3 };
struct sor
{
	int n;
	char ch;
};
struct stu
{
	char name[20];
	int age;
	struct sor s;
};
int main()
{
	struct st p2 = { 1,3 };
	struct stu p3 = { "zhangsan",20,{100,'c'}};
	printf("%s %d %d %c", p3.name, p3.age, p3.s.n, p3.s.ch);
	return 0;
}
#include <stdio.h>
struct s1
{
	char c1;//c1存放在偏移值为0的地址
	int i;//int为4，4< 8取4，偏移值4是4的倍数所以4567是i的位置
	char c2;//1<8，取1，8是1的倍数所以c2的位置是偏移数位8的位置，所以1是char的对齐数，所以最大的对齐数是int的4而最终大小是最大对齐数的整数倍，而目前一个从0占到8一个是9所以下一个整数倍偏移数是11也就是12个大小
};
struct s2
{
	char c1;
	char c2;
	int i;
};
int main()
{
	printf("%d\n", sizeof(struct s1));//第一个成员变量在与结构体变量偏移量为0的地址处，其他的值以自己的字节大小与编译器的对齐数比较，取较小值为对齐数，然后将这个值放到对齐数的整数倍的位置，最后结构体的总大小是最大对齐数的整数倍
	printf("%d\n", sizeof(struct s2));

	return 0;
}
#include <stdio.h>
//牛牛的书// 结构体排序
struct book
{
    char name[20];
    int money;
};
int compar(const void* a1, const void* a2)
{
    return ((*(struct book*)a1).money - (*(struct book*)a2).money);
}
void reverse(void* arr, void* arr2, int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        char emp = *(char*)arr;
        *(char*)arr = *(char*)arr2;
        *(char*)arr2 = emp;
        (char*)arr += 1;
        (char*)arr2 += 1;
    }
}
void my_qsort(void* add, int sz, int small, int(*compar)(const void*, const void*))
{
    int i = 0;
    char* p = (char*)add;
    for (i = 0; i < sz; i++)
    {
        int j = 0;
        for (j = 0; j < sz-i-1; j++)
        {
            if (compar((p+(j*small)), (p+((j+1)*small))) > 0)
            {
                reverse((p+(j*small)), (p+((j+1)*small)), small);
            }
        }
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    struct book add[3];
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", add[i].name, &add[i].money);
    }
    my_qsort(add, n, sizeof(add[0]), compar);
    for (i = 0; i < n; i++)
    {
        printf("%s %d\n", add[i].name, add[i].money);
    }
    return 0;
}