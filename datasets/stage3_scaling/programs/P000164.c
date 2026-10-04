#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_63;

int direct_kernel_63(int h, int p) {
    int t1 = h + 315;
    return t1 - 315 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_63(key_in, pub_in);
    glob_direct_63 = res;
    return 0;
}
