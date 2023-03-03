/*
考察到的约束求解能力覆盖点：范围for语句（range for statement）
*/
#include "../TestCase.h"

int SetItem()
{
    uint32_t loopCnt = 0;
    static const uint32_t nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for (auto item: nums) {
        for (uint32_t i = 0; i < item; i++) {
             loopCnt++;
        }
    }
    return loopCnt;
}

