#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_5;

int direct_kernel_5(int h, int p) {
    int t1 = h + 25;
    return t1 - 25 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_5(key_in, pub_in);
    glob_direct_5 = res;
    return 0;
}
