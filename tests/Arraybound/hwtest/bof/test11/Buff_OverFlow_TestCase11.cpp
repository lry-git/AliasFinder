/*
 * 考察到的约束求解能力覆盖点：复杂结构体
 * */
#include "../TestCase.h"

int SetGoodItem(const ClassRoom *param)
{
    if (param == nullptr) {
        return -1;

    }
    uint32_t loopMax = FOO_Min(param->teacher.teacherId, MAX_ATTR_NUM); // 用宏约束数组长度小于40
    for (uint32_t i = 0; i < loopMax; i++) {
        if (param->teacher.students[i].bookNum != 0) { //结构体定义中students[MAX_ATTR_NUM]，不会越界
            return param->teacher.students[i].stuId; //结构体定义中students[MAX_ATTR_NUM]，不会越界
        }

    }
    return 0;

}

int SetBadItem(const ClassRoom *param)
{
    if (param == nullptr) {
        return -1;

    }
    uint32_t loopMax = FOO_Min(param->teacher.teacherId, MAX_ATTR_NUM); // 用宏约束数组长度小于40
    for (uint32_t i = 0; i < loopMax; i++) {
        if (param->teacher.students[i].bookNum != 0) { //结构体定义中students[MAX_ATTR_NUM]，不会越界
            return param->teacher.students[i].books[i].chapterPage[i];  // 访问chapterPage[BUF_LEN]存在越界风险
        }

    }
    return 0;

}
