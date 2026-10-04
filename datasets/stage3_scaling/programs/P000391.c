#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_90;

int branch_kernel_90(int s, int u) {
    int flag = 0;
    if (s > 1365) {
        flag = 905;
    } else {
        flag = 920;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_90(sec_pw, pub_user);
    glob_branch_90 = branch_out;
    return 0;
}
