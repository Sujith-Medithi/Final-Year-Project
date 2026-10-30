#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_13;

int branch_kernel_13(int s, int u) {
    int flag = 0;
    if (s > 210) {
        flag = 135;
    } else {
        flag = 150;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_13(sec_pw, pub_user);
    glob_branch_13 = branch_out;
    return 0;
}
