#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_73;

int branch_kernel_73(int s, int u) {
    int flag = 0;
    if (s > 1110) {
        flag = 735;
    } else {
        flag = 750;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_73(sec_pw, pub_user);
    glob_branch_73 = branch_out;
    return 0;
}
