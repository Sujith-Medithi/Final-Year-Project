#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_59;

int direct_kernel_59(int h, int p) {
    int t1 = h + 295;
    return t1 - 295 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_59(key_in, pub_in);
    glob_direct_59 = res;
    return 0;
}
