#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_25;

int direct_kernel_25(int h, int p) {
    int t1 = h + 125;
    return t1 - 125 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_25(key_in, pub_in);
    glob_direct_25 = res;
    return 0;
}
