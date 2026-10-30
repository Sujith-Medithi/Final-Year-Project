#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_95;

int direct_kernel_95(int h, int p) {
    int t1 = h + 475;
    return t1 - 475 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_95(key_in, pub_in);
    glob_direct_95 = res;
    return 0;
}
