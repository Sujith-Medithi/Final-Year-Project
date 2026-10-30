#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_86;

int branch_kernel_86(int s, int u) {
    int flag = 0;
    if (s > 1305) {
        flag = 865;
    } else {
        flag = 880;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_86(sec_pw, pub_user);
    glob_branch_86 = branch_out;
    return 0;
}
