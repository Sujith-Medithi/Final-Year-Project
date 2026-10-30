#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_15;

int direct_kernel_15(int h, int p) {
    int t1 = h + 75;
    return t1 - 75 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_15(key_in, pub_in);
    glob_direct_15 = res;
    return 0;
}
