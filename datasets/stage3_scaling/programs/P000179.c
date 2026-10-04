#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_78;

int direct_kernel_78(int h, int p) {
    int t1 = h + 390;
    return t1 - 390 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_78(key_in, pub_in);
    glob_direct_78 = res;
    return 0;
}
