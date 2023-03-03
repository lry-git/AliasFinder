/*
考察到的约束求解能力覆盖点：外部输入，宏定义展开，多层循环，循环中的break
*/
#include "../TestCase.c"

int SetItem(const uint32_t index)
{
    RET_ERR_IF(index > 10, -1);
    uint32_t loopCnt = 0;
    for (uint32_t i = 0; i < index; i++){
        for (uint32_t j = i; j < index - 2; j++) {
            loopCnt++;
            if (j > 5) {
                break;
            }
        }
    }
    return loopCnt;
}
