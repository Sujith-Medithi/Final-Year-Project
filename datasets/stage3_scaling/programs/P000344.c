#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_43;

int branch_kernel_43(int s, int u) {
    int flag = 0;
    if (s > 660) {
        flag = 435;
    } else {
        flag = 450;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_43(sec_pw, pub_user);
    glob_branch_43 = branch_out;
    return 0;
}
