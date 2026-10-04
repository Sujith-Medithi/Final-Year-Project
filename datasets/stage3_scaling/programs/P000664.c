#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_63;

int nested_kernel_63(int sc, int fl) {
    int cat = 0;
    if (sc > 680) {
        cat = 3;
    } else {
        if (sc > 650) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 63;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_63(sec_score, pub_flag);
    glob_nest_63 = nest_out;
    return 0;
}
