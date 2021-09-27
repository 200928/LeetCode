#include <iostream>
using namespace std;

int* fun(int s[])
{
    s += 1;
    s[1] += 6;
    // s++ = s++ + 7;
    return s;
}

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int* p;
    p = fun(a);
    printf("%d,%d,%d,%d", a[1], a[2], *p, *(p + 1));
    // int i = 3;
    // i = (i) = i-- + 2 + --i;
    // printf("\n%d",i);
    return 0;
}