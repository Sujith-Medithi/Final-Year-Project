#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_14;

int direct_kernel_14(int h, int p) {
    int t1 = h + 70;
    return t1 - 70 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_14(key_in, pub_in);
    glob_direct_14 = res;
    return 0;
}
