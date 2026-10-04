#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_92;

int nested_kernel_92(int sc, int fl) {
    int cat = 0;
    if (sc > 970) {
        cat = 3;
    } else {
        if (sc > 940) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 92;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_92(sec_score, pub_flag);
    glob_nest_92 = nest_out;
    return 0;
}
