#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_2 = 0;

int direct_kernel_2(int h, int p) {
    int t = h + 10;
    return t - 10;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_2(key_in, pub_in);
    glob_direct_2 = res;
    return 0;
}
