#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_96;

int direct_kernel_96(int h, int p) {
    int t1 = h + 480;
    return t1 - 480 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_96(key_in, pub_in);
    glob_direct_96 = res;
    return 0;
}
