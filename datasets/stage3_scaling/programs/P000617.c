#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_16;

int nested_kernel_16(int sc, int fl) {
    int cat = 0;
    if (sc > 210) {
        cat = 3;
    } else {
        if (sc > 180) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 16;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_16(sec_score, pub_flag);
    glob_nest_16 = nest_out;
    return 0;
}
