#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_44;

int direct_kernel_44(int h, int p) {
    int t1 = h + 220;
    return t1 - 220 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_44(key_in, pub_in);
    glob_direct_44 = res;
    return 0;
}
