#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_22;

int direct_kernel_22(int h, int p) {
    int t1 = h + 110;
    return t1 - 110 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_22(key_in, pub_in);
    glob_direct_22 = res;
    return 0;
}
