#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_77;

int branch_kernel_77(int s, int u) {
    int flag = 0;
    if (s > 1170) {
        flag = 775;
    } else {
        flag = 790;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_77(sec_pw, pub_user);
    glob_branch_77 = branch_out;
    return 0;
}
