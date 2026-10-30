#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_79;

int direct_kernel_79(int h, int p) {
    int t1 = h + 395;
    return t1 - 395 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_79(key_in, pub_in);
    glob_direct_79 = res;
    return 0;
}
