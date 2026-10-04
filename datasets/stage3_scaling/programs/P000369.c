#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_68;

int branch_kernel_68(int s, int u) {
    int flag = 0;
    if (s > 1035) {
        flag = 685;
    } else {
        flag = 700;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_68(sec_pw, pub_user);
    glob_branch_68 = branch_out;
    return 0;
}
