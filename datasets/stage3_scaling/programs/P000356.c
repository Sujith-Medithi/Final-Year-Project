#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_55;

int branch_kernel_55(int s, int u) {
    int flag = 0;
    if (s > 840) {
        flag = 555;
    } else {
        flag = 570;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_55(sec_pw, pub_user);
    glob_branch_55 = branch_out;
    return 0;
}
