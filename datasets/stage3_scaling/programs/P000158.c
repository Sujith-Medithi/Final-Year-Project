#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_57;

int direct_kernel_57(int h, int p) {
    int t1 = h + 285;
    return t1 - 285 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_57(key_in, pub_in);
    glob_direct_57 = res;
    return 0;
}
