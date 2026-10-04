#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_54;

int nested_kernel_54(int sc, int fl) {
    int cat = 0;
    if (sc > 590) {
        cat = 3;
    } else {
        if (sc > 560) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 54;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_54(sec_score, pub_flag);
    glob_nest_54 = nest_out;
    return 0;
}
