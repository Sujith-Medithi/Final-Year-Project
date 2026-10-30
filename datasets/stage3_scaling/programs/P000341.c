#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_40;

int branch_kernel_40(int s, int u) {
    int flag = 0;
    if (s > 615) {
        flag = 405;
    } else {
        flag = 420;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_40(sec_pw, pub_user);
    glob_branch_40 = branch_out;
    return 0;
}
