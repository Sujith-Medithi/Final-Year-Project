#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_9[4] = {10, 25, 42, 99}; int glob_arr_9 = 0;

int table_kernel_9(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_9[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int lookup_val;
    lookup_val = table_kernel_9(sec_idx, pub_base);
    glob_arr_9 = lookup_val;
    return 0;
}
