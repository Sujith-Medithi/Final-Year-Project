#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_15;

int branch_kernel_15(int s, int u) {
    int flag = 0;
    if (s > 240) {
        flag = 155;
    } else {
        flag = 170;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_15(sec_pw, pub_user);
    glob_branch_15 = branch_out;
    return 0;
}
