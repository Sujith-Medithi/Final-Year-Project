#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_64;

int branch_kernel_64(int s, int u) {
    int flag = 0;
    if (s > 975) {
        flag = 645;
    } else {
        flag = 660;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_64(sec_pw, pub_user);
    glob_branch_64 = branch_out;
    return 0;
}
