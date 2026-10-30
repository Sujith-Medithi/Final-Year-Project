#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_44[3] = {1 + 44, 2, 4 + 44}; int glob_mix_44;

int hybrid_kernel_44(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 2; i++) {
        if ((param >> i) & 1) { state += status_arr_44[i]; }
        else { state -= 1; }
    }
    return state + 44;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_44(sec_param, pub_config);
    glob_mix_44 = mix_out;
    return 0;
}
