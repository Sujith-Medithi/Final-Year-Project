#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_65[3] = {1 + 65, 2, 4 + 65}; int glob_mix_65;

int hybrid_kernel_65(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_65[i]; }
        else { state -= 1; }
    }
    return state + 65;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_65(sec_param, pub_config);
    glob_mix_65 = mix_out;
    return 0;
}
