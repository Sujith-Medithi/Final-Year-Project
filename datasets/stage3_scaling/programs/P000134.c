#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_33;

int direct_kernel_33(int h, int p) {
    int t1 = h + 165;
    return t1 - 165 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_33(key_in, pub_in);
    glob_direct_33 = res;
    return 0;
}
