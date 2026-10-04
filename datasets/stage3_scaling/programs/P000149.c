#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_48;

int direct_kernel_48(int h, int p) {
    int t1 = h + 240;
    return t1 - 240 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_48(key_in, pub_in);
    glob_direct_48 = res;
    return 0;
}
