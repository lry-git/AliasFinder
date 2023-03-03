/*
考察到的约束求解能力覆盖点：上标保护的数据流分析,跨过程
*/
#include "../TestCase.h"

const unsigned NUM_10000 = 10000;

int VisitArray(Cnt *param, uint32_t index, const TestOverRun *item){
    uint32_t num = index / BUF_LEN;
    RET_ERR_IF(item->val >= num, -1);
    return param[item->val].val; // 数组下标访问点
}

void SetGoodItem( TestOverRun *item)
{
    Cnt param[MAX_ATTR_NUM];
    uint32_t index;
    for (uint32_t loop = 0; loop < NUM_10000; loop++) {
        if (loop % MAX_ATTR_NUM == 0) {
            index++;
        }
    }
    VisitArray(param, index, item);  // index为250
}

void SetBadItem(const TestOverRun *item)
{
    Cnt param[MAX_ATTR_NUM];
    uint32_t index;
    for (uint32_t loop = 0; loop < NUM_10000; loop++) {
        if (loop % 2 == 0) {
            index++;
        }
    }
    VisitArray(param, index, item);  // index为5000
}
