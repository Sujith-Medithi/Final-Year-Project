#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_13;

int direct_kernel_13(int h, int p) {
    int t1 = h + 65;
    return t1 - 65 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_13(key_in, pub_in);
    glob_direct_13 = res;
    return 0;
}
