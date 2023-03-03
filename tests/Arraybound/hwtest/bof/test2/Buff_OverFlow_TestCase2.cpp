/*
考察到的约束求解能力覆盖点： vector的size(),resize()函数
*/
#include <vector>
#include "../TestCase.h"
using namespace std;

int SetGoodItem(vector<Cnt> &param1, vector<Cnt> &param2)
{
    uint32_t listSize = param1.size();
    uint32_t loopCnt = FOO_Min(listSize, MAX_ATTR_NUM); // 对param1做了访问上标保护，保证循环上界小于param1的长度
    if (loopCnt > param2.size()) { // 对param2做了访问上标保护，保证循环上界小于param2的长度
        param2.resize(loopCnt);
    }
    uint32_t res = 0;
    for (uint32_t loop = 0; loop < loopCnt; loop++) {
        res += param1[loop].hasAttr;  // 数组下标访问点，不会越界
        res += param2[loop].hasAttr;  // 数组下标访问点，不会越界
    }
    return res;
}

