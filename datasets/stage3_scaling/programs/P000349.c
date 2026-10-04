#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_48;

int branch_kernel_48(int s, int u) {
    int flag = 0;
    if (s > 735) {
        flag = 485;
    } else {
        flag = 500;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_48(sec_pw, pub_user);
    glob_branch_48 = branch_out;
    return 0;
}
