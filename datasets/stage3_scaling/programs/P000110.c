#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_9;

int direct_kernel_9(int h, int p) {
    int t1 = h + 45;
    return t1 - 45 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_9(key_in, pub_in);
    glob_direct_9 = res;
    return 0;
}
