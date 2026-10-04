#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lookup_table_46[4] = {10 + 184, 25 + 46, 42, 99}; int glob_arr_46;

int table_kernel_46(int idx, int base) {
    int safe_idx = idx % 4;
    if (safe_idx < 0) safe_idx = -safe_idx;
    return lookup_table_46[safe_idx] + base;
}

int main()
{
    int sec_idx;
    int pub_base;
    int arr_out;
    arr_out = table_kernel_46(sec_idx, pub_base);
    glob_arr_46 = arr_out;
    return 0;
}
