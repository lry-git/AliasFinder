/*
考察到的约束求解能力覆盖点：ARRAY_SIZE，std::min
*/
#include <algorithm>
#include "../TestCase.h"

int SetGoodItem(const int num)
{
    Cnt param[BUF_LEN];
    if (num != ARRAY_SIZE(param)) {  // 保证入参num为数组大小
        return -1;
    }
    uint32_t loopCnt = std::min(num, MAX_ATTR_NUM); // 做了访问上标保护，保证循环上界小于数组大小
    int res;
    for (uint32_t loop = 0; loop < loopCnt; loop++) {
        res = param[loop].val;  // 数组下标访问点，不会越界
    }
    return res;
}

int SetBadItem(const int num)
{
    Cnt param[BUF_LEN];
    if (num != ARRAY_SIZE(param)) {  // 保证入参num为数组大小
        return -1;
    }
    uint32_t loopCnt = std::min(num, MAX_ATTR_NUM); // 做了访问上标保护
    int res;
    for (uint32_t loop = 0; loop <= loopCnt; loop++) { // POTENTIAL FLAW: 循环上界不准确，可能发生缓冲区越界（off-by-one）
        res = param[loop].val;  // 数组下标访问点，可能越界
    }
    return res;
}