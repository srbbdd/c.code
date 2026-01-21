#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	char* a[] = { "woek","at","alibaba" };//char* a存放的是第一个字符串的首地址，然后赋值给pa，+1跳过一个char*到第二个字符串，所以打印at
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c+1,c};
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	//cpp++指向c+2然后两次解引用得到POINT
//	printf("%s\n", *--*++cpp+3);
//	//cpp++指向c+1，解引用得到c+1然后--等到c，然后解引用得到E然后+3打印出来就是ER
//	printf("%s\n", *cpp[-2]+3);
//	//cpp指向c+1，-2解引用指向c+3然后解引用得到f+3打印就是ST
//	printf("%s\n", cpp[-1][-1]+1);
//	//此时cpp还是指向c+1，-1解引用得到c+2，-1解引用也就是c+1解引用的出来N，+1打印出来就是EW
//	return 0;
//} 
//#include <stdio.h>
//#include<string.h>
//#include <assert.h>
//size_t my_strlen(const char* a)
//{
//	assert(a);
//	int i = 0; 
//	while (*a)
//	{
//		a++;
//		i++;
//	}
//	return i;
//}
//int main()
//{
//	//size_t;
//	char a[] = "fghjkdsfg";
//	size_t len = my_strlen(a);
//	printf("%zu", len);
//	if (strlen("abc") - strlen("abcdef") > 0)//strlen返回值是size_t无符号整形，所以结果肯定是整数
//	{
//		;
//	}
//	else
//	{
//		;
//	}
//	return 0;
//}
#include <stdio.h>
int main()
{
    int t = 0;
    scanf("%d", &t);
    char add[3][3];
    int i = 0;
    for (i = 0; i < t; i++)
    {
        int j = 0;
        int h = 0;
        int z = 0;
        for (j = 0; j < 3; j++)
        {
            int p = 0;
            for (p = 0; p < 3; p++)
            {
                scanf(" %c", &add[j][p]);
            }
            if (add[j][1] != add[j][0] && add[j][0] == add[j][2] && add[j][1] != '.')
            {
                if (add[j][0] == 'o')
                {
                    z++;
                }
                else if (add[j][0] == '*')
                {
                    h++;
                }
            }

        }
        {
            for (j = 0; j < 3; j++)
            {
                if (add[1][j] != add[0][j] && add[0][j] == add[2][j] && add[1][j] != '.')
                {
                    if (add[0][j] == 'o')
                    {
                        z++;
                    }
                    else if (add[0][j] == '*')
                    {
                        h++;
                    }
                }
            }
            if (h != 0 && z == 0)
            {
                printf("kou\n");
            }
            else if (z != 0 && h == 0)
            {
                printf("yukari\n");
            }
            else
            {
                printf("draw\n");
            }
        }
    }
    return 0;
}