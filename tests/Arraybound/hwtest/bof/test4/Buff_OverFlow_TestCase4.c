/*
考察到的约束求解能力覆盖点：跨过程的控制流分析，空指针访问
*/
#include <stddef.h>
#include "../TestCase.c"

TestOverRun *getItem(const uint32_t index)
{
    if (index >= BUF_LEN) {
        return NULL;
    }
    TestOverRun *res;
    return res;
}

int SetGoodItem(const uint32_t index)
{
    TestOverRun *item = getItem(index);
    RET_ERR_IF(index >= BUF_LEN, -1);  // 做了访问上标保护，保证循环上界不超过数组大小
    unsigned int res = item->buff[index];  // 数组下标访问点，不会访问到空指针
    return res;
}

int SeBadItem(const uint32_t index)
{
    TestOverRun *item = getItem(index);
    unsigned int res = item->buff[index];  // 数组下标访问点，可能访问到空指针
    return res;
}