#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_10;

int branch_kernel_10(int s, int u) {
    int flag = 0;
    if (s > 165) {
        flag = 105;
    } else {
        flag = 120;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_10(sec_pw, pub_user);
    glob_branch_10 = branch_out;
    return 0;
}
