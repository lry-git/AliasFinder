#include "TestCase.h"

enum DemoTypeEnum {
    ENUM_VALUE_1 = 1,
    ENUM_VALUE_2 = 2,
    ENUM_VALUE_3,
    ENUM_VALUE_4
};

Cnt g_param1[BUF_LEN];
Cnt g_param2[ENUM_VALUE_4];

bool GetCondition(uint32_t index)
{
    return (index % 2 == 0);
}

uint32_t GetFactor(const uint32_t index)
{
    const uint32_t factorList[] = {0, 1, 2};
    return factorList[index % 3];
}