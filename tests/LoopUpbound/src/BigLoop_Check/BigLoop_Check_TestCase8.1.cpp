/*
考察到的约束求解能力覆盖点：外部输入，数组取值，跨过程，跨文件，枚举值，无法计算确定值的情况
*/
#include "../TestCase.c"
#include <vector>
uint32_t GetFactor__(const uint32_t index)
{
    std::vector<uint32_t> factorList;
    factorList.emplace_back(0);
    return factorList[index%3];
}
uint32_t GetLoopCnt(const uint32_t index)
{
    return GetFactor__(index) * ENUM_VALUE_3;
}
int SetItem(const uint32_t index, const uint32_t addNums)
{
    RET_ERR_IF(addNums >= BUF_LEN, -1);
    uint32_t loopCnt = 0;
    for (uint32_t i = 0; i < GetLoopCnt(index) + addNums; i++){
        loopCnt++;
    }
    return loopCnt;
}