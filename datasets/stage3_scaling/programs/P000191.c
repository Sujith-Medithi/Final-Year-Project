#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_90;

int direct_kernel_90(int h, int p) {
    int t1 = h + 450;
    return t1 - 450 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_90(key_in, pub_in);
    glob_direct_90 = res;
    return 0;
}
