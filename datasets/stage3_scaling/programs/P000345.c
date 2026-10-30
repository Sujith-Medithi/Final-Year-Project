#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_44;

int branch_kernel_44(int s, int u) {
    int flag = 0;
    if (s > 675) {
        flag = 445;
    } else {
        flag = 460;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_44(sec_pw, pub_user);
    glob_branch_44 = branch_out;
    return 0;
}
