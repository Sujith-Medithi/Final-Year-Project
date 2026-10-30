#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_39;

int direct_kernel_39(int h, int p) {
    int t1 = h + 195;
    return t1 - 195 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_39(key_in, pub_in);
    glob_direct_39 = res;
    return 0;
}
