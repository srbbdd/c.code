#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));
	//字符串才加\0所以是6个
	printf("%d\n", sizeof(arr+0));
	//首元素地址加0还是首元素地址，地址就是4/8
	printf("%d\n", sizeof(*arr));
	//首元素解引用，char类型一个字节
	printf("%d\n", sizeof(arr[1]));
  //下标为1的元素解引用，char类型一个字节
	printf("%d\n", sizeof(&arr));
	//数组地址，地址就是4/8
	printf("%d\n", sizeof(&arr+1));
	//数组地址加1，跳过整个数组，地址就是4/8
	printf("%d\n", sizeof(&arr[0]+1));
	//首元素地址加1，跳过一个元素，地址就是4/8
	printf ("%d",sizeof(arr[0] + 1));
	//字符加整形，会整形提升，结果是整形
	return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));
	//随机值，strlen只有到\0才会停下
	printf("%d\n", strlen(arr+0));
	//随机值，从arr+0的位置开始数直到\0
	printf("%d\n", strlen(*arr));
	//strlen函数的形参是char* 这样传进去的是'a'的ASCll就是（97）野指针，会出错
	printf("%d\n", strlen(arr[1]));
	//同上传的'b'的ASCll（98）
	printf("%d\n", strlen(&arr));
	//随机值，整个数组的地址和数组首元素地址起始位置一致，直到\0停下
	printf("%d\n", strlen(&arr+1));
	//随机值-6，加一跳过整个数组开始数到\0结束
	printf("%d\n", strlen(&arr[0]+1));
	//随机值-1，从第二个元素数到\0
	return 0;
}
#include <stdio.h>
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));
	//字符串带\0，sizeof计算长度会算上\0
	printf("%d\n", sizeof(arr+0));
	////首元素地址加0还是首元素地址，首元素地址就是4/8
	printf("%d\n", sizeof(*arr));
	////首元素解引用，一个char类型一个字节
	printf("%d\n", sizeof(arr[1]));
	//首元素下标为1的解引用，一个char类型就是一个字节
	printf("%d\n", sizeof(&arr));
	//地址就是4/8
	printf("%d\n", sizeof(&arr+1));
	//首地址加一，地址就是4/8
	printf("%d\n", sizeof(&arr[0] + 1));
	//取下标为0的地址，然后加一到第二个元素的地址，地址就是4/8
	return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr));
	//strlen计算长度不会计算\0
	printf("%d\n", strlen(arr+0));
	//从首元素开始数到\0
	printf("%d\n", strlen(*arr));
	//strlen接收是char*而传输的是a的ASCll值（97）回成野指针，像a这种ASCll转的数字在转成16进制的地址是很低的地址，而这种低地址是不会让用户访问的，所以程序会直接挂掉
	printf("%d\n", strlen(arr[1]));
	//同上传的b的ASCll（98）
	printf("%d\n", strlen(&arr));
	//整个数组的地址和首元素地址起始位置一样，所以从首元素开始数到\0
	printf("%d\n", strlen(&arr+1));
	//随机值：取整个数组的地址加一跳过整个数组，从数组后面那个地址开始数到\0
	printf("%d\n", strlen(&arr[0]+1));
	//取出首地址，然后+1数到\0
	return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
	char* p = "abcdef";
	printf("%d\n", sizeof(p));
	//p没有解引用里面是地址，地址就是4/8
	printf("%d\n", sizeof(p+1));
	//p里面的地址+1，地址就是4/8
	printf("%d\n", sizeof(*p));
	//p解引用一个char就是1
	printf("%d\n", sizeof(p[0]));
	//p+0解引用还是一个char就是1
	printf("%d\n", sizeof(&p));
	//地址就是4/8
	printf("%d\n", sizeof(&p+1));
	//p的地址加一到下一个地址，地址就是4/8
	printf("%d\n", sizeof(&p[0]+1));
	//取p的首地址然后+1到第二个地址b，地址就4/8
	printf("%d\n", strlen(p));
	//strlen不计算\0
	printf("%d\n", strlen(p+1));
	//从p的地址加一开始数到\0
	printf("%d\n", strlen(*p));
	//p解引用得到a，strlen接收是char*而传输的是a的ASCll值（97）回成野指针，像a这种ASCll转的数字在转成16进制的地址是很低的地址，而这种低地址是不会让用户访问的，所以程序会直接挂掉
	printf("%d\n", strlen(p[0]));
	//同上只是传的是b（98）
	printf("%d\n", strlen(&p));
//取p的地址然后数到\0，p的地址就是从a开始，和整个数组的地址一样虽然取的是整个的地址但他们的起始位置一样/！/老师讲这里从p的地址开始数到\0，p的地址和abcdef没关系所以是随机值//
	printf("%d\n", strlen(&p+1));
	//随机值，取真个地址+1跳过这个字符串开始数到\0
	printf("%d\n", strlen(&p[0]+1));
	//从p的地址+1也就是第二个元素开始数到\0
	return 0;
}
#include <stdio.h>
int main()
{
	int l = 0;
	int r = 0;
	int x = 0;
	scanf("%d %d %d", &l, &r, &x);
	int i = 0;
	for (i = l; i <= r; i++)
	{
		if (i % x == 0)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
#include <stdio.h>
int add(int n, int quantify, int quantify2)
{
    int i = n / quantify;
    for (i; i >= 1; i--)
    {
        if ((n - (i * quantify)) % quantify2 == 0)
        {
            return i + ((n - (i * quantify)) / quantify2);
        }
    }
    return 0;
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = add(n, 6, 8);
    int b = add(n, 8, 6);
    if (a != 0 && b != 0)
    {
        printf("%d", (a > b) ? b : a);
    }
    else if (a == 0 && b != 0 || a != 0 && b == 0)
    {
        printf("%d", (a > b) ? a : b);
    }
    else
    {
        printf("-1");
    }
    return 0;
}