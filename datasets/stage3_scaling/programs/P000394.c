#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_93;

int branch_kernel_93(int s, int u) {
    int flag = 0;
    if (s > 1410) {
        flag = 935;
    } else {
        flag = 950;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_93(sec_pw, pub_user);
    glob_branch_93 = branch_out;
    return 0;
}
