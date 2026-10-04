#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_25;

int branch_kernel_25(int s, int u) {
    int flag = 0;
    if (s > 390) {
        flag = 255;
    } else {
        flag = 270;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_25(sec_pw, pub_user);
    glob_branch_25 = branch_out;
    return 0;
}
