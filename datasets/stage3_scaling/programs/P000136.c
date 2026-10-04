#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_35;

int direct_kernel_35(int h, int p) {
    int t1 = h + 175;
    return t1 - 175 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_35(key_in, pub_in);
    glob_direct_35 = res;
    return 0;
}
