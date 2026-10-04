#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_0;

int direct_kernel_0(int h, int p) {
    int t1 = h + 0;
    return t1 - 0 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_0(key_in, pub_in);
    glob_direct_0 = res;
    return 0;
}
