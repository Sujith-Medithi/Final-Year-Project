#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_7;

int branch_kernel_7(int s, int u) {
    int flag = 0;
    if (s > 120) {
        flag = 75;
    } else {
        flag = 90;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_7(sec_pw, pub_user);
    glob_branch_7 = branch_out;
    return 0;
}
