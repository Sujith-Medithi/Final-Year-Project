#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_35[4] = {10 + 140, 25 + 35, 42, 99}; int glob_arr_35;

int table_kernel_35(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_35[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int arr_out;
    arr_out = table_kernel_35(sec_idx, pub_base);
    glob_arr_35 = arr_out;
    return 0;
}
