#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1,3,2,4,5 };
//	int arr2[] = { 1,2,3 };
//	int ret = memcmp(arr1, arr2, 12);//吧arr1和arr2的前12的字节进行比较
//	printf("%d", ret);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	/*char arr[] = { "hello world" };
//	memset(arr+2, 'x', 3);
//	printf("%s", arr);*/
//	int arr[10] = { 0 };
//	memset(arr, 1, 40);
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
////小乐乐改数字
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int a = 0;
//    while (n)
//    {
//        if ((n % 10) % 2)
//        {
//            a += 1 * pow(10, i);
//        }
//        n /= 10;
//        i++;
//    }
//    printf("%d", a);
//    return 0;
//
//}
#include <stdio.h>
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int big = (n > m) ? n : m;
    int smo = (n < m) ? n : m;
    int i = 0;
    long long int j = 0;
    j = big;
    while (big)
    {
        i = big;
        big = smo % big;
        smo = i;
    }
    i = smo;
    j = n * m / i;
    printf("%lld", i + j);
    return 0;
}