#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_31[3] = {1 + 31, 2, 4 + 31}; int glob_mix_31;

int hybrid_kernel_31(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_31[i]; }
        else { state -= 1; }
    }
    return state + 31;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_31(sec_param, pub_config);
    glob_mix_31 = mix_out;
    return 0;
}
