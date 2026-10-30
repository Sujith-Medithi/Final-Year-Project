#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_12;

int branch_kernel_12(int s, int u) {
    int flag = 0;
    if (s > 195) {
        flag = 125;
    } else {
        flag = 140;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_12(sec_pw, pub_user);
    glob_branch_12 = branch_out;
    return 0;
}
