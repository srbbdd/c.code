#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//任何一个c程序，只要运行起来就会默认打开3个流
//FILE* stdin - 标准输入（键盘）
//FILE* stdout - 标准输出流（屏幕）
//FILE* STDERR - 标准错误流 （屏幕）
struct s
{
	char name[10];
	int age;
	float so;
};
int main()
{
	struct s s = { "zhangsan",25,50.0};
	FILE* p1 = fopen("text.txt", "r");
	assert(p1);
	//fprintf(stdout/*标准输出流可以直接打印在屏幕上 , p1是FILE* 文件流*/, "%s %d %f\n", s.name, s.age, s.so);//fprintf这些函数适用于所有输出流fscanf适用所有输入流
	fputs("liluiol", stdout);//输出到屏幕
	fclose(p1);
	p1 = NULL;
	return 0;
}
struct s
{
	char arr[10];
	int age;
	float score;
};
int main()
{
	struct s s = { "zhangsna",90,77.7 };
	FILE* p1 = fopen("text.txt", "wb");
    assert(p1);
	fwrite(&s,sizeof(struct s),1,p1);//需要写入的数据来自s每个数据大小是sizeof(struct s)，写入一个数据，写入p1
	fclose(p1);
	p1 = NULL;
	return 0;
}
int main()
{
	struct s s = { 0 };
	FILE* p1 = fopen("text.txt", "r");
	assert(p1);
	fread(&s, sizeof(struct s), 1, p1);//从p1读取1一个大小为 sizeof(struct s)的数据放入s
	printf("%s %d %f", s.arr, s.age, s.score);
	fclose(p1);
	p1 = NULL;
	return 0;
}
//scanf 是针对标准输入的格式化输入语句
//printf 是针对标准输出的格式化输出语句
//fsacnf 是针对所有输入流的格式化语句
//fpintf 是针对所有输出流的格式化语句
//sprintf 是吧一个格式化的数据转化成字符串
//sscanf 从一个字符串中转化出一个格式化的数据
int main()
{
	struct s s = { "zhangsan",20, 55.6 };
	struct s tmp = { 0 };
	char buf[100];
	sprintf(buf, "%s %d %f\n", s.arr, s.age, s.score);//将一个格式化的数据写到字符串中，本质是吧一个格式化的数据转换成字符串,s.arr, s.age, s.score转换成字符串
	//"zhangsan 20 55.6"
	printf("%s", buf);
	sscanf(buf ,"%s %d %f", tmp.arr, &(tmp.age), &(tmp.score));//从buf获取一个格式化的数据存入 tmp.arr, &(tmp.age), &(tmp.score)
	printf("%s %d %f", tmp.arr, tmp.age, tmp.score);
	return 0;
}
#include <stdio.h>
// 班级成绩输入输出
int main()
{
    float ret = 0.0f;
    int i = 1;
    float a = 0.0f;
    for (i = 1; i <= 5; i++)
    {
        int j = 1;
        for (j = 1; j <= 5; j++)
        {
            scanf("%f", &a);
            printf("%.1f ", a);
            ret += a;
        }
        printf("%.1f\n", ret);
        ret = 0.0f;
    }
    return 0;
}
#include <stdio.h>
//竞选社长
int seek(char* a, char* b)
{
    int i = 0;
    int ret = 0;
    while (a[i] != 0)
    {
        if (a[i] == b)
        {
            ret++;
        }
        i++;
    }
    return ret;
}
int main()
{
    char add[100];
    scanf("%s", add);
    int a = 0;
    int b = 0;
    char* c = add;
    char* d = add;
    a = seek(c, 'A');
    b = seek(d, 'B');
    if (a == b)
    {
        printf("E");
        return 0;
    }
    printf("%s", a > b ? "A" : "B");
    return 0;
}