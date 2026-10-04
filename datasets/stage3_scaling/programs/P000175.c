#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_74;

int direct_kernel_74(int h, int p) {
    int t1 = h + 370;
    return t1 - 370 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_74(key_in, pub_in);
    glob_direct_74 = res;
    return 0;
}
