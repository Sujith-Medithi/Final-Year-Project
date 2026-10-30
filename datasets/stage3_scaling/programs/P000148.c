#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_47;

int direct_kernel_47(int h, int p) {
    int t1 = h + 235;
    return t1 - 235 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_47(key_in, pub_in);
    glob_direct_47 = res;
    return 0;
}
