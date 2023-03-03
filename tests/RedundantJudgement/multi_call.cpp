#include <stdio.h>
void A(int a)
{
    int array[3];
    if (a > 0)
        array[a] = 1;
}
void B(int b)
{
    A(b);
}
void C(int c)
{
    if (c > 0)
        B(c);
}
void D(int d)
{
    C(d);
    if (d > 0)
        B(d);
}
void E(int e)
{
    if (e)
        C(e);
    D(e);
}