#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_17;

int branch_kernel_17(int s, int u) {
    int flag = 0;
    if (s > 270) {
        flag = 175;
    } else {
        flag = 190;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_17(sec_pw, pub_user);
    glob_branch_17 = branch_out;
    return 0;
}
