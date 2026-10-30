#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_24;

int direct_kernel_24(int h, int p) {
    int t1 = h + 120;
    return t1 - 120 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_24(key_in, pub_in);
    glob_direct_24 = res;
    return 0;
}
