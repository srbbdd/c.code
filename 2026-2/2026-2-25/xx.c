#include  "xx.h"
void testSeqlist1()
{
    sl s1 = { 1 };
    seqlistint(&s1);
    seqlistintFront(&s1,1);
    seqlistintFront(&s1, 2);
    seqlistintFront(&s1, 3);
    seqlistintFront(&s1, 4);
    seqlistintFront(&s1, 5);
    seqlistintFront(&s1, 6);
    inserte(&s1, 2, 20);
    delete(&s1, 2);
    seqlistprintf(&s1);
    destory(&s1);
}
void menu()
{
    ;
}
int main()
{
    testSeqlist1();
    menu();
    return 0;
}