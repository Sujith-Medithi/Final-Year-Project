#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_29;

int direct_kernel_29(int h, int p) {
    int t1 = h + 145;
    return t1 - 145 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_29(key_in, pub_in);
    glob_direct_29 = res;
    return 0;
}
