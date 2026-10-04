#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_80;

int branch_kernel_80(int s, int u) {
    int flag = 0;
    if (s > 1215) {
        flag = 805;
    } else {
        flag = 820;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_80(sec_pw, pub_user);
    glob_branch_80 = branch_out;
    return 0;
}
