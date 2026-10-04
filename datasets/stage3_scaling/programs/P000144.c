#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_43;

int direct_kernel_43(int h, int p) {
    int t1 = h + 215;
    return t1 - 215 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_43(key_in, pub_in);
    glob_direct_43 = res;
    return 0;
}
