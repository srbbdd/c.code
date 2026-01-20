#define _CRT_SECURE_NO_WARNINGS
//include <stdio.h>
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* prt = (int*)(&a + 1);//取整个数组的地址+1跳过整个数组，后面打印减一就是打印5
//	printf("%d %d", *(a + 1), *(prt - 1));
//	return 0;
//}
//#include <stdio.h>
//struct test
//{
//	int num;
//	char* pcname;
//	char cha[2];
//	short sba[4];
//}*p = (struct test*)0x100000;
//int main()
//{
//	printf("%p\n", p + 0x1);
//	printf("%p\n", (unsigned long)p + 0x1);
//	//强制转换成unsigned long将视0x100000为整数，然后加一，在以%p打印就是100001
//	printf("%p\n", (unsigned int*)p + 0x1);
//
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);//(int)a将a的地址看作整数+1,然后以int*赋给ptr2又被转换成地址，地址其实只加了一个字节
//	//小端存储的方式是 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
//	//所以qtr2+一个字节指向的是01后面那个字节，然后打印的时候*int解引用四个字节就是00 00 00 02小端存储倒置，打印出来就是20000000
//	//qtr1目前指向的是数组最后一个元素的后一个地址,[-1]就得到04 00 00 00然后小端存储倒置==00 00 00 04，0被默认省略打印出4
//	printf("%x %x", ptr1[-1], *ptr2);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//逗号表达式第一行是1，3第二行是5后面自动补0，不是逗号表达式初始化应该是大括号{{0，1}，{2，3}，{4，5}};
//	int* p;
//	p = a[0];//第一行首元素给a，就是1
//	printf("%d", p[0]);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;//指向a的第一行的前四个元素
//	printf("%p\n%d", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//p[4][2]=*(*(p+4)+2)//p是int（*）[4]类型加一跳四个字节，p[4][2]会加到4行第4个元素，而指针加减计算的是差值，p[4][2]和a[4][2]中间差四个元素，而且是p-a所以是-4个元素
//	//p-a得出-4，-4的补码是11111111111111111111111111111100以%p打印，地址格式打印没有原码反码补码的转换，所以转成16进制就是fffffffc
//	//%d格式打印就是-4
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);//取整个地址+1，打印减一就是10
//	int* ptr2 = (int*)(*(aa + 1));//*(aa+1)==a[1]第二行第一个元素，打印减一就是5//二维数组解引用需要两个*一次解处行一次解出列所以这里的aa[1]是吧第二行赋给了prt2
//	//而a[1]可以看成一个数组指针，int（*）[5]，a[1]就是这个指针数组的名字，他指向一个数组五个元素+1跳过五个元素来到下一行a[3]
//	printf("%d %d\n", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
#include <stdio.h>
//记录笑声
int main()
{
    int a = 0;
    scanf("%d", &a);
    char b[a + 1];
    scanf("%s", b);
    int i = 0;
    int max = 0;
    while (b[i])
    {
        int cont = 0;
        while (b[i] == 'h' || b[i] == 'H' || b[i] == 'A' || b[i] == 'a')//笑声的合法数列是a，h
        {
            cont++;
            if (b[i] == b[i + 1])
            {
                break;
            }
            i++;
        }
        if (cont > max)
        {
            max = cont;
        }
        i++;
    }
    printf("%d", max);
    return 0;
}