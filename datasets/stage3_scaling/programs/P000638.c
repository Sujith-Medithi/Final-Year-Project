#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_37;

int nested_kernel_37(int sc, int fl) {
    int cat = 0;
    if (sc > 420) {
        cat = 3;
    } else {
        if (sc > 390) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 37;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_37(sec_score, pub_flag);
    glob_nest_37 = nest_out;
    return 0;
}
