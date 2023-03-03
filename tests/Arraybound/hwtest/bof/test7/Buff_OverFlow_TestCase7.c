/*
考察到的约束求解能力覆盖点：上标保护的数据流分析
*/
#include <string.h>
#include "../TestCase.h"

int SetItem(const char inputStr[BUF_LEN])
{
    char tmpStr[BUF_LEN];
    tmpStr[BUF_LEN - 1] = '\0';
    uint32_t len = strlen(tmpStr);
    if (len < BUF_LEN) {
        for (uint32_t i = 0; i <= MAX_ATTR_NUM; i++) {
            if (i == BUF_LEN) {
                break;
            }
            if (len < 0) {
                tmpStr[i] = '0';  // 数组下标访问点，不会越界
            } else {
                tmpStr[i] = inputStr[i];  // 数组下标访问点，不会越界
                len--;
            }
        }
    }
    return 0;
}