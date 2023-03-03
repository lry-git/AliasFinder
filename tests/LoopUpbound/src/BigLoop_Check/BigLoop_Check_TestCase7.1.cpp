/*
考察到的约束求解能力覆盖点：宏定义，枚举值，跨过程
*/
#include <algorithm>
#include "../TestCase.c"
using namespace std;

int getmin(const int &a, const int &b){
    if(b<a) return b;
    return a;
}
int GetLoopCnt_()
{
    return getmin(ENUM_VALUE_4, MAX_ATTR_NUM);
}

int SetItem()
{
    uint32_t loopCnt = 0;
    for (uint32_t i = 0; i < GetLoopCnt_(); i++){
        loopCnt++;
    }
    return loopCnt;
}