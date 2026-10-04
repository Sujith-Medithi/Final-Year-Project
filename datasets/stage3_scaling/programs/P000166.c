#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_65;

int direct_kernel_65(int h, int p) {
    int t1 = h + 325;
    return t1 - 325 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_65(key_in, pub_in);
    glob_direct_65 = res;
    return 0;
}
