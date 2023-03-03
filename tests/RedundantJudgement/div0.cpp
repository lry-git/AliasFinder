#include <stdio.h>
void foo(int i, int j)
{
    int k = 2;
    if (j == 0 && j != 0)
    {
    }
    if (i != 0 && j != 0)
    {
        k = k / i;
        k = k % j;
        // k /= i;
        // k %= j;
    }
    if (i == 0)
    {
    }
}

int main()
{
    int i = 1, j = 2;
    if (i / j == 0)
    {
    }
    // if(i>0)
    // {
    //     i++;
    // }
    if (i != 0 && j != 0)
    {
        foo(i, j);
    }
    return 0;
}
