#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_28;

int direct_kernel_28(int h, int p) {
    int t1 = h + 140;
    return t1 - 140 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_28(key_in, pub_in);
    glob_direct_28 = res;
    return 0;
}
