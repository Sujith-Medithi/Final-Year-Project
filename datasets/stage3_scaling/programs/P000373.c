#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_72;

int branch_kernel_72(int s, int u) {
    int flag = 0;
    if (s > 1095) {
        flag = 725;
    } else {
        flag = 740;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_72(sec_pw, pub_user);
    glob_branch_72 = branch_out;
    return 0;
}
