#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_79[3] = {1 + 79, 2, 4 + 79}; int glob_mix_79;

int hybrid_kernel_79(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_79[i]; }
        else { state -= 1; }
    }
    return state + 79;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_79(sec_param, pub_config);
    glob_mix_79 = mix_out;
    return 0;
}
