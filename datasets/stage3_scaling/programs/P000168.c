#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_67;

int direct_kernel_67(int h, int p) {
    int t1 = h + 335;
    return t1 - 335 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_67(key_in, pub_in);
    glob_direct_67 = res;
    return 0;
}
