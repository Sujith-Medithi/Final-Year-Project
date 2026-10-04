#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_75[3] = {1 + 75, 2, 4 + 75}; int glob_mix_75;

int hybrid_kernel_75(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_75[i]; }
        else { state -= 1; }
    }
    return state + 75;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_75(sec_param, pub_config);
    glob_mix_75 = mix_out;
    return 0;
}
