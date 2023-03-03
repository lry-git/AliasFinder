/*
考察到的约束求解能力覆盖点：ARRAY_SIZE，跨过程的控制流分析
*/
#include "../TestCase.c"

uint32_t GetItemSize(const uint32_t index)
{
    if (GetCondition(index)) {
        return ARRAY_SIZE(g_param1);
    } else {
        return ARRAY_SIZE(g_param2);
    }
}

int SetGoodItem(const uint32_t index, Cnt &res)
{
    uint32_t listSize = GetItemSize(index);
    if (index >= listSize) {  // 做了访问上标保护，保证循环上界不超过数组大小
        return -1;
    }
    if (GetCondition(index)) {
        res = g_param1[index];  // 数组下标访问点，不会越界
    } else {
        res = g_param2[index];  // 数组下标访问点，不会越界
    }
    return 0;
}