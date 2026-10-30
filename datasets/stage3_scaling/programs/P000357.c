#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_56;

int branch_kernel_56(int s, int u) {
    int flag = 0;
    if (s > 855) {
        flag = 565;
    } else {
        flag = 580;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_56(sec_pw, pub_user);
    glob_branch_56 = branch_out;
    return 0;
}
