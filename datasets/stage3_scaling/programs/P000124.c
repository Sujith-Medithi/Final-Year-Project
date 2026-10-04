#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_23;

int direct_kernel_23(int h, int p) {
    int t1 = h + 115;
    return t1 - 115 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_23(key_in, pub_in);
    glob_direct_23 = res;
    return 0;
}
