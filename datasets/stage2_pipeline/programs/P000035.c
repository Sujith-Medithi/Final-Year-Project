#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_4;

int nested_kernel_4(int sc, int fl) {
    int cat = 0;
    if (sc > 90) {
        cat = 3;
    } else {
        if (sc > 60) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 4;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_4(sec_score, pub_flag);
    glob_nest_4 = nest_out;
    return 0;
}
