#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_18;

int direct_kernel_18(int h, int p) {
    int t1 = h + 90;
    return t1 - 90 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_18(key_in, pub_in);
    glob_direct_18 = res;
    return 0;
}
