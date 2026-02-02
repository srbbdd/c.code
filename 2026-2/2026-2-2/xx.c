#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//位段
//位段的成员需要是整形家族的
//位段不快平台但可以节省空间
struct a
{
	//int成员，先开辟四个字节
	int _a : 1;
	int _b : 5;
	int _c : 10;
	//到这里四个字节存不下了然后又开辟了4个字节
	int _d : 30;//限定他们的空间位1，5，10，30个bit位
	//所以占8个字节
};
struct s
{
	// 开辟一个char
	char a : 3;
	char b : 4;
	//到这里剩下一个然后在开辟一个字节，但是上次剩下的一个bit位他不会再用，所以下一个char他还要在开辟一个字节所以占三个字节//但是不是所有的编译器都会浪费不清楚
	char c : 5;
	char d : 4;

};
int main()
{
	struct s s = { 0 };
	printf("%d\n", sizeof(s));
	//一次开辟一个字节所以不涉及大小端问题
	s.a = 10;//a有三个bit位10的二进制是1010 所以只能存下010
	s.b = 12;//能放下1100，此时第一次开辟的一个字节只剩一个字节了，存不下下一个了所以又开辟了一个字节
	s.c = 3;//c有5个bit为所以补0，00011，此时新开辟的一个字节剩3个，所以又开辟了一个
	s.d = 4;//0100
	//所以他们存放的应该是01100010 00000011 00000100换算16进制就是0x 62 03 04
	printf("%d", sizeof(struct a));
	return 0;
}
#include <stdio.h>
//ISBN号码
int main()
{
    char a[14];
    scanf("%s", a);
    int ret = 0;
    char* p = a;
    int i = 1;
    while (i < 10)
    {
        if (*p != '-')
        {
            ret += ((int)(*p) - '0') * i;
            i++;
        }
        p++;
    }
    if ((*(++p)) == 'X' && ret % 11 == 10)
    {
        printf("Right");
    }
    else if (ret % 11 == (*p) - '0')
    {
        printf("Right");
    }
    else
    {
        if (ret % 11 == 10)
        {
            *p = 'X';
        }
        else
        {
            *p = ret % 11 + '0';
        }
        printf("%s", a);
    }
    return 0;
}