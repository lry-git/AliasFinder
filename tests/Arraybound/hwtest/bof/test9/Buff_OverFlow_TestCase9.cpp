/*
考察到的约束求解能力覆盖点：宏定义
*/
#include <vector>
#include "../TestCase.h"
using namespace std;

int SetGoodItem(vector<Cnt> &param)
{
    JUDGE(-1, param.size() >= BUF_LEN);
    param.resize(BUF_LEN);  // 做了访问上标保护,保证数组长度等于BUFLEN；
    uint32_t res = 0;
    for (uint32_t loop = 0; loop < BUF_LEN; loop++) { //
        res += param[loop].hasAttr;  // 数组下标访问点，不会越界
    }
    return res;
}

int SetBadItem(vector<Cnt> &param)
{
    JUDGE(-1, param.size() >= BUF_LEN);
    param.resize(BUF_LEN);  // 做了访问上标保护,保证数组长度等于BUFLEN；
    uint32_t res = 0;
    for (uint32_t loop = 0; loop < MAX_ATTR_NUM; loop++) { // POTENTIAL FLAW: 循环上界设置错误，可能发生缓冲区越界（用错宏）
        res += param[loop].hasAttr;  // 数组下标访问点，可能越界
    }
    return res;
}