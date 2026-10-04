#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_22;

int nested_kernel_22(int sc, int fl) {
    int cat = 0;
    if (sc > 270) {
        cat = 3;
    } else {
        if (sc > 240) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 22;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_22(sec_score, pub_flag);
    glob_nest_22 = nest_out;
    return 0;
}
