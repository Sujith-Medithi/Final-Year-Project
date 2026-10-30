#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_16;

int direct_kernel_16(int h, int p) {
    int t1 = h + 80;
    return t1 - 80 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_16(key_in, pub_in);
    glob_direct_16 = res;
    return 0;
}
