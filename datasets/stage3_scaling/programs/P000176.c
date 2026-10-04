#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_75;

int direct_kernel_75(int h, int p) {
    int t1 = h + 375;
    return t1 - 375 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_75(key_in, pub_in);
    glob_direct_75 = res;
    return 0;
}
