#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_37;

int branch_kernel_37(int s, int u) {
    int flag = 0;
    if (s > 570) {
        flag = 375;
    } else {
        flag = 390;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_37(sec_pw, pub_user);
    glob_branch_37 = branch_out;
    return 0;
}
