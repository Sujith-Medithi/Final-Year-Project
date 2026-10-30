#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_32;

int direct_kernel_32(int h, int p) {
    int t1 = h + 160;
    return t1 - 160 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_32(key_in, pub_in);
    glob_direct_32 = res;
    return 0;
}
