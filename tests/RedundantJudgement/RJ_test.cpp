#include <stdio.h>
// #define RET_ERR_IF(expr, errcode) \
//     do                            \
//     {                             \
//         if ((expr))               \
//         {                         \
//             return (errcode);     \
//         }                         \
//     } while (0)
// #include <vector>
// using namespace std;

// void test_array(int i);
// void test_pointer(int *x);

// void func_A()
// {
//     int j = 1;
//     if (j > 0) // judgement for j
//     {
//         test_array(j);
//     }
//     int *q = &j;
//     if (*q > 0)
//     {
//         test_pointer(q);
//     }
// }

// void test_array(int i)
// {
//     int array[3][3];
//     int k = 2;
//     if (i > 0) // judgement for i
//     {
//         array[i][k] = i; // a redundant judgement for index i
//     }
// }

// void test_pointer(int *x)
// {
//     if (*x > 0)
//     {
//         *x += 1;
//     }
// }

void test_array_index()
{
    int array_int[5];
    int array_2[4][10][12];
    int i = 2, j = 3;
    int x = 1, y = 25;
    int a = 1, b = 2, c = 3;
    if (array_int[i] > 10)
    {
        array_int[i] += 12;
    }
    array_int[i]++;
    array_int[j - i] = 5;
    x = 15 + (y / array_int[i]);
    y = array_int[i + j - 1];
    array_int[array_int[i]] = 1; // multilayer
    array_2[1][2][3] = 5;        // multi dimensional
    x = array_int[1] + array_2[a][b][c];
    // int(*p)[5] = &array_int;
    // array_int;
}

// void test_intra()
// {
//     int array[10];
//     int i = 5;
//     if (i < 10) // ifstmt 1
//     {
//         if (i < 10)     // ifstmt 2
//             array[i]++; // use point
//     }
//     if (i < 10) // non ifstmt
//         i++;
// }

// void test_for(int i)
// {
//     int array[15];
//     for (; i > 0; i--)
//     {
//         array[i] = i - 1;
//     }
// }
// void test_while(int i)
// {
//     int array[15];
//     while (i > 0)
//     {
//         array[i] = i - 1;
//         i--;
//     }

// void test_complex_if(int i, int j)
// {
//     int array[3][3];
//     if (i > 0 && j > 0) // judgement for j
//     {
//         array[i][j] = i; // a redundant judgement for index j
//     }
// }

// void test_complex_cond(int i, int j)
// {
//     int k = 9;
//     int array[10];
//     if (0 < i && k < 2)
//     {
//         array[i] = k;
//     }
//     if (j < 0 && !j+1)
//     {
//         array[j] = k;
//     }
// }

int main()
{
    // int index = 1;
    // RET_ERR_IF(index > 0, -1);
    // test_array(index);
    // test_for(index);
    // test_while(index);
    // int x = 1;
    // test_complex_if(x, index);
    // int x = 1, y = 2;
    // if (x > 0 && y > 0)
    //     test_complex_cond(x, y);
}

// struct Msg
// {
//     int i;
// };
// void AllocRes(Msg *msg)
// {
//     if (msg == NULL)
//     {
//         msg = NULL;
//     }
// }
// void RecordRes(Msg *msg)
// {
//     if (msg == NULL)
//     {
//         msg = NULL;
//     }
// }
// void ProcMsg(Msg *msg)
// {
//     if (msg == NULL)
//     {
//         msg = NULL;
//     }
//     AllocRes(msg);
//     RecordRes(msg);
// }

//===-----------------------------------------===//
// test for redundant check without usepoint
//===-----------------------------------------===//
struct Msg
{
    int i;
};
void AllocRes(Msg *msg, bool flag)
{
    if (flag)
    {
        return;
    }
}
void RecordRes(Msg *msg, bool flag)
{
    if (flag)
    {
        return;
    }
}
void ProcMsg(Msg *msg, bool flag)
{
    if (flag)
    {
        return;
    }
    AllocRes(msg, flag);
    RecordRes(msg, flag);
}

void test_goto()
{
    int i = 0;
label:
    i++;
    if (i < 0)
        goto label;
}