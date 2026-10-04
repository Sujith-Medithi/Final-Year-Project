#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_85;

int direct_kernel_85(int h, int p) {
    int t1 = h + 425;
    return t1 - 425 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_85(key_in, pub_in);
    glob_direct_85 = res;
    return 0;
}
