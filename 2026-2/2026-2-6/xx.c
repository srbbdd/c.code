#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[10] = { 0 };
	int* p = (int*)malloc(40);
	//malloc返回的是void*类型
	if (p == NULL)
	{
		printf("NO");
		return 0;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d", p[i]);
	}
	free(p);//释放p的的空间
	p = NULL;//空间释放后p还是会指向那里，所以置空
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
	while (1)
	{
		//malloc(10);
	}
	return 0;
}
#include <stdio.h>
int main()
{
	int a = 10;
	int* p = &a;
	free(p);
	//free必须释放动态开辟的空间
	p = NULL;
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p = (int*)calloc(10, sizeof(int));//开辟十个元素，每个元素四个字节,返回值是void*
	if (p == NULL)
	{
		printf("NO");
		return 0;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);//calloc开辟空间会将内容初始化为0
	}
	free(p);
	p = NULL;
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		printf("NO");
		return 0;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i+1;
	}
	int* ret = (int*)realloc(p, 80);//给p追加40个字节，就是吧p调整成80个字节/p是需要调整的，80是调整后的大小//返回值是void*
	//p = realloc(p, 80);//realloc可能会开不出来空间而返回空指针
	assert(ret);
	p = ret;
	for (i = 10; i < 20; i++)
	{
		p[i] = i+1;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d ", p[i]);
	}
	free(p);
	ret = NULL;
	p = NULL;
	return 0;
}
#include <stdio.h>
int main()
{
    char add[1000000];
    scanf("%s", add);
    int p = 0;
    scanf("%d", &p);
    int i = 0;
    int j = 0;
    while (p--)
    {
        scanf("%d %d", &i, &j);
        int ret = 0;
        for (i = i - 1; i < j; i++)
        {
            if (add[i] == 'P')
                ret += 3;
            else if (add[i] == 'p')
                ret += 2;
            if (add[i] == 'G')
                ret += 1;
        }
        printf("%d\n", ret);
    }
    return 0;
}