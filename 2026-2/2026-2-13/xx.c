#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//int main()
//{
//	FILE* p1 = fopen("text.txt", "r");
//	assert(p1);
//	fseek(p1, 2, SEEK_SET);//设置偏移值p1，SEEK_SET起始位置偏移量为2的数据
//	int ch = fgetc(p1);
//	printf("%c\n", ch);
//	fseek(p1, 2, SEEK_CUR);//上次读取完后文件指针已经偏移前到2个数据的下一个数据，而CUR就是当前文件指针位置
//	ch = fgetc(p1);
//	printf("%c\n", ch);
//	fseek(p1, -1, SEEK_END);//从末尾开始偏移
//	ch = fgetc(p1);
//	printf("%c\n", ch);
//	printf("%d", ftell(p1));//ftell可以计算起始位置到当前文件指针位置的偏移量
//	rewind(p1);//将文件指针回到起始位置
//	/*int i = 1;
//	for (i = 0; i <= 2; i++)
//	{
//		fseek(p1, i * 2, SEEK_SET);
//		int ch = fgetc(p1);
//		printf("%c\n", ch);
//	}*/
//	fclose(p1);
//	p1 = NULL;
//	return 0;
//}
//#include <stdio.h>
//int max3(int a, int b, int c)
//{
//    return (a > b ? (a > c ? a : c) : (b > c ? b : c));
//}
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    scanf("%d %d %d", &a, &b, &c);
//    int d = max3(a, b + c, c) + max3(a, b, b + c);
//    int e = max3(a + b, b, c);
//    printf("%.2f", (float)e / d);
//    return 0;
//}