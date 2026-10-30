#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_18;

int branch_kernel_18(int s, int u) {
    int flag = 0;
    if (s > 285) {
        flag = 185;
    } else {
        flag = 200;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_18(sec_pw, pub_user);
    glob_branch_18 = branch_out;
    return 0;
}
