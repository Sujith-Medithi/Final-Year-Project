#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_65;

int branch_kernel_65(int s, int u) {
    int flag = 0;
    if (s > 990) {
        flag = 655;
    } else {
        flag = 670;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_65(sec_pw, pub_user);
    glob_branch_65 = branch_out;
    return 0;
}
