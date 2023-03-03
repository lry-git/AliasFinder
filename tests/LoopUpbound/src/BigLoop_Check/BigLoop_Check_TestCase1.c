/*
考察到的约束求解能力覆盖点：std::min, 宏定义，枚举值
*/
#include "../TestCase.c"

int SetItem()
{
    uint32_t loopCnt = 0;
    for (uint32_t i = 0; i < FOO_Min(ENUM_VALUE_4, MAX_ATTR_NUM); i++){
        loopCnt++;
    }
    return loopCnt;
}