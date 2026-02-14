#include <stdio.h>
#include <windows.h>
int main()
{
	/*feof 应用于文件读取结束的时候，判断读取结束的原因是什么
 	ferror 判断是否遇到错误而读取结束
	文本文件判断文件读取是否结束，fgetc（返回EOF）或fgets（NULL）
	二进制判断文件读取是否结束，判断返回值是否小于实际读的个数，fread（返回实际读取的个数）*/
	int c;
	FILE* p1 = fopen("text.txt", "r");
	if (!p1)//如果为空指针，空指针为假取反为真
	{
		return 0;
	}
    if (ferror(p1))//判断是否为读取错误
    {
	return 0;
	}
	else if (feof(p1))//判断是否为文件末尾结束
	{
		return 0;
	}
	return 0;
}
int main()
//缓冲区
{
	FILE* p1 = fopen("test.txt", "w");
	fputs("abcde", p1);
	printf("等待10秒");
	Sleep(10000);
	fflush(p1);//刷新缓冲区
	printf("刷新缓冲区");
	Sleep(10000);
	fclose(p1);//fclose在关闭文件也会刷新缓冲区,所以需要记得关闭文件
	p1 = NULL;
	return 0;
}
