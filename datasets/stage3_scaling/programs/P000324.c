#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_23;

int branch_kernel_23(int s, int u) {
    int flag = 0;
    if (s > 360) {
        flag = 235;
    } else {
        flag = 250;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_23(sec_pw, pub_user);
    glob_branch_23 = branch_out;
    return 0;
}
