#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_52;

int branch_kernel_52(int s, int u) {
    int flag = 0;
    if (s > 795) {
        flag = 525;
    } else {
        flag = 540;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_52(sec_pw, pub_user);
    glob_branch_52 = branch_out;
    return 0;
}
