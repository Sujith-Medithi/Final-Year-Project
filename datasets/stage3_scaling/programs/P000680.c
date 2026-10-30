#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_79;

int nested_kernel_79(int sc, int fl) {
    int cat = 0;
    if (sc > 840) {
        cat = 3;
    } else {
        if (sc > 810) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 79;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_79(sec_score, pub_flag);
    glob_nest_79 = nest_out;
    return 0;
}
