#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_35;

int branch_kernel_35(int s, int u) {
    int flag = 0;
    if (s > 540) {
        flag = 355;
    } else {
        flag = 370;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_35(sec_pw, pub_user);
    glob_branch_35 = branch_out;
    return 0;
}
