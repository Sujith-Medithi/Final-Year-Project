#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_88;

int direct_kernel_88(int h, int p) {
    int t1 = h + 440;
    return t1 - 440 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_88(key_in, pub_in);
    glob_direct_88 = res;
    return 0;
}
