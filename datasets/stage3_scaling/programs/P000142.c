#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_41;

int direct_kernel_41(int h, int p) {
    int t1 = h + 205;
    return t1 - 205 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_41(key_in, pub_in);
    glob_direct_41 = res;
    return 0;
}
