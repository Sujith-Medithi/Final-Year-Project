#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_14;

int branch_kernel_14(int s, int u) {
    int flag = 0;
    if (s > 225) {
        flag = 145;
    } else {
        flag = 160;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_14(sec_pw, pub_user);
    glob_branch_14 = branch_out;
    return 0;
}
