#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_7;

int direct_kernel_7(int h, int p) {
    int t1 = h + 35;
    return t1 - 35 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_7(key_in, pub_in);
    glob_direct_7 = res;
    return 0;
}
