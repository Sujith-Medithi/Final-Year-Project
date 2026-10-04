#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_84;

int direct_kernel_84(int h, int p) {
    int t1 = h + 420;
    return t1 - 420 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_84(key_in, pub_in);
    glob_direct_84 = res;
    return 0;
}
