#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_51;

int nested_kernel_51(int sc, int fl) {
    int cat = 0;
    if (sc > 560) {
        cat = 3;
    } else {
        if (sc > 530) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 51;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_51(sec_score, pub_flag);
    glob_nest_51 = nest_out;
    return 0;
}
