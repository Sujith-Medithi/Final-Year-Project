#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_62;

int direct_kernel_62(int h, int p) {
    int t1 = h + 310;
    return t1 - 310 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_62(key_in, pub_in);
    glob_direct_62 = res;
    return 0;
}
