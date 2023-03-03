/*
 * 考察到的约束求解能力覆盖点：入参不合理导致越界
 * */
#include "../TestCase.h"
constexpr int NUM = 100;

int GetItem(Student &stu, const uint32_t num)
{
    JUDGE(-1, num <= stu.bookNum);
    stu.bookNum -= num;

    int res = 0;
    uint32_t loopCnt = FOO_Min(num, BUF_LEN);
    for (uint32_t loop = 0; loop < loopCnt; loop++) {
        JUDGE(-1, stu.bookNum < NUM); // 数据保护宏使用错误，越界访问无效
        res += stu.books[stu.bookNum].pageNum; // 从实现上分析，如果可以保证stu.book = 数组长度len;
        stu.bookNum++;                         // 又因数组起始访问下标为len-num，迭代/累加次数少于num，因此不会出现数组越界。

    }
    return res;

}

int SetGoodItem(Student &stu, const uint32_t num){
    JUDGE(-1, stu.bookNum = ARRAY_SIZE(stu.books)) // 保证stu.book = stu.books[]的长度，入参合理，不报错；
        int res =  GetItem(stu, num);
    return res;

}

int SetBadItem(Student &stu, const uint32_t num){
    int res =  GetItem(stu, num); // 无法保证入参合理性，应该报错；
    return res;

}
