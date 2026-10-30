#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_58;

int nested_kernel_58(int sc, int fl) {
    int cat = 0;
    if (sc > 630) {
        cat = 3;
    } else {
        if (sc > 600) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 58;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_58(sec_score, pub_flag);
    glob_nest_58 = nest_out;
    return 0;
}
