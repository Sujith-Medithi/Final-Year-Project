#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_31;

int branch_kernel_31(int s, int u) {
    int flag = 0;
    if (s > 480) {
        flag = 315;
    } else {
        flag = 330;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_31(sec_pw, pub_user);
    glob_branch_31 = branch_out;
    return 0;
}
