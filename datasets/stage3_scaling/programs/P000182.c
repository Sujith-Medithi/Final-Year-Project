#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_81;

int direct_kernel_81(int h, int p) {
    int t1 = h + 405;
    return t1 - 405 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_81(key_in, pub_in);
    glob_direct_81 = res;
    return 0;
}
