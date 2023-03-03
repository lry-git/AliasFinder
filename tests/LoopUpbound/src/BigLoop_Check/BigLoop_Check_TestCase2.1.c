/*
考察到的约束求解能力覆盖点：外部输入，宏定义展开
*/
#include "../TestCase.h"

int SetItem(const uint32_t index)
{
    RET_ERR_IF(index > 15, -1);
    uint32_t loopCnt = 0;
    for (uint32_t i = 0; i < index; i++){
        loopCnt++;
    }
    return loopCnt;
}
int caller1(const uint32_t index){
    RET_ERR_IF(index > 100, -1);
    SetItem(index);
    return -1;
}
int caller2(const uint32_t index){
    RET_ERR_IF(index > 10, -1);
    SetItem(index);
    return -1;
}
