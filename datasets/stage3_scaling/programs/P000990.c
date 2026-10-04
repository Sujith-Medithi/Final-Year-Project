#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_89[3] = {1 + 89, 2, 4 + 89}; int glob_mix_89;

int hybrid_kernel_89(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_89[i]; }
        else { state -= 1; }
    }
    return state + 89;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_89(sec_param, pub_config);
    glob_mix_89 = mix_out;
    return 0;
}
