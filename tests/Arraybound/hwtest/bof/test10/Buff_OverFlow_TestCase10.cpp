/*
考察到的约束求解能力覆盖点：外部输入，数组取值，跨过程，跨过程，枚举值
*/
#include "../TestCase.c"

int SetItem(const uint32_t index, const uint32_t addNums)
{
    Cnt param[BUF_LEN];
    uint32_t listSize = ARRAY_SIZE(param);
    RET_ERR_IF(listSize >= MAX_ATTR_NUM, -1);  // 用宏约束数组长度小于40；
    Cnt res = param[GetFactor(index) * BUF_LEN + ENUM_VALUE_4 + addNums]; // POTENTIAL FLAW: addNum大于12时，可能发生缓冲区越界
    return res.val;
}