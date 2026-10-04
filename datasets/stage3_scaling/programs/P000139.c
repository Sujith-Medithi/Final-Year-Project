#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_38;

int direct_kernel_38(int h, int p) {
    int t1 = h + 190;
    return t1 - 190 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_38(key_in, pub_in);
    glob_direct_38 = res;
    return 0;
}
