#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_2;

int nested_kernel_2(int sc, int fl) {
    int cat = 0;
    if (sc > 70) {
        cat = 3;
    } else {
        if (sc > 40) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 2;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_2(sec_score, pub_flag);
    glob_nest_2 = nest_out;
    return 0;
}
