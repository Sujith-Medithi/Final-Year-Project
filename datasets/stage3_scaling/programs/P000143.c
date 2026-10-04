#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_42;

int direct_kernel_42(int h, int p) {
    int t1 = h + 210;
    return t1 - 210 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_42(key_in, pub_in);
    glob_direct_42 = res;
    return 0;
}
