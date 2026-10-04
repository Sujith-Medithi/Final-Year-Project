#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int status_arr_71[3] = {1 + 71, 2, 4 + 71}; int glob_mix_71;

int hybrid_kernel_71(int param, int cfg) {
    int state = cfg;
    for (int i = 0; i < 3; i++) {
        if ((param >> i) & 1) { state += status_arr_71[i]; }
        else { state -= 1; }
    }
    return state + 71;
}

int main()
{
    int sec_param;
    int pub_config;
    int mix_out;
    mix_out = hybrid_kernel_71(sec_param, pub_config);
    glob_mix_71 = mix_out;
    return 0;
}
