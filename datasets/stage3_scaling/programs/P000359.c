#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_58;

int branch_kernel_58(int s, int u) {
    int flag = 0;
    if (s > 885) {
        flag = 585;
    } else {
        flag = 600;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_58(sec_pw, pub_user);
    glob_branch_58 = branch_out;
    return 0;
}
