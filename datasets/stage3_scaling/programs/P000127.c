#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_26;

int direct_kernel_26(int h, int p) {
    int t1 = h + 130;
    return t1 - 130 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_26(key_in, pub_in);
    glob_direct_26 = res;
    return 0;
}
