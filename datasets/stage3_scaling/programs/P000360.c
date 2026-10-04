#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_59;

int branch_kernel_59(int s, int u) {
    int flag = 0;
    if (s > 900) {
        flag = 595;
    } else {
        flag = 610;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_59(sec_pw, pub_user);
    glob_branch_59 = branch_out;
    return 0;
}
