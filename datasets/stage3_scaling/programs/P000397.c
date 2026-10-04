#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_96;

int branch_kernel_96(int s, int u) {
    int flag = 0;
    if (s > 1455) {
        flag = 965;
    } else {
        flag = 980;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_96(sec_pw, pub_user);
    glob_branch_96 = branch_out;
    return 0;
}
