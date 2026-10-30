#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_direct_89;

int direct_kernel_89(int h, int p) {
    int t1 = h + 445;
    return t1 - 445 + p;
}

int main()
{
    int key_in;
    int pub_in;
    int res;
    res = direct_kernel_89(key_in, pub_in);
    glob_direct_89 = res;
    return 0;
}
