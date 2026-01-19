#include <stdio.h>
#include <string.h>
int main()
{
	char* p = "abcdef";
	printf("%d", strlen(&p + 1));
	return 0;
}
#include <stdio.h>
int main()
{
	int a[3][4];
	printf("%d\n", sizeof(a));
    //三行四列一个int元素4字节一共48
	printf("%d\n", sizeof(a[0][0]));
	//传的第一个元素一个整型四个字节
	printf("%d\n", sizeof(a[0]));
	//首元素加0还是第0行，一行就是16字节
	printf("%d\n", sizeof(a[0]+1));
	//第一行第一个元素加一，传的是第二个元素的地址，地址就是4/8
	printf("%d\n", sizeof(*(a[0]+1)));
	//同上得到第二个元素然后解引用，一个整型就是四个字节
	printf("%d\n", sizeof(a+1));
	//首元素地址加一到第二行，然后吧第二行的首地址传进去，地址就是4/8
	printf("%d\n", sizeof(*(a+1)));
	//吧二维数组的每一行看作一个一维数组，同上得到第二行的地址解引用就得到了整个第二行所以是16
	printf("%d\n", sizeof(&a[0]+1));
	//取到第一行的首地址然后+1得到第二行的首地址，地址就是4/8
	printf("%d\n", sizeof(*(&a[0]+1)));
	//取第一行的首地址+1得到第二行的地址，然后解引用得到整个第二行的地址，一行就是16
	printf("%d\n", sizeof(*a));
	//首地址解引用，得到整个第一行，就是16
	printf("%d\n", sizeof(a[3]));
	//数组名单独放在sizeof会计算整个数组，如果第四行真的存在那他也是16个字节，sizeof可以确认他是这个二维数组的第四行而每一行都是4个整形，他不会真的访问这一行所以没有越界
	return 0;
}
#include <stdio.h>
//数颜色
int main()
{
	char rgb[100001] = "0";//给\0留一个空间
	scanf("%s", rgb);
	int i = 0;
	int r = 0;
	int g = 0;
	int b = 0;


	while (rgb[i])//字符串最后一个是\0会自动停
	{
		if (rgb[i] == 'r' || rgb[i] == 'R')
		{
			r++;
		}
		if (rgb[i] == 'g' || rgb[i] == 'G')
		{
			g++;
		}
		if (rgb[i] == 'b' || rgb[i] == 'B')
		{
			b++;
		}
		i++;
	}
	printf("(%d,%d,%d)", r, g, b);
	return 0;
}