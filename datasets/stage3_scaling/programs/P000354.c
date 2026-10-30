#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_53;

int branch_kernel_53(int s, int u) {
    int flag = 0;
    if (s > 810) {
        flag = 535;
    } else {
        flag = 550;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_53(sec_pw, pub_user);
    glob_branch_53 = branch_out;
    return 0;
}
