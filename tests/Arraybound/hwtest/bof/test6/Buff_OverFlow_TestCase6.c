/*
考察到的约束求解能力覆盖点：上标保护的数据流分析,跨过程,数组长度是引用传入,外部输入
*/
#include "../TestCase.c"
#define NUM_30 30

int VisitArray(Cnt *param, uint32_t *index, uint32_t input){
    RET_ERR_IF(input >= NUM_30, -1);
    return param[*index + input].val;
}

void SetGoodItem(uint32_t input)
{
    Cnt param[MAX_ATTR_NUM];  // MAX_ATTR_NUM = 40
    uint32_t index = GetFactor(input) * ENUM_VALUE_3; //  index = input % 3 * 3 = {0, 3, 6}
    VisitArray(param, &index, input);
}

void SetBadItem(uint32_t input)
{
    Cnt param[MAX_ATTR_NUM];  // MAX_ATTR_NUM = 40
    uint32_t index = GetFactor(input) * ENUM_VALUE_4 * 2; //  index = input % 3 * 8 = {0, 8, 16}
    VisitArray(param, &index, input);
}