#ifndef __TEST_H__//可以防止头文件被重复包含
#define __TEST_H__//第一次没有被定义，头文件内容会被拷贝过去，如果重复包含 __TEST_H__被定义 这些代码就不会被执行
#pragma once//头文件只被包含一次
int add(int x, int y);
#endif