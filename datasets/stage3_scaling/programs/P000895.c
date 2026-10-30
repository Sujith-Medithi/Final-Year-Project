#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_94[4] = {10 + 376, 25 + 94, 42, 99}; int glob_arr_94;

int table_kernel_94(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_94[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int arr_out;
    arr_out = table_kernel_94(sec_idx, pub_base);
    glob_arr_94 = arr_out;
    return 0;
}
