#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_19;

int direct_kernel_19(int h, int p) {
    int t1 = h + 95;
    return t1 - 95 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_19(key_in, pub_in);
    glob_direct_19 = res;
    return 0;
}
