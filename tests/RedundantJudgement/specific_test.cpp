// test for specific_target_config.toml
#include <stdio.h>
void foo_1(int i, int j, int k)
{
    int array_1[10];
    bool array_2[5][6];
    int array_3[10];
    if (i > 0) // foo_1 ifstmt
    {
        array_1[i] = 2; // foo_1 use point
        array_3[i] = 2; // foo_1 use point
    }
    if (j < 5) // foo_1 ifstmt
    {
        array_2[j][0] = true; // foo_1 use point
    }
    if (k) // foo_1 ifstmt
    {
    }
}
int foo_2(int i)
{
    int array_1[10];
    if (i > 0) // foo_2 ifstmt
    {
        array_1[i] = 2; // foo_2 use point
    }
    if (i == 0) // fool_2 ifstmt
    {
    }
    return 0;
}
int foo_3()
{
    int *p1;
    int a;
    if (p1 == NULL)
    {
        p1 = &a;
    }
    if (p1 != NULL)
    {
        int c = 10 / *p1;
    }
    return 0;
}
int main()
{
    int i, j, k;
    if (k) // main ifstmt
    {
    }
    if (i > 0 && j < 5) // main ifstmt
    {
        foo_1(i, j, k);
        foo_2(i);
    }
}