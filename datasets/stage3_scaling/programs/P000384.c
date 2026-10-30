#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int glob_branch_83;

int branch_kernel_83(int s, int u) {
    int flag = 0;
    if (s > 1260) {
        flag = 835;
    } else {
        flag = 850;
    }
    return flag + u;
}

int main()
{
    int sec_pw;
    int pub_user;
    int branch_out;
    branch_out = branch_kernel_83(sec_pw, pub_user);
    glob_branch_83 = branch_out;
    return 0;
}
