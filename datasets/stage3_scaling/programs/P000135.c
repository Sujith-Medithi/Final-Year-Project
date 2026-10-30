#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_34;

int direct_kernel_34(int h, int p) {
    int t1 = h + 170;
    return t1 - 170 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_34(key_in, pub_in);
    glob_direct_34 = res;
    return 0;
}
