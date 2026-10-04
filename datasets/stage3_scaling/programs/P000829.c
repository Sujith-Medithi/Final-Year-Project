#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_28[4] = {10 + 112, 25 + 28, 42, 99}; int glob_arr_28;

int table_kernel_28(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_28[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int arr_out;
    arr_out = table_kernel_28(sec_idx, pub_base);
    glob_arr_28 = arr_out;
    return 0;
}
