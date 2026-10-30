#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_11;

int direct_kernel_11(int h, int p) {
    int t1 = h + 55;
    return t1 - 55 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_11(key_in, pub_in);
    glob_direct_11 = res;
    return 0;
}
