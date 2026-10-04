#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_87;

int branch_kernel_87(int s, int u) {
    int flag = 0;
    if (s > 1320) {
        flag = 875;
    } else {
        flag = 890;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_87(sec_pw, pub_user);
    glob_branch_87 = branch_out;
    return 0;
}
