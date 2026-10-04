#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_nest_62;

int nested_kernel_62(int sc, int fl) {
    int cat = 0;
    if (sc > 670) {
        cat = 3;
    } else {
        if (sc > 640) { cat = 1; } else { cat = 0; }
    }
    return cat + fl + 62;
}

int main()
{
    int sec_score;
    int pub_flag;
    int nest_out;
    nest_out = nested_kernel_62(sec_score, pub_flag);
    glob_nest_62 = nest_out;
    return 0;
}
