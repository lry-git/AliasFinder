/*
考察到的约束求解能力覆盖点：静态数组的长度计算，std::min
*/

#include <algorithm>
#include "../TestCase.h"
using namespace std;

void SetGoodItem(const TestOverRun *item, int &val)
{
    uint32_t index = std::min(int(item->val), BUF_LEN);  // 做了访问上标保护，保证index<=12
    RET_IF(index < 1);
    static const uint32_t nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    val = nums[index - 1];  // 数组下标访问点，不会越界
}