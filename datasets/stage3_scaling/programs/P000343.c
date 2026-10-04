#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_42;

int branch_kernel_42(int s, int u) {
    int flag = 0;
    if (s > 645) {
        flag = 425;
    } else {
        flag = 440;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_42(sec_pw, pub_user);
    glob_branch_42 = branch_out;
    return 0;
}
