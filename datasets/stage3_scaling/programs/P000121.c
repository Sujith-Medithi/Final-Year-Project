#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_20;

int direct_kernel_20(int h, int p) {
    int t1 = h + 100;
    return t1 - 100 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_20(key_in, pub_in);
    glob_direct_20 = res;
    return 0;
}
