#include <stdbool.h>
#include <string.h>
typedef unsigned int uint32_t;
typedef unsigned int UINT32;

#define FOO_Min(a, b) (((a) < (b)) ? (a) : (b))
#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))
#define MAX_ATTR_NUM 40
#define BUF_LEN 12
#define RET_ERR_IF(expr, errcode)              \
    do {                                                        \
        if ((expr)) {                                           \
            return(errcode);                                    \
        }                                                       \
    } while (0)

#define JUDGE(errcode, expr) \
{                        \
    if (!(expr)) {       \
        return(errcode);   \
    }                    \
}

typedef struct {
    uint32_t val;
    char buff[BUF_LEN];
} TestOverRun;


typedef struct {
    int val;
    bool hasAttr;
}Cnt;

typedef struct {
    char *name;
    unsigned int pageNum;
    unsigned int bookId;
    unsigned int chapterPage[BUF_LEN];

} Book;

typedef struct {
    char *name;
    bool gender;
    unsigned int stuId;
    unsigned int bookNum;
    char ID[BUF_LEN];
    Book books[MAX_ATTR_NUM];

} Student;

typedef struct {
    int teacherId;
    Student students[MAX_ATTR_NUM];

} Teacher;

typedef struct {
    unsigned int classId;
    Teacher teacher;

} ClassRoom;

#define RET_VOID_IF(expr)                                       \
    do {                                                        \
        if (expr) {                                           \
            return;                                             \
        }                                                       \
    } while (0)

#define RET_ERR(errorCode)                                       \
    do {                                                         \
        return errorCode;                                             \
    } while (0)

#define RET_ERR_VOID()                                    \
    do {                                                         \
        return;                                              \
    } while (0)

#define ARG2(_0, _1, _2, ...) _2
#define NARG2(...) ARG2(__VA_ARGS__, 2, 1, 0)

#define NARGS_1(a) RET_VOID_IF(a)
#define NARGS_2(a, b) RET_ERR_IF((a), (b))
#define NARGS_N(N, ...) NARGS_##N(__VA_ARGS__)
#define NARGS(N, ...) NARGS_N(N, __VA_ARGS__)

#define RET_IF(...) NARGS(NARG2(__VA_ARGS__), __VA_ARGS__)


