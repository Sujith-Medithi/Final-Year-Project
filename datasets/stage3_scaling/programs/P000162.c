#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_61;

int direct_kernel_61(int h, int p) {
    int t1 = h + 305;
    return t1 - 305 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_61(key_in, pub_in);
    glob_direct_61 = res;
    return 0;
}
